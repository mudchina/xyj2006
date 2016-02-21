//beitian.c
//created 4-8-97, pickle

#include <room.h>
#include <ansi.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "北天门");
  set ("long", @LONG

    这里是天宫的北门。玉皇大帝的宝座是坐北朝南的，所以除了有
特殊圣旨或玉帝的亲信之外，没人敢从这里出入。比起南天门来，北
边可就冷清多了。虽然如此，北天门造的可丝毫不含糊。鲜红的大门
上镶着闪闪发光的铜钉，显得威武非凡。护国天王领着大力天丁和众
天兵，一丝不苟的巡逻着。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("objects", ([ /* sizeof() == 4 */
//  __DIR__"npc/tian-ding2" : 1,
//  __DIR__"npc/tian-ding1" : 1,
  __DIR__"npc/hg-tianwang" : 1,
  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nw1",
  "south" : __DIR__"beimenting",
  "north" : __DIR__"yun",
  "east" : __DIR__"ne1",
]));
create_door("south", "北天门", "north", DOOR_CLOSED);

  setup();
}

int valid_leave(object me, string dir)
{
 
        if (dir == "north") {
        	message_vision ("$N纵身跳入云海中！\n",me);
        	return ::valid_leave(me,dir);
        }
        if (dir != "south") {
                return ::valid_leave(me,dir);
        }
 
 
if (objectp(present("huguo tianwang", environment(me)))) {
 
if (me->query("combat_exp")>100000) 
return notify_fail(HIY"护国天王对你拱手作了个揖：这位" + RANK_D->query_respect(me) +"，实在对不起。若想进去还是从南门走吧。\n看来这里不能进。\n"NOR);
else
return notify_fail(HIY"护国天王厉声说道：此乃天宫重地，闲杂人等不得入内！\n你满怀失望的离开了。\n"NOR);
        }
return ::valid_leave(me,dir);
}

