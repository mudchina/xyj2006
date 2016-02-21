//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "辰龙道");
  set ("long", @LONG

长长的辰龙大道在开封城内东西向延伸，道路上由青石条铺成，两边
种着郁郁葱葱的树木。往西远远可见开封府的城门，往东有一座高大
的铁塔，南边是一马场。

LONG);

  set("exits", ([
        "west" : __DIR__"chen1",
        "east" : __DIR__"tieta",
        "south" : __DIR__"machang",
      ]));

  set("outdoors", __DIR__);

  setup();
}


