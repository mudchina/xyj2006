// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向双子宫的路上，只见前面可以看到美丽的双子宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的金牛宫。
LONG);


        set("exits", ([
        "northup"    :       __DIR__"jn2sz2",
            "eastdown"  :       __DIR__"jinniu",
        ]));

        set("outdoors", "12gong");
        setup();
}
