// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/wuqidian.c

inherit ROOM;

void create ()
{
        set ("short", "兵器铺");
        set ("long", @LONG

虽是山间小店，但兵器种类却着实齐全。出门在外的人都
愿意来这里买一些趁手的家伙防身。店老板正忙着把新送
来的武器装入仓库。见你进来只是招呼一声，并没有放下
手中的活。

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ 
                "east" : __DIR__"tulu4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/wangshan" : 1,
        ]));

	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
