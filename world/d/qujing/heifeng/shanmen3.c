//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shanmen.c

inherit ROOM;

void create ()
{
  set ("short", "三山门");
  set ("long", @LONG

走到这里，树立在你面前的是一个牌坊，牌坊是用白色石头堆砌而成，
十分的雄壮，前面是登上山上寺院的山道。
LONG);

  set("exits", ([
        "westup"  : __DIR__"shandao",
        "east"  : __DIR__"shanlu4",
        "southeast" : __DIR__"road1",
      ]));
  set("outdoors","hf");
  setup();

}
