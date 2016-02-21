// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG
   
  屋内有一张四方桌,但已破损，邻墙铺了一席破烂不堪的
草席，主人不在家，东西都蒙上了厚厚的一层灰。只有几只
大老鼠，瞪着一双小眼睛，惊疑的看着这不速之客。地上散
落着一个水罐，两、三个破碗。
。
LONG);
  
  set("objects", ([
        __DIR__"npc/rat"   : 2,
      ]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
     "east" :__DIR__"sroad7",
]));

  setup();
}






