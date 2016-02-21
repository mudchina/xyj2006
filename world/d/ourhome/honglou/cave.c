// Room: /u/hkgroup/cave
inherit ROOM;

void create ()
{
  set ("short", "蓼汀花溆");
  set ("long", @LONG

　　水声潺潺泻出，石洞上则萝薜倒垂，下则落花浮荡。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"none.c",
  "north" : __DIR__"yard2",
  "south" : __DIR__"village",
]));
  set("outdoors", "/u/hkgroup");
  
  set("objects", ([
   "/d/obj/misc/seed":1,
  ]));

  setup();
}

/*
int valid_leave(object me, string dir)
{
	if( dir=="up" && !wizardp(me) )
		return notify_fail("楼上闲人免进。\n");
	return ::valid_leave(me, dir);
}

*/
