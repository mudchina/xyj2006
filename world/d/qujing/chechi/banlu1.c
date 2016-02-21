// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/banlu1.c

inherit ROOM;

void create ()
{
  set ("short", "石板路");
  set ("long", @LONG

南城的小丘上整整齐齐地铺着一条石板路，路边种有两排矮树，
间有奇花异草。矮树绿枝碧叶，清风徐徐，恰是十分宜人。

LONG);

  set("exits", ([
        "southdown"    : __DIR__"banlu2",
        "northup"      : __DIR__"dianmen",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

