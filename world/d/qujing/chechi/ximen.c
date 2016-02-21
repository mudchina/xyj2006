// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/ximen.c

inherit ROOM;

void create ()
{
  set ("short", "西城门");
  set ("long", @LONG

西城门紧闭，城楼高耸，车迟国旌旗迎风簌簌飘扬。楼两角筑有
石墙箭楼，站有两列弓箭手。楼下护墙借备森严，内有一排穿甲
戴盔的刀斧手严阵以待。

LONG);

  set("exits", ([
        "north"        : __DIR__"qiang3a",
        "east"         : __DIR__"taiping",
        "west"         : __DIR__"shatan4",
        "south"        : __DIR__"qiang5a",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
      dir == "west")
    return 0;
  return 1;
}
