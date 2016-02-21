//fxtd.c

inherit ROOM;

void create ()
{
  set ("short", "枫雪天地");
  set ("long", @LONG

＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
   枫，是红的，
                        天，是蓝的，
                                          地，是黄的，
             那洁白无瑕的雪，在窗外飞舞……
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fdoor",
  "east" : "/d/moon/yunu3",
]));
  set("outdoors", 1);

  setup();
}
