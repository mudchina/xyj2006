// snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "宝林寺");
  set ("long", @LONG

只见八字砖墙泥红粉，两边门上钉金钉，叠叠楼台藏岭畔，城城宫阙
隐山中。果然是一座好寺院。正门上红底烫金的写着三个字：＂宝林
寺＂。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"road4",
  "enter" : __DIR__"piandian.c",
  "south" : __DIR__"road5.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/monk2" : 2,
  __DIR__"npc/monk1" : 1,
]));

  setup();
}

int valid_leave (object who, string dir)
{
  object seng = present ("shousi seng", environment(who));
  if (dir == "enter" && seng && living (seng))
    return notify_fail (seng->query("name")+"说道：“寺院恕不接客，请回。”\n");
  return ::valid_leave(who, dir);
}
