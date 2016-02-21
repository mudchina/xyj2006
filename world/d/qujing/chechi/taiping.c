// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/taiping.c

inherit ROOM;

void create ()
{
  set ("short", "太平场");
  set ("long", @LONG

太平场以碎砖铺成，场子不太大。场心有破旧的泥土祭坛，上面
稀稀拉拉地长了一些枯草。这里算是车迟国的比较热闹的地段，
穿着朴素的行人在场上走过。

LONG);

  set("exits", ([
        "west"         : __DIR__"ximen",
        "north"        : __DIR__"caichang",
        "south"        : __DIR__"jieshi6",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

