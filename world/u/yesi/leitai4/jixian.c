// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "祭贤场");
  set ("long", @LONG

祭贤场心搭起了一座玉石祭台，祭台上端端正正地放着一个镂银签盒，
里面插着金签。祭台四周是香炉，点着袅袅香烟。场的北边是一个大
门，东西各有门通往其它的场。

LONG);

  set("exits", ([
        "north" : __DIR__"shuilu",
        "west" : __DIR__"pudu",
        "east" : __DIR__"ee",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
        __DIR__"npc/chen" :  1,
      ]));

  setup();
}


