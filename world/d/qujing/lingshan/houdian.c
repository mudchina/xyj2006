//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里仙气冉冉，东西面是金凤银鹤花屏，南边是一排香木玉
窗，窗外有一天院，临窗可见院中翠竹竿竿倒，金莲朵朵摇，
北面是一彩绒殿门。

LONG);

  set("exits", ([
        "north"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/xiantong" : 2,
        "/d/xueshan/npc/kongque":1,
     ]));

  setup();
}

