inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "天边");
  set ("long", @LONG

蓬莱岛上风光秀丽，当真是好去处！高崖上视野开阔，远望四周，
把蓬莱景色看的清清楚楚。远处大海如明镜般平整。山崖上长有
无数异草，飘着淡淡香气。
LONG);
  	set("outdoors", 1);
        set("objects", ([ /* sizeof() == 2 */
// __DIR__"npc/nuwa" : 1, NPC掉了，我找不到nuwa 这个npc
	]));

  setup();
}
