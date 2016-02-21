// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向天称宫的路上，只见前面可以看到美丽的天称宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的室女宫。
LONG);


        set("exits", ([
        "eastup"    :       __DIR__"tianchen",
            "southdown"  :       __DIR__"sn2tc1",
        ]));

        set("outdoors", "12gong");
        setup();
}
