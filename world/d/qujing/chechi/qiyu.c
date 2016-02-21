// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/qiyu.c

inherit ROOM;

void create ()
{
  set ("short", "祈雨场");
  set ("long", @LONG

场上有一玉池，水波微荡，金莲朵朵在池里争艳。这里是旱季祈
祷龙王降雨的场所，周围彩墙绘有雾峰云海。西边有一五色拱门
通向坛场。

LONG);

  set("exits", ([
        "north"        : __DIR__"leiyu",
        "west"         : __DIR__"tan",
      ]));

  set("objects",([
         __DIR__"npc/jz3" : 1,
         __DIR__"obj/youguo" : 1,
      ]));
  set("outdoors","/d/qujing/chechi");
  setup();
}

