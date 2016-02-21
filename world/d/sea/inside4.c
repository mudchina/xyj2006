// hill.c

inherit ROOM;

void create ()
{
  set ("short", "内堂");
  set ("long", @LONG

后殿中铜炉熏香，又有细廊通向两旁。殿后有一台，台中几个宫
女正陪着龙婆观景。台外有一片花园，老梅吐萼，遍地鹿苔。远
处平林尽被烟雾笼罩。
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long9.c" : 1,
  __DIR__"npc/longpo" : 1,
  __DIR__"npc/gonge" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huayuan1.c",
  "north" : __DIR__"huayuan.c",
  "west" : __DIR__"inside3",
  "east" : __DIR__"yidao.c",
]));
//      
        set("water", 1);
//  
  setup();
}
