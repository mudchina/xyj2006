// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "民居");
  set ("long", @LONG

这里是一片民居住房，有松板木楼也有石砖青瓦的平房，家家
户户张灯结彩五光十色。有不少大小的五颜六色的彩灯挂在窗
口门前，门口有一个油罐，供送油客灌油之用。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie1",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 1,
        __DIR__"obj/pot"   : 1,
      ]));
  set("has_oil",1);
  set("has_oil_pot",1);
  set("outdoors", __DIR__);

  setup();
}

void regenerate_oil ()
{
  call_out ("regenerating_oil",600);
}

void regenerating_oil ()
{
  this_object()->set("has_oil",1);
}



