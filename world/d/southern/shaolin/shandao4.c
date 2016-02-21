
inherit ROOM;

void create ()
{
	set ("short", "山道");
	set ("long", @LONG

缓步走向寺前，只见树木森森，荫著一片碑林。石碑(bei)大半已经毁
破，字迹模糊，不知写著什麽。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"northdown" : __DIR__"shandao3",
		"southup" : __DIR__"shandao5",
	]));

        set("item_desc", 
        (["bei" : 
             "太宗为秦王时，带兵讨伐王世充，少林寺和尚投军立功，最著者共一十三人。\n"
           +"其中只昙宗一僧受封为大将军，其馀十二僧不愿为官，唐太宗各赐紫罗袈裟一\n"
           +"袭。\n　　　　特立此碑，以嘉其功。\n", 
        ]));

	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

	setup();
}


