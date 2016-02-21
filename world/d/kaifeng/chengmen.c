//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "开封城门");
  set ("long", @LONG

一座高高的青垒石墙城楼耸立，城门上旌旗招展。城下是一条宽宽的
大道从门洞里穿过，往东就是城里，大道西边通向远方。门两边站立
着一些兵士，警察地护卫着开封城。

LONG);

  set("exits", ([
        "west" : __DIR__"east5",
        "east" : __DIR__"chen1",
      ]));

  set("objects", 
      ([
         __DIR__"npc/wujiang" : 1,
         __DIR__"npc/bing" : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}


