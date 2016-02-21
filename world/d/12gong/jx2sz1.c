// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向狮子宫的路上，只见前面可以看到美丽的狮子宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的巨蟹宫。
LONG);


        set("exits", ([
        "southup"    :       __DIR__"jx2sz2",
            "westdown"  :       __DIR__"juxie",
        ]));

        set("outdoors", "12gong");
        setup();
}
