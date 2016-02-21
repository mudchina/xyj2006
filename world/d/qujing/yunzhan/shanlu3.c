//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/shanlu3.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "山林");
  set ("long", @LONG

走在林中，时常能听到丛林之上野鹤发出的尖唳之声，成精的狐狸
和野狼从你面前穿来穿去，真是让人心惊肉跳，你的脚下有一丛灌
木(bush)在风的吹动下起浮不定。
LONG);

  set("exits", ([
        "westdown"   :"/d/qujing/huangfeng/road1",
        "eastdown"  : __DIR__"shanlu2",
      ]));
  set("outdoors","yz");
  setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object ob = this_player();
        object wield;

        if(!wield=ob->query_temp("weapon"))
                return notify_fail("你手中没有利器。\n");

        if( ! arg || arg != "bush" )
                return notify_fail("你要砍什么？\n");

        if(((string)wield->query("skill_type")!="sword"
             && ((string)wield->query("skill_type")!="blade")))
                return notify_fail("你应该找把剑，或是刀什么的。\n");

        message_vision(HIR"$N对着灌木丛猛砍了一阵，随着灌木的倒下，居然发现了一个洞口。\n"NOR,ob);
                set("exits/down", __DIR__"in1");
                remove_call_out("close");
                call_out("close", 5, this_object());
                return 1;
}
void close(object room)
{
        message("vision","风一吹，又有一些灌木移了过来，刚好堵住了洞口。\n", room);
        room->delete("exits/down");
}
