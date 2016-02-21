// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

你抬头看见雅典娜神庙在阳光发出金色的光芒，禁不住虔诚地向雅典
娜女神祷告！再回头时发现十二宫已经隐没在云海之中。

LONG);


        set("exits", ([
        "northup"    :       __DIR__"topalace2",
            "south"  :       __DIR__"shuangyu",
        ]));

        set("outdoors", "12gong");
        setup();
}
