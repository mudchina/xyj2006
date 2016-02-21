// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小街");
  set ("long", @LONG

这里是桥南的街口，往东可见一庙宇。走在青石板条铺成的小
街上，令人觉得悠闲宁静，街头有炊烟袅袅飘来青柴的香味。
不远处传来家家户户舂米的声音，还有大户人家榨香油的醇香
味。

LONG);

  set("exits", ([
        "north"   : __DIR__"qiaonan",
        "east"   : __DIR__"jimiao",
        "south"   : __DIR__"xiaojie4",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



