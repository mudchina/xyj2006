// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "药铺");
  set ("long", @LONG

药铺三面是药柜，柜上是大大小小的铜把抽屉，上面整整齐齐
地贴有药签。一张杜松木桌放在屋中间，摆着几只瓷药盅和红
泥药罐子。

LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao5",
      ]));
  set("objects", ([
        __DIR__"npc/zheng"    : 1,
      ]));
  setup();
}

