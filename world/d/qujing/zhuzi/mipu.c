// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "米铺");
  set ("long", @LONG

米铺里柜台很高，后面堆着一袋一袋的大米。屋堂里放着一个大木
架，上面是一框框的蔬菜和一些装着食盐椒料。柜台后面正坐着米
老板，瞪着一双精明的老鼠眼。

LONG);

  set("exits", ([ 
    "north" : __DIR__"xi3",
  ]));
  set("objects", ([
    __DIR__"npc/mi" : 1
  ]));
  setup();
}
