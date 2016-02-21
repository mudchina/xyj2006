#include <ansi.h>
#include <room.h>
#include </d/dntg/sky/laojunluhelp.h>

inherit ROOM;

int leave_here(string arg,object who);


void create()
{
set("short", "通明殿");
set("long", @LONG
    
入宫的大道继续向前延伸，走不多远就是灵霄宝殿了。
在这里隐隐可以看见宝殿雄伟的殿门，和传说中神采
飞扬的天神们。
LONG );



set("exits", ([
  "north"   : __DIR__"bishagong",
  "south"   : __DIR__"caihongqiao2",
  "west"   : __DIR__"baoguangdian",
  "east"   : __DIR__"lingxudian",
]));

set("objects", 
([
    __DIR__"npc/youshengzhenjun" : 1,
]));

setup();
}


void init()
  {
   object who=this_player();
   object where=this_object();
   object zhenjun,lingguan;
   int i;



   add_action("do_quit", "quit");
   add_action ("do_cast","cast");

   if (who->query("dntg/laojunlu")=="allow")
     {
     tell_room(environment(who),"只见"+who->name()+"从天而降。\n",who); 

     if(who->query("dntg/tongmingdian")!="yes") {
     if (! present ("yousheng zhenjun",where))
       {
       zhenjun=new (__DIR__"npc/youshengzhenjun");
       zhenjun->move(where);
       tell_room(environment(who),zhenjun->name()+"匆匆赶来。\n",who); 
       }
       zhenjun=( present ("yousheng zhenjun", where));
       zhenjun->command("chat "+who->query("name")
          +"这"+RANK_D->query_rude(who)+"打到通明殿了！");
       message_vision("$N一招手，唤来几名灵官，将$n围在当中！\n",zhenjun,who);
       for (i=0;i<4;i++)
         {
         lingguan=new (__DIR__"npc/lingguan");
         lingguan->move(where);
         lingguan->kill_ob(who);
         }
       where->set("fight_here","yes");
       zhenjun->kill_ob(who);
       who->set("dntg/tongmingdian","yes");     
       leave_here("佑圣真君",who);      
     }
  }
   else if(where->query("fight_here") == "yes") you_leave("佑圣真君",who);
  }


int valid_leave(object me, string dir)
{
   object where=this_object();

   if (me->query("dntg/laojunlu") != "allow")
      return ::valid_leave(me, dir);
   else if (present ("yousheng zhenjun",where) || present ("ling guan",where))
      return notify_fail("这么多人围着你，怎么走？\n");
   else if (dir != "north")
      return notify_fail("已经闹到这步田地，不如一不作，二不修，打进灵霄宝殿！\n");
   else 
     {
     me->set("dntg/laojunlu","allow1");
     where->set("fight_here","no");
     return ::valid_leave(me, dir);

     }
}

int do_cast (string arg)
{
  object who = this_player();
  string cast_id,cast_name;

  if (who->query("dntg/laojunlu")=="allow" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun" || arg=="chuqiao"))
     {
      tell_object(who,"哪里跑！\n");
      return 1;
     }
  else if (who->query("dntg/laojunlu")=="allow" 
        && ((sscanf(arg, "%s on %s", cast_id,cast_name) == 2 
                && cast_id=="qiankun") || arg=="qiankun"))
     {
      tell_object(who,"你隐隐的听到镇元大仙的声音：你这逆徒！"
      
          +"闹到今日这步田地，休要用我观中法术，以免牵带我全观弟子！\n");
      return 1;
     }
  else return 0;

}

int do_quit(string arg)
{
    tell_object(this_player(), "这里不能离开游戏。\n");
    return 1;
}

