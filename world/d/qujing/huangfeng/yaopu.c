// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yaopu.c

inherit ROOM;

void create ()
{
        set ("short", "王记药铺");
        set ("long", @LONG

店里弥漫着浓重的药气，老板正斜靠在长椅上打盹，这里的
药材都是村民从山上采来的。据说有一两位药材极为难得，
加上药铺老板祖上传下的几张素有奇效的药方，小店曾经名
噪一时，近来山中有虎，药材商人来得少了，生意也就清淡
了许多。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 1
                "north" : __DIR__"tulu2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yaoboss" : 1,
                "/d/obj/misc/tables" : 1,
        ]));


	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
