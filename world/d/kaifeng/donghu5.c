//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "东湖路");
  set ("long", @LONG

东湖边一条小路弯弯曲曲蜿蜒盘绕，湖水清澈透明，湖岸上杨柳排排
成荫。风吹过时，湖水荡漾杨柳细枝微拂，湖面山影倒印，岸边百鸟
齐鸣令人陶醉。

LONG);

  set("exits", ([
        "northwest" : __DIR__"donghu2",
        "southeast" : __DIR__"donghu7",
      ]));

  set("outdoors", __DIR__);

  setup();
}


