// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "南海之滨");
  set ("long", @LONG

南海之滨。往北是一条宽阔笔直的官道，足可容得下十马并驰。
往南则是一片汪洋大海，不知通向何方。西南海面上隐隐可见
一小岛。浅海近岸处还有几个游泳的人。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway5",
  "east" : __DIR__"seashore1",
"west" : "/d/jz/egate",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
    object me;
	me=this_player();
if (me->is_busy() || me->query_temp("pending"))
         return notify_fail("你现在正忙着呢。\n");
 	message_vision(HIY "$N纵身一跃，跳入海中。只见$N使足了全身力气，手足并用，不一会儿就游到了海中小岛上。\n" NOR, me);
        me->move("/d/nanhai/island");

        message_vision(HIY "只见$N浑身湿漉漉地从海里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}




