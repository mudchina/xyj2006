inherit "/std/city.c";

void create ()
{
reload("汉阳");
set ("short", "汉阳城");
set ("long", @LONG

这是一座古老的城市。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhuque-s1",
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}

