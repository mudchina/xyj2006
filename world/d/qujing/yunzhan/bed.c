//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "破床");
  set ("long", @LONG

床上垫了些干草，被褥已经看不清原来的颜色，想那老猪本性
尚此，可高小姐如何在此居住，岂不要遭罪而死。
LONG);

  set("exits", ([
        "south" : __DIR__"in2",
      ]));
  set("objects",([
        __DIR__"npc/lady":1,
        ]));
  set("sleep_room",1);
  setup();
}
