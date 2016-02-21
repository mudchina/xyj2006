// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/changjing.c

inherit ROOM;

void create ()
{
  set ("short", "禅院");
  set ("long", @LONG

院中一条青石路面，路两侧长满了青松翠柏，古藤奇芭。东边
一排厢房，是道人们休息的地方。北面就是菩萨讲经的所在，
远远的已经有诵经声传了过来。

LONG);

  set("exits", ([
        "west"    : __DIR__"bedroom",
        "north"   : __DIR__"jiangtang",
	"south" : __DIR__"shanmen",
      ]));

  set("outdoors",__DIR__);
  setup();
}

