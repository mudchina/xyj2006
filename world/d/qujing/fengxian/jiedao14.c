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
        "north"    : __DIR__"jiedao7",
        "west"    : __DIR__"jiedao13",
        "south"    : __DIR__"xiang",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

