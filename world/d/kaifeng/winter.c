//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "冬廊");
  set ("long", @LONG

冬廊是长长的直角纯白色廊厅，廊檐上素素地勾画着薄雪花，
廊边放着躺椅茶几，可供贵宾们休息闲聊。两边各有一通道导
向贵宾观礼台。

LONG);

  set("exits", ([
        "east"   : __DIR__"south",
        "north"   : __DIR__"west",
      ]));

  setup();
}




