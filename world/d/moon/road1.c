//Cracked by Roath
// Room: /moon/road.c

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

两边白石陵层，或如鬼怪，或如猛兽，纵横傲立；上面苔藓成斑，藤萝掩
映；其中微露羊肠小径。
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"ontop.c",
  "north" : __DIR__"road2",
]));
  set("objects",(["/d/obj/flower/yehua.c":1,]));

  setup();
}






