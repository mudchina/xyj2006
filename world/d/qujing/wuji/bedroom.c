// Room: /u/mimi/zhuziguo/bedroom.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "寝宫");
  set ("long", @LONG

这里光线柔和，屋里装饰精美细腻。靠窗放有一长条桌，陈列着一
些玉器瓷器。另一面是床，整齐地铺着锦罗花被。往北通向露天的
小院子。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"garden",
  ]));
  set("sleep_room",1);
  set("if_bed",1);

  setup();
}
