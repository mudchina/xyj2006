// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向双鱼宫的路上，只见前面可以看到美丽的双鱼宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的宝瓶宫。
LONG);


        set("exits", ([
        "northup"    :       __DIR__"shuangyu",
            "eastdown"  :       __DIR__"bp2sy1",
        ]));

        set("outdoors", "12gong");
        setup();
}
