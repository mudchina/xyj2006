// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/gong5.c
inherit ROOM;

void create ()
{
  set ("short", "建章宫");
  set ("long", @LONG

宫殿里紫霓朦胧，瑞气缭绕。墙上雕有龙凤，玲珑剔透欲飞欲
去。地上摆有金盆芝兰香蕙，银桌玉器铺彩结，几位宫女玉簪
珠履静然肃立。

LONG);

  set("exits", ([
        "east"       : __DIR__"yujie5"
      ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}


