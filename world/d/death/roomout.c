// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "幽司");
  set ("long", @LONG

向东看去是一片荒凉，远处是一座黑山，山上笼着浓浓的黑气。
西边是阎罗地府，传来阵阵怒斥与求饶的声音。南边一间小室，
几个文官打扮的人出出入入。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sifang",
  "east" : __DIR__"huang",
  "west" : __DIR__"walk7",
]));
  set("hell", 1);
  set("out_doors", 1);

  setup();
}
