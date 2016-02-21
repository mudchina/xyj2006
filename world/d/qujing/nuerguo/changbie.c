// created by snowcat.c 4/4/1997
// room: /d/nuerguo/changshi.c

inherit ROOM;

void create ()
{
  set ("short", "长别亭");
  set ("long", @LONG

在山腰的平地上，修了一座亭子，向东南方向的西梁城镇眺
望。亭上有一小匾写道：长别亭。西北方向有一条小路，通
向西域境外。


LONG);

  set("exits", ([
        "northwest" : __DIR__"end",
        "eastdown"  : __DIR__"shanpo",
        "southdown" : __DIR__"xiaolu4",
      ]));

  setup();
}






