// Room: /u/mimi/zhuziguo/hilltop  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "山顶");
  set ("long", @LONG

山顶山磐石耸立，旁边有一片稀稀拉拉的树林。南边是陡峭的悬崖
直壁，无路可行。此处山高风冷，空谷回音。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
    "northdown" : __DIR__"road5",
  ]));
  set("objects", ([
     __DIR__"npc/prince" : 1,
     __DIR__"npc/siwei" : 2,
  ]));

  set("outdoors", __DIR__"");
  setup();
}

