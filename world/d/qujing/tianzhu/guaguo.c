// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "瓜果店");
  set ("long", @LONG

一个青竹棚里，摆了一排排的竹筐，筐子里放着各种新鲜的瓜
果正待出售。不时有路人进进出出光顾瓜果店，买下一些水果
瓜类。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao65",
      ]));
  set("objects", ([
        __DIR__"npc/zhang"   : 1,
      ]));

  setup();
}


