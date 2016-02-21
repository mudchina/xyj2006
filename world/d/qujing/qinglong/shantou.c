// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山头");
  set ("long", @LONG

奇峰异石边出现一开阔地带，脚下东南边是长长的绿色森林，
东边是绝壁，下边是万丈深渊。西边岩石狰狞，似乎无路可言，
东北方向比较平坦些。

LONG);

  set("exits", ([
        "southdown"   : __DIR__"shanlu1",
        "northeast"   : __DIR__"shanding",
      ]));
  set("outdoors", __DIR__);

  setup();
}



