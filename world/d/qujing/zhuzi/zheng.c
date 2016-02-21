// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "正宫");
  set ("long", @LONG

正宫紫气万千，祥云飞舞红光满殿。只见玛瑙檐白玉砖琉璃瓦，四周
的墙上锦龙绣凤欲飞欲舞，正中是金鼎银座，两边文武官员分别排开
肃然而立。

LONG);
  set("exits", ([ 
    "north" : __DIR__"qian",
    "west" : __DIR__"yuhua",
    "east" : __DIR__"neiyuan",
    "south" : __DIR__"zhaoyang",
  ]));
  set("objects", ([
    __DIR__"npc/taijian" : 2,
    __DIR__"npc/girl" : 2,
  ]));

  setup();
}

