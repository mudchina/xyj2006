// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "私塾");
  set ("long", @LONG

明亮的堂屋里，放着一书案，上面插着一根计时用的燃香。案
头堆了一些书简，放了一把铜戒尺。私塾的北墙有一窗口望出
去可见幽幽的青山。

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao18",
      ]));
  set("objects", ([
        __DIR__"npc/yuan"   : 1,
        __DIR__"npc/kid"   : 3,
      ]));

  setup();
}


