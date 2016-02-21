// create by snowcat.c 12/8/1997

inherit BANK;

void create ()
{
  set ("short", "钱庄");
  set ("long", @LONG

钱庄是一个青瓦小楼，门上有一旧匾，一个厚门帘将门遮得死
死的。屋里是一个高高的紫色柜台，从柜台里不时传来金银锭
铜币落盘的声音。柜台上放着一盏油灯，一闪一闪地照着屋子。

LONG);

  set("exits", ([
//        "east"   : __DIR__"jiedao68",
		"north"  : __DIR__"jiedao56",
      ]));
  set("objects", ([
        __DIR__"npc/situ"   : 1,
      ]));

  setup();
}


