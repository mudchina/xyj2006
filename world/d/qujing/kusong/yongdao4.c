//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "前洞");
  set ("long", @LONG

这里宽敞了许多，洞内一片光亮。来回有很多小妖走动，嘻嘻嚷
嚷地也十分热闹，四处的路口深深地不知通向何方。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao6",
  "southeast" : __DIR__"yongdao2", 
  "southwest" : __DIR__"yongdao3",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/yao2" : 2,    
//  __DIR__"npc/xian": 1,
]));



  setup();
}

