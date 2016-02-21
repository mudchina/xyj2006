// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "石牢");
  set ("long", @LONG

这里是阴森森的石牢，石牢四周是犬牙交错的怪石，从石壁上
突凸出来。地上铺着一些枯草，还有几块破破烂烂的旧兽皮零
碎地垫在地上。

LONG);

  set("exits", ([
      ]));
  set("sleep_room", 1);
  set("no_magic", 1);
  set("no_fight", 1);

  setup();
}



