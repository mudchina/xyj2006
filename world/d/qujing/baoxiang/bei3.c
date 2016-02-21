// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/bei3.c

inherit ROOM;

void create ()
{
  set ("short", "北街");
  set ("long", @LONG

街上人很多，路两边不时传来异国情调的琴声。东面有一家小作
坊，门口放着式样奇特的毯子木器之类手工制品向路人销售，南
边通向王宫大门。

LONG);

  set("exits", ([
        "north"      : __DIR__"bei2",
        "east"       : __DIR__"zuofang",
        "south"      : __DIR__"bei4",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

