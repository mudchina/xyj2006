// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "茅屋");
  set ("long", @LONG

一座如仙庵一般的茅屋在眼前，茅屋前有一拱门。透过拱门可
以看见里面如庄园一般，静悄悄。再往里看有一个木亭子。茅
屋外东南面是一座石桥。

LONG);

  set("exits", ([
        "west"    : __DIR__"muxiang",
        "southeast"    : __DIR__"shiqiao",
      ]));
  setup();
}

