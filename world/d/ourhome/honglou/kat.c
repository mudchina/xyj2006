// Room: /u/hkgroup/kat
inherit ROOM;

void create ()
{
  set ("short", "µ´ÓÆÓÆÈı¸üÃÎ");
  set ("long", @LONG

¡¡¡¡¡¡¡¡¿İÌÙ£¬ÀÏÊ÷£¬»èÑ»¡­¡­

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"pavilion",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}
