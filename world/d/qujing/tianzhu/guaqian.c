// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "卦签铺");
  set ("long", @LONG

卦签铺里摆了一仙桌，上面有几本羊皮书，几只雕花白石签筒
里插着大大小小的竹签。铺角有一香案，上有一只细脚香炉，
炉里插着几根已经熄了的香。

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao61",
      ]));

  setup();
}


