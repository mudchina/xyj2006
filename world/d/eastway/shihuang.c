// create by snowcat.c 4/20/1997
// room: /d/eastway/shihuang.c

inherit ROOM;

void create ()
{
  set ("short", "始皇陵");
  set ("long", @LONG

这是座落在官道以东的一个大丘陵，呈覆斗型。站在丘陵
上极目远眺，不禁心旷神怡。旁边有一座高大的石碑：
“秦始皇陵”。

LONG);

  set("exits", ([
        "east"       : __DIR__"bingma",
        "west"       : __DIR__"guandao3",
      ]));
  set("objects", ([ /* sizeof() == 2 */
         __DIR__"npc/wujiang" : 2,
         __DIR__"npc/bing" : 3,
      ]));

  set("outdoors", __DIR__);

  setup();
}






