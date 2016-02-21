// gate.c

inherit ROOM;

void create()
{
  set ("short", "土路");
  set ("long", @LONG

周围是一片蹈田，一些农夫在田里赶着牲口耕种．西边望去有一座
山，雾气蒙蒙，看不清楚．东边是小镇，也是方圆几十里最为繁华
的地方．镇虽不大，但柴米油盐样样不缺．
LONG);
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"zhyuan",
//"south"
"east" : __DIR__"road2",
"west" : __DIR__"road4",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


