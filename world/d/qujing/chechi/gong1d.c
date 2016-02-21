// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/gong1d.c

inherit ROOM;

void create ()
{
  set ("short", "宫墙");
  set ("long", @LONG

宫墙雄伟，用大石块堆砌而成，顶端飘着皇家旌旗。每隔一丈就
设有一个哨楼，上面有哨兵持矛巡逻。墙下是一条石路，沿墙伸
向远方。

LONG);

  set("exits", ([
        "east"         : __DIR__"gong1e",
        "west"         : __DIR__"gong1c",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

