//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

走到这，你就觉得洞里特别的凌乱，地上堆着些不干不净的杂
草，还有些骚臭味传出来，还有一张破床摆在前面，整个洞显
得特别的低矮，你的头一不小心就撞到洞顶伸出的石头。
LONG);

  set("exits", ([
        "south"  : __DIR__"in1",
         "west"  : __DIR__"piandong",
        "east"  : __DIR__"xiaolu1",
        "north" : __DIR__"bed",
      ]));
  setup();
}
