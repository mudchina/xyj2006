//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "马场");
  set ("long", @LONG

马场里面宽大，场子的四周搭起了一排长长的马棚，棚里是各种各样
的马。马前放着食槽，槽里堆着切好的新鲜草料。马场的北边有门通
向大街上。

LONG);

  set("exits", ([
        "north" : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/maguan" : 1,
        __DIR__"npc/horse" : 6,
      ]));

  set("outdoors", __DIR__);

  setup();
}


