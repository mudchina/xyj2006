// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "酒楼");
  set ("long", @LONG

酒楼里八仙桌摆了二九一十八张，十分豪华。酒楼临街的窗上
扎满了各色彩灯笼，象是有什么喜宴要在这里举办。酒楼的里
间厨房里飘来一阵烤乳猪的香味。

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie3",
      ]));
  set("objects", ([
        __DIR__"npc/jiubao"  : 1,
      ]));

  setup();
}



