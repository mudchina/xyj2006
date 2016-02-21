// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "斗蟋馆");
  set ("long", @LONG

斗蟋馆里有一张长方木桌，上面放着一些陶盘陶罐，专供斗蟋蟀之
用。一些公子少爷光顾此处，一边摇着鹅毛扇一边聊天，同时观斗
蟋蟀。

LONG);

  set("exits", ([ 
    "south" : __DIR__"tian2",
  ]));
  set("objects", ([ 
    __DIR__"npc/xishuai" : 2,
  ]));
  setup();
}

void init ()
{
  object xishuai1 = present("xishuai 1",this_object());
  object xishuai2 = present("xishuai 2",this_object());

  if (! xishuai1 || ! xishuai2)
    return;
  xishuai1->kill_ob(xishuai2);
  xishuai2->kill_ob(xishuai1);
}
