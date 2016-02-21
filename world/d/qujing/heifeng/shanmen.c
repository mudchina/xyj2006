//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

前面就是寺院，风景如画，整个寺院被山包围着，还有一些花
从寺院的墙上开了出来，也许这就是“一只红杏出墙来”的原
型吧，山门两旁还各摆了个石狮子。
LONG);

  set("exits", ([
        "enter"  : __DIR__"dadian",
        "eastdown"  : __DIR__"shandao5",
        "westdown"  : "/d/qujing/yunzhan/road1",
      ]));
  set("objects",([
        __DIR__"npc/welcome": 1,
                ]));
  set("outdoors","hf");
  setup();

}
