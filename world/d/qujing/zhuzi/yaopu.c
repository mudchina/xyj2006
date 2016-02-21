// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "药铺");
  set ("long", @LONG

药铺门口摊开一些正在晒的草药，铺子里有一丈许的大药柜，装着
各式草药。墙上贴着一匾，上书“免费号脉”四个字。

LONG);

  set("exits", ([ 
    "south" : __DIR__"tian1",
  ]));
  set("objects", ([
    __DIR__"npc/laotong" : 1,
  ]));
  setup();
}
