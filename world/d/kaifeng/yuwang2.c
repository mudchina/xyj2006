//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "禹王道");
  set ("long", @LONG

禹王道在这里由南北向转东向上拐去，大道由碎石块铺就而成，道路
略微变窄一些。道路的两边都是一片片成林的青松翠柏树木，一阵阵
轻风吹过，松柏林中涛声不绝。

LONG);

  set("exits", ([
        "north" : __DIR__"yuwang1",
        "eastup" : __DIR__"yuwang3",
      ]));

  set("outdoors", __DIR__);

  setup();
}


