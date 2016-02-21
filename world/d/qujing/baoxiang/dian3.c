// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dian3.c
inherit ROOM;

void create ()
{
  set ("short", "烧香殿");
  set ("long", @LONG

宫殿里紫霓朦胧，瑞气缭绕。墙上雕有龙凤，玲珑剔透欲飞欲
去。地上摆有金盆芝兰香蕙，银桌玉器铺彩结，几位宫女玉簪
珠履静然肃立。

LONG);

  set("exits", ([
        "west"       : __DIR__"yujie3"
      ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}


