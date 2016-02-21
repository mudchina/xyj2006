//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "舜王街");
  set ("long", @LONG

舜王街南北双向通行，与城里的另一条大街尧王街并行，穿过开封的
闹市区地带。街道由一色青石长条铺成。街的两边是各种各样的府宅
店铺，西边有一招牌：“春醇茶栈”。

LONG);

  set("exits", ([
        "southeast" : __DIR__"tieta",
        "north" : __DIR__"shun4",
        "west" : __DIR__"chunchun",
      ]));

  set("outdoors", __DIR__);

  setup();
}


