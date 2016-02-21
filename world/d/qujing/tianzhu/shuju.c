// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "书局");
  set ("long", @LONG

这里是书局，大堂里摆了一排排的书柜，上面有书简线装经书
羊皮书。堂后有一个紫花屏风，几个瓷花盆里种着几棵奇花异
草，书局的主人不知在何处。

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao53",
      ]));

  setup();
}


