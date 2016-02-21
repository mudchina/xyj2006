// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "通道");
  set ("long", @LONG

通道由东西向延伸开，洞比较狭窄，洞壁上长着绿色的蔓草，
怪石遍地。东边有三个洞穴入口，不知通向何处，通道的西边
有光线传进。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"wowang1",
        "east"   : __DIR__"wowang2",
        "southeast"   : __DIR__"wowang3",
        "west"   : __DIR__"tongdao1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 1,
      ]));

  setup();
}



