//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "仓库");
  set ("long", @LONG

石头仓库不是很大，用于堆放武器，工具，肉干肉巴子之类的
储备物。现在仓库里空空如也，地上散着一些乱糟糟的干草和
不成块的碎兽皮。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"canting",
      ]));

  setup();
}



