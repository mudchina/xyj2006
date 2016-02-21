// created by snowcat.c 5/23/1997
// room: /d/pantao/ting1.c

inherit ROOM;

void create ()
{
  set ("short", "黄霞亭");
  set ("long", @LONG

只见得霞光耀眼瑞气飘飘，亭内仙花盛开香气缭绕。正中放有
一方皎玉镶金供桌，上有紫芝瑶草。霞亭由四根盘龙柱高高擎
起，周围层层云雾环绕。

LONG);

  set("exits", ([
        "south"     : __DIR__"ting2",
        "southeast" : __DIR__"pan1a",
      ]));

  set("objects", ([
         __DIR__"npc/xiannu1"  : 1,
     ]));

  setup();
}

