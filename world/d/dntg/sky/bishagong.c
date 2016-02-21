#include <ansi.h>
#include <room.h>
#include <laojunluhelp.h>

inherit ROOM;

int leave_here(string arg,object who);

string *files = ({
  "/d/dntg/laojunlu/npc/moli-qing",
  "/d/dntg/laojunlu/npc/moli-hong",
  "/d/dntg/laojunlu/npc/moli-hai",
  "/d/dntg/laojunlu/npc/moli-shou",
});


void create()
{
set("short", "毗沙宫");
set("long", @LONG

毗沙宫中站立着几个庄严的武士，扫视着没一个来往的人。
LONG );

set("exits", ([
  "south"   : __DIR__"tongmingdian",
  "north"   : __DIR__"tonglugong",
]));


set("objects", ([
    __DIR__"npc/yishengzhenjun" : 1,
]));

setup();
}


void init()
  {
   object who=this_player();
   object where=this_object();
   object zhenjun,defender;
   int i;



   add_action("do_quit", "quit");
   add_action("do_ji", "ji");
   add_action ("do_cast","cast");

   if (who->query("dntg/laojunlu")=="allow1")
     {
     tell_room(environment(who),who->name()+"怒冲冲闯了过来。\n",who); 

     if (who->query("dntg/bishagong")!="yes") //死过再来
        {
      if (! present ("yisheng zhenjun",where))
       {
       
       zhenjun=new (__DIR__"npc/yishengzhenjun");
       zhenjun->move("/d/dntg/sky/bishagong");
       tell_room(environment(who),zhenjun->name()+"匆匆赶来。\n",who); 
       }
      zhenjun=( present ("yisheng zhenjun", where));
       zhenjun->command("chat "+who->query("name")
          +"这"+RANK_D->query_rude(who)+"打到毗沙宫了！四大天王快来救驾！");
       message_vision("只见四大天王蜂拥而来，将$N围在当中！\n",who);
       for (i=0;i<4;i++)
         {
         defender=new (files[i]);
         defender->move("/d/dntg/sky/bishagong");

         defender->kill_ob(who);
         }
         where->set("fight_here","yes");
         who->set("dntg/bishagong","yes"); 
        zhenjun->kill_ob(who);
       leave_here("翊圣真君",who);      
     }
   }
    else if(where->query("fight_here") == "yes")
          you_leave("翊圣真君",who);
 
}

int valid_leave(object me, string dir)
{
   object where=this_object();

   if (me->query("dntg/laojunlu") != "allow1")
      return ::valid_leave(me, dir);
   else if (present ("yisheng zhenjun",where) || present ("tian wang",where))
      return notify_fail("这么多人围着你，怎么进去！\n");
   else if (dir != "north")
      return notify_fail("已经闹到这步田地，不如一不作，二不修，打进灵霄宝殿！\n");
   else 
     {
     me->set("dntg/laojunlu","finish");
     where->set("fight_here","no");
     return ::valid_leave(me, dir);
     }
}

int do_cast (string arg)
{
  object who = this_player();
  string cast_id,cast_name;

  if (who->query("dntg/laojunlu")=="allow1" 
         && (arg=="escape" || arg=="shuidun" || arg=="tudun" || arg=="chuqiao"))
     {
      tell_object(who,"哪里跑！\n");
      return 1;
     }
  else if (who->query("dntg/laojunlu")=="allow1" 
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
int do_ji(string arg)
{
tell_object(this_player(), "到了这离还敢用仙家宝贝？\n");
  return 1;
}
