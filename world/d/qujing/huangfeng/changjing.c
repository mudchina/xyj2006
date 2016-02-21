// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/cangjing.c

inherit ROOM;

void create ()
{
  set ("short", "经阁");
  set ("long", @LONG

经阁里东西两侧各有一壁书柜，柜上列着各种经文佛典。居中
设一书案，案上放着一本经书。封页上似乎写着“法华经”三
个小字。

LONG);

  set("exits", ([
        "south"    : __DIR__"jiangtang",
      ]));

  set("objects", ([
      ]));
  setup();
}

