// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "官场");
  set ("long", @LONG

官场位于宫殿一侧，场上有八角雨亭一座，亭前百草仙花郁郁
葱葱。西边是宫墙，里面殿阁高耸入云。广场的东北方向与朝
门相通。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"zhaomen",
      ]));
  set("objects", ([
        __DIR__"npc/wenguan"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

