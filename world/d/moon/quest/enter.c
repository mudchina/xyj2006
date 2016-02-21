//Cracked by Roath

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "蛮荒之地");
  set ("long", @LONG

这里是月宫的背面，一片穷山恶水。身后是墨绿色的湖水，
眼前一座山峰，怪石嶙峋，山间瘴气迷漫，鸟兽绝迹。山脚
下有一条小径，崎岖不平，蜿蜒往西而去，时有怪兽出没。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road1.c",
]));
 set("outdoors", 1);
 setup();
}

