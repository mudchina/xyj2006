//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/kitchen.c

inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

猎户人家整年都是吃肉，所以厨房里面到处挂的都是腌好的肉，
到了冬天大雪封山，猎户人家就是靠这些腌肉、腌菜过洞的。

LONG);

  set("exits", ([
        "south" : __DIR__"yard",
      ]));
  set("objects",([
        __DIR__"obj/rou" : 3,
        ]));
  setup();

}
