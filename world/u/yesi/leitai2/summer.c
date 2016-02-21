// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "夏廊");
  set ("long", @LONG

夏廊是长长的直角朱色廊厅，廊檐上绘着盘亘起伏的群峰山峦，
廊边放着躺椅茶几，可供贵宾们休息闲聊。两边各有一通道导
向贵宾观礼台。

LONG);

  set("exits", ([
        "west"   : __DIR__"north",
        "south"   : __DIR__"east",
      ]));

  setup();
}




