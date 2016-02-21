// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里古色古香，东有一排莲花窗，南有一个宽大的软榻，铺
了一床锦花被。北面有一桌子和一张椅子。西边的门直通大雄
宝殿。

LONG);

  set("exits", ([
        "west"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/tong"   : 3,
      ]));
  set("sleep_room",1);
  set("if_bed",1);

  setup();
}



