//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "二门");
  set ("long", @LONG

第二大殿门也是一对巨大的檀香银皮木门，门边是橙色仙鸾戏
水画屏。殿的左右各有一个丈许高白银佛鼎，北面是雷音古寺
一门，东西为侧殿，南边是第三道大殿门。

LONG);

  set("exits", ([
        "north"   : __DIR__"yimen",
        "south"   : __DIR__"sanmen",
        "west"   : __DIR__"sidian23",
        "east"   : __DIR__"sidian25",
      ]));
  set("objects", ([
        __DIR__"npc/jingang" : 4,
     ]));

  setup();
}


