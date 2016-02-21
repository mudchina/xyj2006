//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "一门");
  set ("long", @LONG

大殿门口乃是一对巨大的檀香木门，门边有朱色霓虹双鹤飞天
玉台柱。殿两侧各有一个紫雕玉玛瑙纹佛鼎，北面是宽敞的寺
前大广场，东西为侧殿，南边又是一道大殿门。

LONG);

  set("exits", ([
        "north"   : __DIR__"siqian",
        "south"   : __DIR__"ermen",
        "west"   : __DIR__"sidian13",
        "east"   : __DIR__"sidian15",
      ]));
  set("objects", ([
        __DIR__"npc/biqiu" : 2,
     ]));

  setup();
}

