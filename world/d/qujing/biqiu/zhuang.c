// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "清华庄");
  set ("long", @LONG

清华庄是一个小小的空场子，座落在杨树林子里。场子的北面
传来阵阵溪水流动的声音，东面有一蒿草茅屋，西边有路通入
杨树林子。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"xinan",
        "west"    : __DIR__"yang2",
        "east"    : __DIR__"maowu",
      ]));
  set("outdoors",__DIR__"");
  setup();
}
