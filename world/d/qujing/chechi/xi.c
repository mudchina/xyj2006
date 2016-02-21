// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/xi.c

inherit ROOM;

void create ()
{
  set ("short", "西场");
  set ("long", @LONG

西场用大块石头东西向三排铺成，位于车迟皇宫的西南边，往西
是比较热闹的城区，往东则是中场，从这里往北看，可以见到皇
宫的殿阁。

LONG);

  set("exits", ([
        "west"         : __DIR__"jieshi6",
        "east"         : __DIR__"zhong",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

