// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG

茅屋里有点黑暗，靠墙放着一杨木桌子，上有一盏铜油灯。门
前有一水缸盛着半缸清溪水，里面有一蒿草垫子床，铺着一块
羊毛毯。

LONG);

  set("exits", ([
        "west"    : __DIR__"zhuang",
        "southwest"    : __DIR__"yang5",
      ]));
  set("resource", ([
        "water"   : 1,
      ]));
  setup();
}

