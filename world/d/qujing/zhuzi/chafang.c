// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "茶房");
  set ("long", @LONG

茶房是朱紫国的闲人杂聚的场所，里面一字排开一些木桌木椅。茶
客们一边品茶，一边绘声绘色交头接耳，人声鼎沸。北边的门通向
北霞街，南边的门通向夕林街。

LONG);

  set("exits", ([ 
    "south" : __DIR__"xi3",
    "north" : __DIR__"beixia2",
  ]));
  set("objects", ([
    __DIR__"npc/cha" : 1
  ]));
  setup();
}
