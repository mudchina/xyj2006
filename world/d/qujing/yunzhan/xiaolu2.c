//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "洞内小路");
  set ("long", @LONG

洞内只有些简易的小路，你顺着小路向前走去，根本不能
站直行走，否则一不小心就要撞到石头上。
LONG);

  set("exits", ([
        "west"  : __DIR__"xiaolu1",
        "east"  : __DIR__"xiaolu3",
      ]));
  setup();
}
