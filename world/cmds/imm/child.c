// child.c
// written by mon 4/5/98

inherit F_CLEAN_UP;

int main(object me, string str)
{
     object where, *list;
     int i, number;

     if (!str) str = me->query("cwf");
     if(!str) return notify_fail("你要查看哪个文件？\n");
 
     str = resolve_path(me->query("cwd"), str);
        if( sscanf(str, "%*s.c") != 1 ) str += ".c";
        me->set("cwf", str);
   
     if( file_size(str) < 0 )
                return notify_fail("没有这个文件：" + str + ")\n");

     list=children(str);
     number=sizeof(list);
     if(number) {
       for(i=0;i<sizeof(list);i++) {
         write((int)(i+1)+". "+file_name(list[i])+" "+
           list[i]->query("name")+"("+
           list[i]->query("id")+") is at ");
         where=environment(list[i]);
         if(where) {
           if(where->query("short")) {
             write(where->query("short"));
           } else {
             write(where->short());
           }
           write("("+file_name(where)+")\n");
         } else {
           write("???\n");
         }
       }
     }

     return 1;
}

int help(object me)
{
write(@HELP
指令格式 : child filename

List information about all copies (master and cloned)
of a given file in the mud.

HELP
    );
    return 1;
}
