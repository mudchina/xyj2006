// Room: /d/changan/shuju  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "四季水果店");
  set ("long", @LONG

这家水果店店面虽然不大，但各色瓜果齐全，而且时令瓜果每日由
城外运来，尤其新鲜。各色水果鲜红翠绿，十分诱人。

LONG);

  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/vender.c" : 1,
  ]));
  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"estreet.c",
  ]));

  setup();
}
