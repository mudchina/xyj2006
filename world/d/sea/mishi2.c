// Room: /u/rainy/sea/mishi1.c inherit ROOM; 

inherit ROOM;


void create()
{
  set ("short", "密室");
  set ("long", @LONG
密室中黑黑的，看不大清楚。
LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/tuotiancha" : 1,
  __DIR__"obj/cold_dan" : 1,
  "/d/obj/armor/tiejia" : 1,
]));

  set("no_clean_up", 1);

  setup();
}
