//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "广寒宫正殿");
  set ("long", @LONG

迎面先看见一个赤金九龙青地大匾，上面写著斗大三个字：「广寒宫」；
大紫檀雕螭案上设著三尺来高青绿古鼎，悬著待漏随朝墨龙大画，一边是
金锥彝，一边是玻璃盒，底下两溜十六张紫檀交椅。　　　
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fairy2.c" : 1,
  __DIR__"npc/fairy3.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"wulang.c",
  "south" : __DIR__"road3",
  "west" : __DIR__"huilang.c",
]));

  setup();
}
