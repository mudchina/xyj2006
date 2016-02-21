// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "偏宫");
  set ("long", @LONG

偏宫为一长方形的空穴，两边长满了石笋，洞顶上吊下一些钟
乳石，洞壁上插着几把火炬，以供照明之用。烟将洞壁熏得一
片漆黑。

LONG);

  set("exits", ([
        "east"   : __DIR__"zhong",
        "southwest"   : __DIR__"nei",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



