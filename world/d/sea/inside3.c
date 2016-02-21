//modified by bear

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
void create ()
{
  set ("short", "龙宫正殿");
  set ("long", @LONG

正殿之上悬一明珠，把诺大一殿照得通亮。两旁桌椅玉石打造而成，　　
当中还嵌着无数珠宝。两边墙上挂了两幅画，看起来相当的陈旧。　　　
南北是两座偏殿。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"inside2.c",
  "east" : __DIR__"inside4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/longwang" : 1,
]));
//      
        set("water", 1);
//  
  setup();
}

void init()
{
   object where=this_object();

    remove_call_out("check_time");
   check_time(where);
   add_action("do_hear","hear");
}
void check_time(object where)
{

   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   if(phase==0&&(!query("jiangjing"))) jiang_jing(where);
if(phase==7&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:es",CYN+"◇"YEL"东海龙宫"CYN"◇"YEL"敖广[ao guang]"YEL"：现在开始传授我们龙宫避水之术。\n"+NOR,users());
tell_object(where,"四海龙王乃玉帝遣于凡间，专管降雨。\n");
tell_object(where,"四海龙王之下又有众多河龙王，井龙王，及各种水族。\n");
tell_object(where,"我传的武功法术在水中占了极大的优势。\n");

   tell_object(where,"本龙宫的宝物对本门弟子的成长也是大有好处。\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
tell_object(where,"龙王敖广说道：回去试试你的避水之术修炼的如何了。\n");
   set("jiangjing",0);
     set ("long", @LONG
     龙宫弟子们都在听龙王敖广说些什么。
LONG);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
return notify_fail("龙王敖广还没开始传授避水之术呢。\n");

 if((string)me->query("family/family_name")!="东海龙宫")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("东海龙宫避水之术你已经听的差不多了。\n");

    tell_object(me,"你在旁边听着，听着。不禁对本门的避水之术有所领悟。\n");
   me->start_busy(5);
   me->improve_skill("dragonforce",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("seashentong",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}



int valid_leave()
{
    if(
       (present("dao kan dao", this_player()))
       || (present("jiu gu cha", this_player()))
       || (present("mei hua chui", this_player()))
       || (present("hua gan ji", this_player()))
      )
        return notify_fail("龙宫至宝不能随便带走！\n");
    return ::valid_leave();
}

