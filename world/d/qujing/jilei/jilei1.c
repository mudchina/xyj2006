//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "积雷山");
  set ("long", @LONG

万丈山崖如刀削一般，群峰峦奇形怪状似犬牙交错。山凹里弥
漫着一股股浓烈的缥缈雾气，阴风呼啸，空谷回音。野兽的吼
叫声已经很近了。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shan11",
        "southwest"   : __DIR__"jilei2",
        "southeast"   : __DIR__"jilei3",
      ]));
  set("outdoors", __DIR__);

  setup();
}



