//changan city

inherit ROOM;

void create ()
{
        set ("short", "大雄宝殿");
        set ("long", @LONG

正中一座金身大佛盘腿坐在莲花宝座之上，左右是四大天王。一十八
位金刚分列两旁。佛前的供台上是善男信女带来的香烛供品及写下心
愿的香纸，供台下一个小箱，装的是供奉的金银。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"huashengsi",
                "east" : __DIR__"fangzhang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


