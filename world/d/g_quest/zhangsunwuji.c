//zhangsun wuji

inherit NPC;
#include <ansi.h>
#include <quest.h>

void create()
{
	set_name("长孙无忌", ({"zhangsun wuji", "wuji"}));
	set("title", "户部尚书");
	set("age", 50);
	set("per", 28);

	set("quest_type", "captor");
        set("inquiry", ([
		"公文" : (: give_quest :),
		"gongwen" : (: give_quest :),
	]));	

	setup();
	carry_object("/d/gao/obj/changpao")->wear();
}