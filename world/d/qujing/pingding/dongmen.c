// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "洞门");
  set ("long", @LONG

洞门里有山涧流过，山涧之上有一石栏曲桥，一头通向洞外，
另一头在洞里连向高处。高处有几个大小不同的通道，分别导
向洞的纵深地带。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"dongwai",
        "northeast"   : __DIR__"beidong",
        "south"   : __DIR__"nandong",
        "east"   : __DIR__"qianting",
      ]));
  set("objects", ([
        __DIR__"npc/hu"   : 1,
        __DIR__"npc/long"   : 1,
      ]));

  setup();
}



