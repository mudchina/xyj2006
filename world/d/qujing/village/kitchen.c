//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

这个厨房特别的干净，好象才盖的一样，但是你转念一想，也许
女人多的家庭都是这样的吧，女人勤劳对男人是有很多好处的。

LONG);
  set("exits", ([
        "east"  : __DIR__"house",
          ]));
  set("objects",([
	    __DIR__"obj/luzi" : 1,
	]));
  setup();
}
