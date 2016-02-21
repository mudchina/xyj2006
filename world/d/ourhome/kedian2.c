// Room: /city/kedian2.c

inherit ROOM;

void create ()
{
  set ("short", "荒郊野外");
  set ("long", @LONG
你正走在荒郊野外的一条崎岖小路上，只有一些小虫子
绕着你飞来飞去。 
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kedian",
  "south" : __DIR__"kedian3",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/obj/money/silver" : 2,
]));

  setup();
}
