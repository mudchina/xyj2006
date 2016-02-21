// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/dongmen.c

inherit ROOM;

void create ()
{
  set ("short", "东城门");
  set ("long", @LONG

东城门大开，城楼高耸，车迟国旌旗迎风簌簌飘扬。楼两角筑有石墙箭楼
，站有两列弓箭手。楼下护墙借备森严，内有一排穿甲戴盔的刀斧手严阵
以待。
LONG);

  set("outdoors", "/d/qujing/chechi");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"shatan1",
  "south" : __DIR__"qiang5g",
  "north" : __DIR__"qiang3g",
  "west" : __DIR__"ruizhao",
]));

  setup();
}

int valid_leave (object who, string dir)
{
  if ((! interactive(who)) &&
        dir == "east")
    return 0;
  return 1;
}


