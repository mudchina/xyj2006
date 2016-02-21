// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "洞外");
  set ("long", @LONG

山顶上一片广场，但见那狼牙般的岩崖下有一洞口，阴森森不
知是什么去处。洞外边山壁上长满了苔衣，四处陡峭，好象看
不到路的迹象。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"hukou",
      ]));
  set("outdoors", __DIR__);

  setup();
}



