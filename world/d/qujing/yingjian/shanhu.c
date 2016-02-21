//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/shanhu.c

inherit ROOM;

void create ()
{
  set ("short", "珊瑚丛");
  set ("long", @LONG

这里面尽是些五彩的珊瑚，你的眼睛都看花了。

LONG);

  set("exits", ([
        "up" : __DIR__"jiandi2",
      ]));
      set("objects", ([
        "/d/jz/obj/fish": 3,
        __DIR__"npc/long":1,
        ]));
  setup();

}
