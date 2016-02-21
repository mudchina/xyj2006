// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向白羊宫的路上，只见前面可以看到美丽的白羊宫耸立在奥林
匹亚峰上！
LONG);


        set("exits", ([
 "westup"    :       __DIR__"baiyang",
            "northdown"  :       __DIR__"toby1",
        ]));

        set("outdoors", "12gong");
        setup();
}
