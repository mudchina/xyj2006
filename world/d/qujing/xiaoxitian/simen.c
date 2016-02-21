// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "寺门");
  set ("long", @LONG

山坡之上树林郁郁，有一片开阔地带，一边是山谷另一边是野
林，中间耸立着一座高大的寺院，寺院的门前有一长匾写着：
“小雷音寺”几个大字。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"lindao11",
        "south"   : __DIR__"siyuan",
      ]));
  set("objects", ([
          __DIR__"npc/tong"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



