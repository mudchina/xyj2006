#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"农田"NOR);
set ("long", @LONG
 
房间的墙壁上面画满了富饶了农田，房间中间只有一个祭台。
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shendian",
]));
  set("objects", ([ /* sizeof() == 1 */
  ]));
  set("no_clean_up", 1);
  setup();
}
void init()
{
        add_action("do_put", "put");
        set("no_clean_up", 1);
}
int do_put(string arg)
{
         object famugong, ob, me;
        me=this_player();
        if( !arg)
                return notify_fail("你要放什么东西？\n");
 if( !arg || arg!="nong fu" || !(ob=present(arg, me)))
                return notify_fail("不要乱放。\n");
   message_vision("\n$N将$n放在祭台，一道黄光过后，祭台上隐隐出现了一个"+HIY" 土 "NOR+"字。\n\n", me, ob);
    me->set_temp("shendian/tumigong","begin");
    me->move("/d/shendian/tu/tumigong0");
                destruct(ob);
        return 1;
}
