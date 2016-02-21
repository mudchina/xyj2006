// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "禹王道");
  set ("long", @LONG

禹王大道自铁塔下向东南方向伸展而去，大道由碎石块铺就而成，可
行车马。道路的两边都是一片片成林的青松翠柏树木，和煦的轻风吹
过林涛阵阵。

LONG);

  set("exits", ([
        "northwest" : __DIR__"tieta",
        "south" : __DIR__"yuwang2",
        "east" : __DIR__"yuwang4",
      ]));

  set("outdoors", __DIR__);

  setup();
}


