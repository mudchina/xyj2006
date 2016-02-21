// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

这里是街的北尽头。走在青石板条铺成的小街上，令人觉得悠
闲宁静，街头有炊烟袅袅飘来青柴的香味。不远处传来家家户
户舂米的声音，还有大户人家榨香油的醇香味。

LONG);

  set("exits", ([
        "north"   : __DIR__"minju1",
        "east"   : __DIR__"minju2",
        "south"   : __DIR__"xiaojie3",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



