// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向人马宫的路上，只见前面可以看到美丽的人马宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的天蝎宫。
LONG);


        set("exits", ([
        "westup"    :       __DIR__"renma",
            "northdown"  :       __DIR__"tx2rm1",
        ]));

        set("outdoors", "12gong");
        setup();
}
