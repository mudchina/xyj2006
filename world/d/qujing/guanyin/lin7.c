inherit ROOM;

void create ()
{
  set ("short", "林道");
  set ("long", @LONG

但见山林锦翠色，到处都是飞禽走兽，给你一种赏心悦目的
感觉。远远看到山凹里面有楼台影影，殿阁沉沉，
LONG);
 
 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guai" : 2,
        ]));
  set("exits", ([
        "east"      : __DIR__"lin6",
        "westup"   :  __DIR__"shanmen",
          "northwest" : __DIR__"shandao1",
        "south" : __DIR__"lin8",
      ]));

  set("outdoors", __DIR__);

  setup();
}

