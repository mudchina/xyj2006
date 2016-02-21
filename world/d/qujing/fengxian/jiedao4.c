// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道一丈来宽，民事冷落，店铺倒闭，街上走着一些无精打采
的官人，以及零零散散的面黄饥瘦的饥民与衣裳褴褛的乞丐。
令人有点惨不忍睹。

LONG);

  set("exits", ([
        "north"    : __DIR__"jiuguan",
        "south"    : __DIR__"jiedao10",
        "east"    : __DIR__"shikou",
        "west"    : __DIR__"jiedao3",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

