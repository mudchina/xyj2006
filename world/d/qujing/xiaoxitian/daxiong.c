// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG

大雄宝殿里佛像高坐台上，台前放着一个长长的漆木香案，案
上有青铜香炉一对，香炉里面冒出青青的香烟。宝殿的西边是
寺院，北边是珍楼，南边是宝阁。

LONG);

  set("exits", ([
        "north"   : __DIR__"zhenlou",
        "south"   : __DIR__"baoge",
        "west"   : __DIR__"siyuan",
        "east"   : __DIR__"houdian",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong"   : 3,
        __DIR__"npc/huangmei"   : 1,
      ]));

  setup();
}



