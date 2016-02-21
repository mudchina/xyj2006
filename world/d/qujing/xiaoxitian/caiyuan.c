// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "菜园");
  set ("long", @LONG

菜园里的地新翻过，种着各种蔬菜瓜果，菜园的边上种着一片
果树，树上垂下青皮果子。菜园的东北是大寺院，南边有一座
石房。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"siyuan",
        "south"   : __DIR__"chanfang",
      ]));
  set("outdoors", __DIR__);

  setup();
}



