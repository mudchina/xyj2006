// Room: /u/hkgroup/yard1
inherit ROOM;

void create ()
{
  set ("short", "潇湘馆");
  set ("long", @LONG

　　　　秀玉初成实，堪宜待凤凰。竿竿青欲滴，个个绿生凉。
　　　　迸砌防阶水，穿□碍鼎香。莫摇清碎影，好梦昼初长。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pavilion",
  "north" : __DIR__"village",
  "east" : __DIR__"wow",
]));

  setup();
}
