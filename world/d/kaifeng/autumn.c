//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "秋廊");
  set ("long", @LONG

秋廊是长长的直角橙黄色廊厅，廊檐上描绘着秋风吹山落叶图，
廊边放着躺椅茶几，可供贵宾们休息闲聊。两边各有一通道导
向贵宾观礼台。

LONG);

  set("exits", ([
        "west"   : __DIR__"south",
        "north"   : __DIR__"east",
      ]));

  setup();
}




