//Cracked by Roath
inherit ROOM;
void create()
{
  set ("short", "承恩街");
  set ("long", @LONG

        这个小城也颇有一段历史了，由于位置偏远，而当地居民也
不是很多，所以照成了小城的末落。这虽然远比不了长安的繁华，但
它却有另种恬静的氛围。

LONG);
        set("exits", ([
  "east" : __DIR__"center",
  "west" : __DIR__"chengen-2",
  "south": __DIR__"zhahuopu",
]));
  setup();
}
