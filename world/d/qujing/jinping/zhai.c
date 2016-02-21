// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "斋房");
  set ("long", @LONG

斋房不是很大，墙角砌了一大灶台，屋外烧火屋里烧饭煮菜，
灶里边墙根有一对空木桶，几只空菜箩筐。斋房靠窗处放了张
木桌和两条长凳。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"xiaolu",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 2,
      ]));

  setup();
}



