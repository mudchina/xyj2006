// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

走在青石板条铺成的小街上，令人觉得悠闲宁静，街头有炊烟
袅袅飘来青柴的香味。不远处传来家家户户舂米的声音，还有
大户人家榨香油的醇香味。

LONG);

  set("exits", ([
        "north"   : __DIR__"minju3",
        "west"   : __DIR__"xiaojie5",
        "east"   : __DIR__"xiaojie7",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



