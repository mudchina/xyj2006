//Cracked by Roath
// Room: /d/nanhai/fanting
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

这里是通往斋房的走廊，普陀山门人弟子们用斋前往往在此
小憩片刻，有人乘机寻得一些药品灵丹来疗伤养精。
LONG);
/*
角落上
似乎有一扇小门通往里屋。
*/
//  set("item_desc", ([ /* sizeof() == 1 */
//  "south" : (: look_door,     "south" :),
//]));
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaoyuan",
  "south" : __DIR__"restroom",
  "east" : __DIR__"zhaifang",
//  "north": __DIR__"restroom",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangchu" : 1,
]));
//create_door("south", "小门", "north", DOOR_CLOSED);

  setup();
}
int valid_leave(object me, string dir)
{
if (me->query("family/family_name") != "南海普陀山" && dir == "east")
if(objectp(present("zhangchu seng", environment(me))))
return notify_fail("掌厨僧伸手拦住你：里面是本派厨房，" + RANK_D->query_respect(me) + "请留步！\n");   
return ::valid_leave(me, dir);
}
