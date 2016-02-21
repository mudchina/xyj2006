//fdoor.c

inherit ROOM;

void create ()
{
  set ("short", "枫雪宫大门");
  set ("long", @LONG

＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
   枫，是红的，
                        天，是蓝的，
                                          地，是黄的，
             那洁白无瑕的雪，在窗外飞舞……
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊

	枫雪天地会告示(gaoshi)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"fxtd",
  "enter" : __DIR__"living",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "gaoshi" : "《枫雪天地》：
    http://www.ams.queensu.ca/lyh/fxtd/
＊投稿须知＊：
    http://www.qucis.queensu.ca/home/guo/fxtd/submissions.html
",
]));
  set("outdoors", 1);

  setup();
}
