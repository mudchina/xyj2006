//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "灵山巅");
  set ("long", @LONG

灵山巅无数彩霞飞虹万千条，仙气如雾紫光瑞瑞。四面巧峰排
列，怪石参差，悬崖下瑶草奇花，曲径旁紫芝香蕙，真是个花
草松篁鸾凤鹤鹿之胜地。

LONG);

  set("exits", ([
        "eastdown"   : __DIR__"lingyun1",
        "south"   : __DIR__"siqian",
      ]));
  set("objects", ([
        __DIR__"npc/youpo" : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}



