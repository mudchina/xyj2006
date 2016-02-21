// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "南天门");
  set ("long", @LONG

这里就是天宫的南门，只见金光万道，瑞气千条。你一时间觉
得有些不知所措，定了定神，才发现门是琉璃造就，宝玉妆成。
气派非凡。进了这一道门，就是天宫了。往门内望去，只见云
遮雾绕，一座座宫殿隐隐约约地看不大清晰。增长天王手持长
枪，正带着几个天兵天将在这里巡逻。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/zz-tianwang" : 1,
//  __DIR__"npc/tian-ding2" : 1,
//  __DIR__"npc/tian-ding1" : 1,
  __DIR__"npc/tian-bing" : 4,
]));
  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sw1",
  "north" : __DIR__"nanmenting",
  "east" : __DIR__"se1",
]));
create_door("north", "南天门", "south", DOOR_CLOSED);

  setup();
}
 
int valid_leave(object me, string dir)
{
 
        if (dir != "north") {
                return ::valid_leave(me,dir);
        }
 
 
        if (objectp(present("zengzhang tianwang", environment(me)))) {
 
                if (me->query("combat_exp")<100000) {
return notify_fail(HIY"增长天王对你说道：" + RANK_D->query_respect(me) +"似乎还未入仙道，回去多下点苦功吧。\n你满怀失望的离开了。\n"NOR);

                }
                else {
return notify_fail(HIY"增长天王对你拱手作了个揖：这位" + RANK_D->query_respect(me) +"，实在对不起。天庭正在准备蟠桃大会，暂不接待外客。\n看来得下次了。\n"NOR);
                }
        }
return ::valid_leave(me,dir);
}
