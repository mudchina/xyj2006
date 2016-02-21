inherit ROOM;

void create ()
{
  set ("short", "林道");
  set ("long", @LONG

但见山林锦翠色，到处都是飞禽走兽，给你一种赏心悦目的
感觉。远远看到山凹里面有楼台影影，殿阁沉沉，
LONG);
 
  set("exits", ([
        "eastup"      : __DIR__"lin4",
        "west"   :  __DIR__"lin6",
      ]));

  set("outdoors", __DIR__);

  setup();
}

