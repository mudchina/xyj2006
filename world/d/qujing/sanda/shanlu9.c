//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

石桥下，流滚滚清泉，台座上，长明明白粉。远观一似三岛天堂，
近看犹如蓬莱仙境。香松紫竹绕山溪，鸦雀猿猴穿峻岭，路上时常
有走兽出现，或有飞禽坐伴。

LONG);

  set("exits", ([
        "south"     : __DIR__"shanlu10",
        "north"     : __DIR__"shanlu8",
      ]));
  set("outdoors",1);
  setup();
}
