// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "面馆");
  set ("long", @LONG

这是位于城中心的一家面馆，地段繁华，生意极为兴隆。店里销售
各式各样精美面点，面条，烧饼馍馍。东边有一门通向朱紫街，南
边通向夕林街。

LONG);

  set("exits", ([ 
    "east" : __DIR__"zhuzi3",
    "south" : __DIR__"xi4",
  ]));
  set("objects", ([
    __DIR__"npc/liuguang" : 1,
  ]));
  setup();
}
