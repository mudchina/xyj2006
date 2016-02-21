// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "北霞街");
  set ("long", @LONG

北霞街是城北一条东西向的大道，街面宽敞，相传朱紫老国王托梦
神游城北夜见霞光万道，果然金圣娘娘怀胎生下太子，故将此街命
名为北霞街以示吉祥。南边有一茶房的招牌。

LONG);

  set("exits", ([ 
    "west" : __DIR__"beixia1",
    "east" : __DIR__"beixia3",
    "south" : __DIR__"chafang",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
