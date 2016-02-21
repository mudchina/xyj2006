// kefang.c
inherit ROOM;
void create()
{
        set("short", "客房");
        set("long", @LONG

    房里干干净净的，供客人休息。一排竹板大床，已经被磨得发黄
了。屋角里摆着个炉子，以备冬天取暖。

LONG
        );

        set("sleep_room",1);
        set("if_bed",1);
        set("exits", ([
                "north" : __DIR__"shop",
	]));
        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}
