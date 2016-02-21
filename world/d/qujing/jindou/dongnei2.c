// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

宽敞的洞内雾气腾腾，洞顶上长着粗长的青藤，从头上挂下来。
洞壁插着兽油火把，吱吱地冒着烟，将洞内照亮。洞的地上填
得平平整整，铺着一块一块石板。

LONG);

  set("exits", ([
        "east"   : __DIR__"dongnei3",
        "south"   : __DIR__"dongnei4",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));

  setup();
}



