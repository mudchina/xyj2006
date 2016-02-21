// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "阴司");
  set ("long", @LONG

阴司内寒气森森，黄土小径连向四方。左右分别有座青砖瓦房，偶
尔有些勾司人出入。天色一片阴暗，天际现着血色。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"new-sifang3",
  "east": __DIR__"new-sifang4",
  "north": __DIR__"new-walk4",
]));
  set("hell", 1);

  setup();
}


