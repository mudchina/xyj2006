
inherit ROOM;

void create ()
{
	set ("short", "道旁");
	set ("long", @LONG

折而向西，过了一岭，只见古柏三百余章，皆挺直端秀，凌霄托根树旁，
作花柏顶，灿若云荼。路旁有一口水井(jing)。
LONG);

        set("item_desc", 
        (["jing" : 
            "探头井口向下望去，只见井水清澈，并无特异之处。\n", 
        ]));

	set("exits", 
	([ //sizeof() == 4
		"east" : __DIR__"shandao5",
	]));
	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

        set("resource", ([ /* sizeof() == 1 */
         "water" : 1,
         ]));


	setup();
}


