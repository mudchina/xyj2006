// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "帽店");
  set ("long", @LONG

这是一家专门卖帽的店铺，门外挑了一个四方灯笼，灯笼的四
面都画了个帽子。店铺里设了一水磨铜镜，顾客在买了帽子之
后往往挤在铜镜前戴帽儿照镜子。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao68",
      ]));
  set("objects", ([
        __DIR__"npc/tian"   : 1,
      ]));

  setup();
}


