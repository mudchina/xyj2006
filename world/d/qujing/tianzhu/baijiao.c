// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "百脚山麓");
  set ("long", @LONG

山林浓密黑压压地起伏，山路沿着山势蜿蜒，坎坎坷坷不平。
从浓密的山林里偶然可以听野兽远远的吼叫，路边风吹草动沙
沙作响。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shan4",
        "southwest"   : __DIR__"shanmen",
      ]));
  set("outdoors", __DIR__);

  setup();
}



