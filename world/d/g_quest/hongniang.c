// hongniang.c

inherit NPC;
#include <ansi.h>
#include <quest.h>
void create()
{
        set_name("ºìÄï", ({ "hong niang","hong" }) );
        set("title", "ºìÄï×¯");
        set("gender", "Å®ÐÔ" );
        set("age", 16);
        
	set("quest_type", "dancer");
        set("inquiry", ([
		"yaoqin": (: give_quest:),
		"ÑþÇÙ": (: give_quest:),
        ]));

        setup();
        add_money("gold", 10);
//        carry_object("/clone/misc/cloth")->wear();
}
