// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向天蝎宫的路上，只见前面可以看到美丽的天蝎宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的天称宫。
LONG);


        set("exits", ([
        "northup"    :       __DIR__"tianxie",
            "eastdown"  :       __DIR__"tc2tx1",
        ]));

        set("outdoors", "12gong");
        setup();
}
