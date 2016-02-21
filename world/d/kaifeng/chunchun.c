//Cracked by Roath
// by snowcat

inherit ROOM;

void create ()
{
  set ("short", "春醇茶栈");
  set ("long", @LONG

茶栈里摆了几张红木桌子，围着桌子放了几条长凳。此处窗明几净，
满屋飘着茶香。里墙是柜台，上面放满了大小不同的茶筒茶罐。东边
门帘通向街头。

LONG);

  set("exits", ([
    "east" : __DIR__"shun5",
  ]));
  set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/chaniang" : 1,
  ]));
  set("resource", ([ /* sizeof() == 1 */
    "water" : 1,
  ]));
  set("valid_startroom", 1);
  setup();
}

