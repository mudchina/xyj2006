//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

石崖高万丈，山大接青霄，根连地厚，峰插山高。两边杂树数千棵
，前后藤缠百余里。花映草梢风有影，水流云窦月五根。倒木横担
山涧，枯藤接挂光峰。

LONG);

  set("exits", ([
        "southwest"     : __DIR__"shanlu7",
        "north"     : __DIR__"shanlu5",
      ]));
  set("outdoors",1);
  setup();
}
