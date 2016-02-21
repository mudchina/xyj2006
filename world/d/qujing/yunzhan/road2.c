//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road1.c

inherit ROOM;

void create ()
{
  set ("short", "荒路");
  set ("long", @LONG

到了这里，景色变得单调了许多，万籁俱寂，只见一条黄土大道
直通远方，不见尽头，这里没有飞禽走兽，没有游鱼浮草，只有
自己的脚步声，还有身后扬起的漫漫尘土。
LONG);

  set("exits", ([
        "east"  : __DIR__"road1",
        "west"  : __DIR__"road3",
      ]));
  set("outdoors","yz");
  setup();
}
