// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/simen.c

inherit ROOM;

void create ()
{
  set ("short", "寺门");
  set ("long", @LONG

山前有一座破旧的寺庙，已经退色的门半掩半开，落满了蛛网灰
尘。似乎这里很久已经没有什么香客光临了。门上的大匾隐隐约
约可见“智渊寺”几个金字。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"shanlu4",
        "east"         : __DIR__"jingang",
      ]));

  set("objects", ([
        __DIR__"npc/heshang"    : 2,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

