// Room: /u/mimi/zhuziguo/stable_room.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "马槽");
  set ("long", @LONG

此间的马都是太子精心挑选的大宛宝马。其中以那匹名为＂绝尘＂
的马最为名贵。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"garden.c",
]  ));

  setup();
}
