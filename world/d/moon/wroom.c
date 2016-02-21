//Cracked by Roath
// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG

懒懒的阳光透过窗棂，有意无意地洒落满室，再有红蕊细枝点缀几处，整
间厢房便似沐浴在晌午的光霭花气中，处处浮溢着一种恬静的感觉。屋角
有一张小床，两边墙上各有一排铜钉，在阳光下泛着柔和的金色。
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "睡觉用的床铺(gosleep,gobed,bed)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaoyuan",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"bed_moon");
            message_vision(HIY "\n纱帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

