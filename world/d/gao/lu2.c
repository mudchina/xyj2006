// gate.c

inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG

进到镇中人似乎多了些，也有些做小买卖的．青青的石板铺在路
上，延续到镇的另一端．
LONG);
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"zhyuan",
//"south"
"east" : __DIR__"lu1",
"west" :__DIR__"gate",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


