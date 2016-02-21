//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "斜巷");
  set ("long", @LONG

这里好象已是路的尽头，下方有一条窄窄的斜巷，里面黑黑的望
不到底，不知能通到何处。巷口挂着一个木牌，写着“入禁地者
死”五个字。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yongdao5",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/bianfu" : 1,
  __DIR__"npc/mahuang" : 1,    
]));


  setup();
}

