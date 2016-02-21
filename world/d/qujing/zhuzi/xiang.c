// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "厢房");
  set ("long", @LONG

厢房干净整齐，房门口有一檀香木太师椅，房里有八仙桌可以备席
设宴，上放有紫茶壶。门边有一砖台红泥小炉，极为雅致，情调非
常怡人。

LONG);

  set("exits", ([ 
    "north" : __DIR__"huitong",
  ]));
  set("objects", ([ 
    "/d/obj/food/chahu" : 1,
  ]));
  set("sleep_room",1);
  setup();
}
