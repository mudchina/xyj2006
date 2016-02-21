//changan city

inherit ROOM;

void create ()
{
        set ("short", "三联书局");
        set ("long", @LONG

这是一家新开张不久的书局。书架上整整齐齐地放着一些手抄的卷轴。
雕板印刷书到了唐朝已日趋成熟，因此这里的书架上也放着不少印制
精美图文并茂的图书。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"baihu-w1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/bookseller" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


