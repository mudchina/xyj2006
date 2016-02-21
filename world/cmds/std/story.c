// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit F_SAVE;

int main(object me, string arg)
{
   object document, content, cont_num;
   int i, j, option, month, number, year, nummonth, argn;
   string dirname="/data/doc/", deloption, srcstr, dststr, file;
   string *mon= ({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});

   if (! arg) {
     dirname=dirname+ctime(time())[20..23] + "/";
     option=1;
     }
   else argn=sscanf(arg, "%d %d %d %s", month, number, year, deloption);

   if ( argn >3)
     if (deloption=="-delete")
        {
        if ( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
         && (string)SECURITY_D->get_status(this_player(1)) !="(arch)" )
          return notify_fail("你不能删除文档！\n");
        else argn=3;
        }
     else 
        return notify_fail("指令格式：story [<month> [<number>]] [<year>]\n");
   
   if (argn==3) { 
     option=3;
     dirname=dirname+sprintf("%d",year)+"/";
     }
   if (argn==2) 
     if (number <1996) {
        dirname=dirname+ctime(time())[20..23] + "/";
        option=3;
        }
     else {
                   dirname=dirname+sprintf("%d",number)+"/";
                   option=2;
                    }
   if (argn==1)
     if (month<1996) {
        dirname=dirname+ctime(time())[20..23] + "/";
        option=2;
        }
     else {
        dirname=dirname+sprintf("%d",month)+"/";
        option=1;
        }

   seteuid(getuid());
   cont_num=new("/obj/not.c");
   cont_num->set("file_name", dirname+"month.number");
   cont_num->restore();
   if (!objectp(cont_num) )
     return notify_fail("文档读取失败！\n"); 

   if (option==1) {
     file="";
     for (i=1;i<=12;i++) 
     if (cont_num->query(mon[i-1])) {
        file+=chinese_number(i)+"月：总共"
+chinese_number(cont_num->query(mon[i-1]))
+"篇文档：\n--------------------------------------------------------------------------------\n";
        content=new("/obj/not.c");
        content->set("file_name", dirname+"content."+mon[i-1]);
        content->restore();
        if ( !objectp(content) )
          return notify_fail("文档读取失败！\n");
        file+=content->query("msg")+"\n";
        }
     me->start_more(file);
     return 1;
     }

   if (month<=0 || month >=13) return notify_fail("要读的文档不存在！\n"); 
   nummonth=cont_num->query(mon[month-1]);

   if( option==2 ) {
     if (!nummonth) return notify_fail("该月无文档。\n");
     content=new("/obj/not.c");
     content->set("file_name", dirname+"content."+mon[month-1]);
     content->restore();
     if ( !objectp(content) )
        return notify_fail("文档读取失败！\n");
     write("总共"+chinese_number(nummonth)+"篇文档：\n--------------------------------------------------------------------------------\n");
     me->start_more(content->query("msg"));
     return 1;
     }

   if (!nummonth || nummonth < number)
     return notify_fail("要读的文档不存在！\n"); 
   document=new("/obj/not.c");
   document->set("file_name", dirname+ sprintf("%s/doc%d.%d",mon[month-1],month,number) );
   document->restore();
   if ( !objectp(document) )
     return notify_fail("文档读取失败！");

   if (deloption=="-delete") {
     cont_num->set(mon[month-1], nummonth-1);
     cont_num->save();
     content=new("/obj/not.c");
     content->set("file_name", dirname+"content."+mon[month-1]);
     content->restore();
     if ( !objectp(content) )
        return notify_fail("文档读取失败！\n");
     dststr=""; srcstr=content->query("msg");
     for (i=1;i<=nummonth;i++) {
        sscanf(srcstr, "[%d]%s\n%s", j, file, srcstr);
        if (i >number) file=sprintf("[%3d]", i-1)+file+"\n";
        else file=sprintf("[%3d]", i)+file+"\n";
        if (i!=number) dststr+=file; 
        }
     content->set("msg", dststr);
     content->save();
     if (nummonth==number) 
        rm(dirname+sprintf("%s/doc%d.%d.o",mon[month-1],month,number));
     else
     for (i=number+1;i<=nummonth;i++) {
        document=new("/obj/not.c");
        document->set("file_name", dirname+sprintf("%s/doc%d.%d",mon[month-1],month,i));
        document->restore();
        srcstr=document->query("msg");
        sscanf(srcstr, "[%d]%s\n%s", j, file, srcstr);
        dststr=sprintf("[%3d]", i-1)+file+"\n"+srcstr;
        document->set("file_name", dirname+sprintf("%s/doc%d.%d",mon[month-1],month,i-1));  
        document->set("msg", dststr);
        document->save();
        }
     write("文档删除成功！\n");
     return 1;
     }
   me->start_more(document->query("msg"));
   return 1;
}

int help (object me)
{
        write(@HELP
指令格式：story <month> [<number> [<year>]]

这个指令让你在线阅读保存的文档，或者列出所能读取的文档目录。


Example: 阅读某年的目录：
story
story 1997

Example: 阅读某月的目录：
story 5
story 5 1997

Example: 阅读某篇文档：
story 5 1
story 5 1 1997
 
HELP
);
        return 1;
}

