// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "坡路");
  set ("long", @LONG

天阳门外一条长路斜斜地向东北方向蜿蜒而去，极目远眺可见山色
茫茫云雾渺渺，一座巅峰挡住雾角，不知是何去处。路上行人很少
且行色匆匆。

LONG);

  set("exits", ([ 
    "eastup" : __DIR__"polu2",
    "southwest" : "/d/qujing/zhuzi/tian4",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
