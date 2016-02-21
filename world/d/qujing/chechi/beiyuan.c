// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/beiyuan.c

inherit ROOM;

void create ()
{
  set ("short", "北院");
  set ("long", @LONG

北院里空荡荡，靠墙稀稀拉拉种了一些树，半死不活地长着。北
边放有一见底的破水缸。再往北是间破门破窗的房子，往南是金
刚殿。

LONG);

  set("exits", ([
        "north"         : __DIR__"zhaifang",
        "south"         : __DIR__"jingang",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

