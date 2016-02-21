// created by snowcat.c 5/23/1997
// room: /d/pantao/ting3.c

inherit ROOM;

void create ()
{
  set ("short", "绿霞亭");
  set ("long", @LONG

只见得霞光耀眼瑞气飘飘，亭内仙花盛开香气缭绕。正中放有
一方皎玉镶金供桌，上有紫芝瑶草。霞亭由四根盘龙柱高高擎
起，周围层层云雾环绕。

LONG);

  set("exits", ([
        "north"     : __DIR__"ting2",
        "south"     : __DIR__"ting4",
        "northeast" : __DIR__"pan1a",
        "southeast" : __DIR__"pan2a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu3"  : 1,
     ]));

  setup();
}

