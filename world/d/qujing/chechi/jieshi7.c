// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jieshi7.c

inherit ROOM;

void create ()
{
  set ("short", "街市");
  set ("long", @LONG

拥挤的车迟国街市，由碎砖石铺成。人声鼎沸，街景秀丽，令人
目不暇己。两边有不少行人来回匆匆走过。偶尔有些小贩沿途边
走叫边卖着什么。

LONG);

  set("exits", ([
        "west"         : __DIR__"dong",
        "north"        : __DIR__"ruizhao",
        "south"        : __DIR__"jieshi9",
      ]));

  set("objects", ([
        __DIR__"npc/people" : 2,
  ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

