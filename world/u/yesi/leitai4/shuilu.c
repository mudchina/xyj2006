// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "水陆大会");
  set ("long", @LONG

禹王台的后面建起了一座高大的殿宇，殿前搭起了巨大的台子，上面
彩旗飞舞。殿的上方挂了一个大匾：“水陆大会”。水陆大会的会场
由一些兵卒把守着。

LONG);

  set("exits", ([
        "north" : __DIR__"yuwang3",
        "southwest" : __DIR__"pudu",
        "south" : __DIR__"jixian",
        "southeast" : __DIR__"ee",
        "southup" : __DIR__"gate",
      ]));
  set("objects", ([
        __DIR__"npc/zu" :  4,
      ]));

  set("outdoors", __DIR__);

  setup();
}


