// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山路弯曲在群山峻岭之中来回起伏绕行，两边是爬满苔藓的山
岩，岩石缝里长出苍松翠柏。路上尽是碎石野草，不时有一些
枯枝藤蔓绊脚。

LONG);

  set("exits", ([
        "westup"   : __DIR__"jindou3",
        "northeast"   : __DIR__"shanlu4",
      ]));
  set("outdoors", __DIR__);

  setup();
}



