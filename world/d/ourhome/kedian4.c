// Room: /city/kedian3.c

inherit ROOM;

void create ()
{
  set ("short", "路的尽头");
  set ("long", @LONG
地势稍显开阔，已经到了路的尽头。这里只有一座小亭，
亭上牌匾大书：“聚见亭”。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian3",
  "south" : __DIR__"xiaoting",
]));

  setup();
}






