//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

洞内的厨房相当的大，来回竟有十来个小妖忙活。屋内各种炊具
也是应有尽有，东边一排特大的蒸锅冒着水气。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao8", 
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/xian": 1,
]));



  setup();
}

