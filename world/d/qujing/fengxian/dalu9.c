// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "大路");
  set ("long", @LONG

路遥遥，道幽幽，这里的大路又长又远。天边有云山雾海，近
处是荒芜的农田，偶尔可见到一些小溪小河，均已干涸见底，
路边大树枝枯叶落，草黄土裂。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"dalu8",
        "west"    : "/d/qujing/yuhua/xiaolu10",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

