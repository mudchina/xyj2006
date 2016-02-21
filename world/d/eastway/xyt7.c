// create by snowcat.c 4/20/1997
// room: /d/eastway/xyt7.c

inherit ROOM;

void create ()
{
  set ("short", "小雁塔内");
  set ("long", @LONG

塔内气氛静而神秘，光线有些昏暗朦胧。四周墙壁上有数
盏龛灯，周围绘有彩色壁画。塔内有楼梯供人上下，从龛
形门窗可以纵目远眺。

LONG);

  set("exits", ([
        "up"       : __DIR__"xyt8",
        "down"     : __DIR__"xyt6",
      ]));

  setup();
}






