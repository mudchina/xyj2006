// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "金灯桥");
  set ("long", @LONG

桥上张灯结彩，各种彩灯纸笼高高挑起，桥上放置着大小瓷盏
瓷盆缸，散发着酥香油的醇香味。桥上人来人往气氛非同寻常
宛若过节一般。

LONG);

  set("exits", ([
        "north"   : __DIR__"qiaobei",
        "south"   : __DIR__"qiaonan",
      ]));
  set("objects", ([
        __DIR__"obj/gang"   : 3,
        __DIR__"npc/dengguan"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



