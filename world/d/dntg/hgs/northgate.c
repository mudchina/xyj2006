// Room: /d/4world/northgate.c
inherit ROOM;

void create ()
{
  set ("short", "傲来国北城门");
  set ("long", @LONG

一座高大的城墙耸立于前者，城上不断有守城的官兵走过。城中
往往来来的人很多，傲来国人风淳朴，民富而知足，到处也都是
一幅喜气洋洋的景色。
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("outdoors", __DIR__"");
  set("objects", ([
                __DIR__"npc/wushi": 2]) );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"north2.c",
  "north" : __DIR__"aolai",
  "east"  : __DIR__"aolaifighting",
]));
  set("no_fight", 1);

  setup();
}
int valid_leave(object me, string dir)
{
// This line caused a bug. Modified by Dream on 08/27/97
//	me=this_player();

    if (dir == "south" ) {
        if ((int)me->query("combat_exp") < 15000
	&& (int)me->query("PKS") < 2 ) 
		return ::valid_leave(me, dir);
	return notify_fail("武士将手中长剑一横，喝道：看你贼眉鼠眼的样子，不许进！\n");
	}

return 1;
}

