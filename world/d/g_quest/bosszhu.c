//zhangsun wuji

inherit NPC;
#include <ansi.h>
#include <quest.h>

void create()
{
	set_name("朱老板", ({"boss dachang", "boss"}));
	set("title", "长安巨贾");
	set("age", 40);
	set("per", 15);
	set("long","
朱老板原名猪大肠，当年是长安城两大流氓“左捣乱，右猪肠”
之一。有次被捣乱痛扁后卧床不起，百无聊赖之际读史解闷。读
到刘邦周处等人的故事时，悚然有悟。从此奋发读书，潜心习武，
文不成武不就后，毅然下海从商，终于成就了今天的局面。发迹
改名朱大常，身穿绸袍，俨然衣冠中人。\n");
	

	set("quest_type", "knight");
        set("inquiry", ([
		"密函" : (: give_quest :),
		"mihan": (: give_quest :),
	]));	

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
}