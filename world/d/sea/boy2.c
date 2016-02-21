// boy2.c

inherit ROOM;

void create ()
{
  set ("short", "过道");
  set ("long", @LONG

一条长长的走廊，联结着前后厅。东边是太子的寝室，传出杯酬交错
的声音，几名宫女端着盒子走来走去。北边一间大厅，是太子练武的
地方。

LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gongnu" : 2,
]));
  set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"boy1",
  "north" : __DIR__"boy4",
  "east" : __DIR__"boy3",
]));
//      
        set("water", 1);
//  
        setup();
}

