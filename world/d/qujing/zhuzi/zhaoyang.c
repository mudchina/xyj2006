// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "昭阳宫");
  set ("long", @LONG

宫中檀香木柱雕有祥云朵朵，墙壁上五彩缤纷虹霞万千，真是个仙
境重生。丝竹乐声轻缓如风飘逸，又见宫女托着鲜果山珍佳肴来回
走过。

LONG);
  set("exits", ([ 
    "north" : __DIR__"zheng",
    "east" : __DIR__"housan",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 1,
    __DIR__"npc/girl" : 2,
  ]));
  setup();
}
