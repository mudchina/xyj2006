// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jingang.c

inherit ROOM;

void create ()
{
  set ("short", "金刚殿");
  set ("long", @LONG

金刚殿里残破不堪，光线十分阴暗。几个泥胎已经因为年久失修
颜色早就脱落了，台上放着旧香鼎，有气无力地燃着佛香。往东
是正殿，东南方向有一通道。

LONG);

  set("exits", ([
        "west"          : __DIR__"simen",
        "east"          : __DIR__"zheng",
        "north"         : __DIR__"beiyuan",
        "southeast"     : __DIR__"damo",
      ]));

  setup();
}

