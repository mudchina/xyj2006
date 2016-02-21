#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW"厨房"NOR);
set ("long", @LONG
 
房间周围被炊烟熏的黑漆漆的，房间正中有一个铁锅。
  
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"shendian",
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
         object chuzi, ob, me;
        me=this_player();
        if( !arg)
                return notify_fail("你要放什么东西？\n");
 if( !arg || arg!="chu zi" || !(ob=present(arg, me)))
                return notify_fail("不要乱放。\n");
  message_vision("\n$N将$n放在祭台，一道金黄色的光闪后，祭台上隐隐出现了一个"+HIY" 金 "NOR+"字。\n\n", me, ob);
    me->set_temp("shendian/jinmigong","begin");
    me->move("/d/shendian/jin/jinmigong0");
                destruct(ob);
        return 1;
}
