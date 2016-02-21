// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/dong.c

inherit ROOM;

void create ()
{
  set ("short", "东场");
  set ("long", @LONG

东场在皇宫的东南边，由大块石头东西向三排铺成。往西是相邻
的中场，向北伸首可以见到高大的殿阁。这里路人不多且行色匆
匆，不敢随便久留。

LONG);

  set("exits", ([
        "east"         : __DIR__"jieshi7",
        "west"         : __DIR__"zhong",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

