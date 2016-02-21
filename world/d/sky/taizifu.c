#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "三太子府");
  set ("long", @LONG

府中的主人乃是三太子哪吒，御封的三坛海会大将。当初哪吒年
闯祸，天王恐有后患欲杀之，哪吒奋而割肉还母，剔骨还父，一
点灵魂飘到西方极乐世界，佛以碧藕为骨，荷叶为衣，念动起死
回生真言，哪吒遂又得了性命。后降服九十六洞妖魔，端地是神
通广大。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"yongdao",
  ]));

  set("objects", ([
    __DIR__"npc/nezha" : 1,
  ]));
  setup();
}


