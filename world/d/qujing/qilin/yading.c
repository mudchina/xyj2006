// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "崖顶");
  set ("long", @LONG

这里是山坳处一略凸起的崖坡，四处可听见山禽声咽咽，山兽吼呼
呼。然而脚下则如火焚过一般红焦一片，不远处有一小坡，坡上满
是流沙。

LONG);

  set("exits", ([ 
    "westup" : __DIR__"dongkou",
    "southeast" : __DIR__"shankou",
  ]));
  set("outdoors", __DIR__"");
  setup();
}

