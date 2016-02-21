// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "石头门");
  set ("long", @LONG

石壁上青苔如云，有一门洞自然而成。门口怪石累累如笋如兽，
自门楣上有滴水落下，嗒嗒有声。往北有一木亭，往南可见一
逍遥石院。

LONG);

  set("exits", ([
        "north"   : __DIR__"muxiang",
        "south"   : __DIR__"shiyuan",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

