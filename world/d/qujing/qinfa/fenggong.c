// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "凤宫");
  set ("long", @LONG

凤宫里四周挂着花翎凤羽，四面是贴彩百棂窗。宫殿里插着两
面巨型凤尾扇。扇下有一翠绿银竹镂花床，铺着玫瑰红鸳鸯锦
丝被褥。

LONG);

  set("exits", ([
        "west"    : __DIR__"longgong",
        "north"    : __DIR__"qingong1",
        "south"    : __DIR__"qingong2",
      ]));
  set("objects", ([
        __DIR__"npc/queen"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

