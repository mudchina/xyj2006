// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

这里的山路平缓但松散如泥，走在上面深一脚浅一脚，让人不
禁有点心虚。路边可以听见林中鸟儿的鸣唱，风不断地吹过，
四处开满无名野花。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shanlu1",
        "southwest"   : __DIR__"shanlu7",
      ]));
  set("outdoors", __DIR__);

  setup();
}



