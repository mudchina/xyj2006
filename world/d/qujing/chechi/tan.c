// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/tan.c

inherit ROOM;

void create ()
{
  set ("short", "坛场");
  set ("long", @LONG

无数玉坛一线排开，中间有一黄铜大鼎。风摇青树，瑞草齐生，
生气勃然。左右各有一五色拱门相通，西边是祭水场，东边是祈
雨场。

LONG);

  set("exits", ([
        "south"        : __DIR__"zhaomen",
        "north"        : __DIR__"wufeng",
        "east"         : __DIR__"qiyu",
        "west"         : __DIR__"jishui",
      ]));

  set("objects",([
       __DIR__"npc/jz2" : 1,
       __DIR__"obj/guizi" : 1,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

