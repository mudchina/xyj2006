// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "光禄寺");
  set ("long", @LONG

光禄寺红墙青瓦，自街上看去十分醒目。寺里从里到外装修一
新，朱漆门彩绘塑象亮铜香炉。一个雕花香案上放着一副新的
木鱼木锤，地上的铺着绣花葡团。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao38",
      ]));

  setup();
}


