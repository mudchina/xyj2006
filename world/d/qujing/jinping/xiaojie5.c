// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

你走在青石板条铺成的小街上，令人觉得悠闲宁静，街头有炊
烟袅袅飘来青柴的香味。不远处传来家家户户舂米的声音，还
有大户人家榨香油的醇香味。南边有一客店，打着招牌。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie4",
        "east"   : __DIR__"xiaojie6",
        "south"   : __DIR__"kedian",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



