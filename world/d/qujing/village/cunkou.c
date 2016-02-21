//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "村口");
  set ("long", @LONG

你抬头远见一簇松阴，内有几间房舍，着实轩昂，但见：

        门垂翠柏，宅近青山，几株松冉冉，
        数茎竹斑斑，篱边野菊迎霜艳。

LONG);
  set("exits", ([
        "northwest"  : __DIR__"road4",
        "east"  : __DIR__"road3",
        "north" : __DIR__"huanglu1",
      //  "southwest": "/d/
          ]));
  set("outdoors","cz");
  setup();
}
