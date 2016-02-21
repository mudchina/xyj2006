// Room: /u/mimi/zhuziguo/backyard  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "后院");
  set ("long", @LONG

后院方方正正，院子里开了一块菜园子，种着各种蔬菜瓜果，绿油
油一片。有一个藤架子，一些说不出名字的蔓藤爬在上面，开着黄
色的小花。

LONG);

  set("outdoors", __DIR__"");                         
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"eastroom",
  ]));

  setup();
}
