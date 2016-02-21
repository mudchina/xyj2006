// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

这里西边是富丽堂皇的府门，东与北是青石板条铺成的小街，
令人觉得悠闲宁静，街头有炊烟袅袅飘来青柴的香味。不远
处传来家家户户舂米的声音，还有大户人家榨香油的醇香味。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie2",
        "west"   : __DIR__"fumen",
        "east"   : __DIR__"xiaojie5",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



