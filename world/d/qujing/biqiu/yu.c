// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "玉殿");
  set ("long", @LONG

殿里一面是玉壁光洁如镜，另外一面是香草廊百花争艳。南边
放有绒缎镂花椅，旁边打着一排龙凤扇屏。西边有莲花套窗三
六共一十八扇。

LONG);

  set("exits", ([
        "north"    : __DIR__"bao",
      ]));
  set("objects", ([
        __DIR__"npc/girl"    : 2,
        __DIR__"npc/hou"    : 1,
      ]));
  setup();
}

