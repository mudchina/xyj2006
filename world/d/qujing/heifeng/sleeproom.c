//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG

这里静悄悄的，中间放着一个坐垫，用来坐禅。

LONG);

  set("exits", ([
        "south": __DIR__"dadian",
      ]));
  setup();

}
void init()
{
  add_action("do_xiuxi", "xiuxi");
}
int do_xiuxi(string arg)
{
  object me=this_player();
if( me->query("obstacle/yj") !="done")
   return notify_fail("什么？\n");
if( me->query_temp("jiasha_given"))
{
message_vision(HIR"你刚躺下准备休息，\n"NOR,me);
message_vision(HIR"突然忽然一阵火起，\n"NOR,me);
message_vision(HIR"你马上起身去看出了什么事。\n"NOR,me);
me->set_temp("fired",1);
}
return 1;
} 
