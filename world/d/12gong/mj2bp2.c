// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向宝瓶宫的路上，只见前面可以看到美丽的宝瓶宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的魔羯宫。
LONG);


        set("exits", ([
        "eastup"    :       __DIR__"baoping",
            "southdown"  :       __DIR__"mj2bp1",
        ]));

        set("outdoors", "12gong");
        setup();
}
