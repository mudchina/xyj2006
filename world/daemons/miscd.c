// miscd.c
// by mon@xyj 10/19/98

#pragma optimize

#include <ansi.h>

inherit F_DBASE;

mapping maps=([]);

void create()
{
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   seteuid(getuid());
   set("name", "监控精灵");
   set("id", "miscd");

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}

int random_capture(object me,int chance,int silent)
{
        if(!me) return 0;
        if(!chance) chance=5000;
//	if(wizardp(me)) chance=1;

        if(random(chance)==0) {
	    if(silent)
                tell_object(me,"\n忽然一阵黄风呼啸而来，你身不由己"+
                    "被卷了进去！\n");
	    else
                message_vision("\n忽然一阵黄风呼啸而来，$N身不由己"+
                    "被卷了进去！\n",me);
            tell_object(me,"\n不知过了多久．．．\n\n");
            me->set_temp("old_place",environment(me));
            me->move("/d/qujing/baihuling/jail",1);
            message_vision("$N被嘭地一声摔在地上！\n",me);
            return 1;
        }
	return 0;
}


string find_place(object where)
{
	string fail, msg, filename, filename1, answer;
	int len;

	fail=""; // default fail message

        filename=file_name(where);
	len=strlen(filename);
	if(len<2) return fail;

        len--;
        while(filename[len]!='/' && len>0) {
	  len--;
	}
	if(len<2) return fail;

	filename1=filename[1..(len-1)];

        if(sscanf(filename,"/d/changan/bed#%*s")==1) {
	//this need check first.
	  answer="床上";
        } else if(!undefinedp(maps[filename1])) {
	  answer=maps[filename1];
	} else if(where->is_character()) {
	  answer=where->query("name")+"身上";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="住家里";
        } else { 
          answer=undefinedp(where->query("short"))?
		  where->short():
		  where->query("short");
        }

	return answer;
}
