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
        "west" : __DIR__"yuwang1",
        "east" : __DIR__"yuwang5",
      ]));

  set("outdoors", __DIR__);

  setup();
}

// mon 11/8/98 for ymdh's alternative_die.
void init()
{
    if(!this_player())  return;
    this_player()->delete_temp("ymdh/entered");
}

