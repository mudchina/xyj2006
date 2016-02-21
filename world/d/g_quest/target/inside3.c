// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// inside3.c
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_serve();
inherit ROOM;

void create ()
{
  set ("short", "龙宫正殿");
  set ("long", @LONG

正殿之上悬一明珠，把诺大一殿照得通亮。两旁桌椅玉石打造而成，　　
当中还嵌着无数珠宝。两边墙上挂了两幅画，看起来相当的陈旧。　　　
南北是两座偏殿。如果龙王累了，你还可以给他服务一下。(serve)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"inside2.c",
  "east" : __DIR__"inside4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/longwang" : 1,
]));
  set("water", 1);
  setup();

}

void init()
{
   object where=this_object();

  remove_call_out("check_time");
   check_time(where);
   add_action("do_serve","serve");
}

void check_time(object where)
{
   mixed *local = localtime(time()*60);
   int t = local[2] * 60 + local[1];
  int phase=((int)(t/120));
if((phase==1)&&(!query("hungry"))) feel_hungry(where);
if((phase==2)&&query("hungry")) feel_full(where);
   call_out("check_time",60,where);
}

void feel_hungry(object where)
{
message("channel:es",HIG+"【东海龙宫】敖广(Ao guang)：朕累了，有人来服务吗？\n"+NOR,users());
   set("hungry",1);
}
void feel_full(object where)
{
tell_object(where,"东海龙王笑道：很好，很好。\n");
  set("hungry",0);
}
int do_serve()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("hungry"))
      return notify_fail("东海龙王道：我现在不累！\n");
   if((string)me->query("family/family_name")!="东海龙宫")
      return notify_fail("东海龙王道：不敢劳您大驾！\n");
   if(me->query("faith")>5000||me->query("combat_exp")>10000000)
      return notify_fail("您是我们龙宫有身份的人，这样的事就让小辈们做吧。\n");
   tell_object(me,"你运起碧海神通，海水不断在龙王周身回旋按摩！\n");
   me->start_busy(5);
      me->add("faith",1);
	  me->improve_skill("seashentong",random((int)(me->query("spi")+me->query("int"))/2),1);
   me->add("combat_exp",9);
   me->add("potential",3);
   me->receive_damage("kee",40);
   me->receive_damage("sen",40);
   tell_object(me,"你觉得碧海神通进步了！\n");
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
