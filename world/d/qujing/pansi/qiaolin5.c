// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "乔林");
  set ("long", @LONG

山原浩瀚秀丽，树木苍青葱翠，高大的乔木树林一望无际复盖
着大地。林中歪歪斜斜地横着一条光秃秃的小径，径头不知通
向何处。

LONG);

  set("exits", ([
        "northeast"    : __DIR__"qiaolin3",
        "southwest"    : __DIR__"nanpo",
        "southeast"    : __DIR__"qiaolin7",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

