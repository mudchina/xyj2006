// created by snowcat.c 5/23/1997
// room: /d/pantao/yaoa.c

inherit ROOM;

void create ()
{
  set ("short", "瑶池西廊");
  set ("long", @LONG

瑶池西廊摆满芝兰香蕙，瑶草奇花。仙姬仙子在此备制仙果仙
肴。但见金银果盘内金丸珠弹，红绽黄肥。中间供有数枚紫纹
娇嫩半红半绿的蟠桃。

LONG);

  set("exits", ([
        "east"  : __DIR__"yaob",
      ]));

  setup();
}

