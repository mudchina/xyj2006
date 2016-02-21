// Room: /u/mimi/zhuziguo/palace.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "昭泽殿");
  set ("long", @LONG

这里是乌鸡国王召见臣子，研讨国家大事的地方。四壁琉璃焕彩，
流金滴玉。阶下臣子侍卫屏息作声，等候国王的旨意。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"huilang.c",
    "south" : __DIR__"zym.c",
  ]));
  set("objects", ([
      __DIR__"npc/taijian" : 2,
      __DIR__"npc/chen" : 3,
      __DIR__"npc/kingfake" : 1,
  ]));

  setup();
}
