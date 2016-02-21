// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "春廊");
  set ("long", @LONG

春廊是长长的直角绿色廊厅，廊檐上画着各种各样的鲜花香草，
廊边放着躺椅茶几，可供贵宾们休息闲聊。两边各有一通道导
向贵宾观礼台。

LONG);

  set("exits", ([
        "east"   : __DIR__"north",
        "south"   : __DIR__"west",
      ]));

  setup();
}




