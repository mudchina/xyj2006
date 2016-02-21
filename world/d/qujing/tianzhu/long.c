// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "龙阁");
  set ("long", @LONG

整个楼阁为金黄色，阁内的西墙上有巨大的琉璃砖二龙戏珠，
楼阁里面的地上铺着暗红色的火方石，上面再铺设一条长长的
绣花地毯。

LONG);

  set("exits", ([
        "east"   : __DIR__"yuhua",
        "north"   : __DIR__"hou2",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


