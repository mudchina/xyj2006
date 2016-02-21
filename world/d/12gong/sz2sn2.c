// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向室女宫的路上，只见前面可以看到美丽的室女宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的狮子宫。
LONG);


        set("exits", ([
        "southup"    :       __DIR__"shinu",
            "westdown"  :       __DIR__"sz2sn1",
        ]));

        set("outdoors", "12gong");
        setup();
}
