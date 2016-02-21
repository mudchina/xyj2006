//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "辰龙道");
  set ("long", @LONG

开封城内一条长长的大道，道路上由青石条铺成，两边是常青的树木
沿着大道两边成排种开，郁郁葱葱。往西是开封府的城门，往东通向
城里，可远远看见一座深色的高塔。

LONG);

  set("exits", ([
        "west" : __DIR__"chengmen",
        "east" : __DIR__"chen2",
      ]));

    set("objects",([
    "/d/shendian/babu/mohuluojia" : 1,
    ]));
  set("outdoors", __DIR__);

  setup();
}


