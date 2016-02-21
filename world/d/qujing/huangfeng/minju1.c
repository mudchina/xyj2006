// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/minju1.c

inherit ROOM;

void create ()
{
        set ("short", "民居");
        set ("long", @LONG

平凡的村中人家，虽只一桌一椅，却收拾得干净整洁。家里
的大人们都出去劳作了，只有几个小孩留在家中。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"tulu2",
        ]));

        set("objects", 
        ([ //sizeof() == 3
		__DIR__"npc/boykid" : 1,
		__DIR__"npc/girlkid" : 1,
		]));

	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
