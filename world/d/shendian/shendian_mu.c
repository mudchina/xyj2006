#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"森林"NOR);
set ("long", @LONG
 
房间的墙壁上面画满了森林，房间中间只有一个祭台。
 
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shendian",
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
 if( !arg || arg!="famu gong" || !(ob=present(arg, me)))
                return notify_fail("不要乱放。\n");
 message_vision("\n$N将$n放在祭台，一道绿光过后，祭台上隐隐出现了一个"+YEL" 木 "NOR+"字。\n\n", me, ob);
    me->set_temp("shendian/mumigong","begin");
   me->move("/d/shendian/mu/mumigong0");
                destruct(ob);
        return 1;
}
