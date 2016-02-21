// tomcat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("孔雀大明王", ({"kongque mingwang", "kongque", "mingwang", "wang"}));
	set("title",  HIG"佛母孔雀大明王菩萨"NOR);
	set("gender", "男性" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "凤凰之长子，于雪山为如来所擒，困于灵山，武功尽失。");
	set("class", "yaomo");
	set("combat_exp", 5200000);

	set("attitude", "peaceful");
	create_family("大雪山", 1, "祖师");
//	set("rank_info/respect", "佛母");
	set_skill("unarmed", 250);
	set_skill("cuixin-zhang", 250);
        set_skill("dodge", 300);
	set_skill("xiaoyaoyou", 240);
	set_skill("parry", 280);
        set_skill("sword", 270);
        set_skill("bainiao-jian", 280);
	set_skill("blade", 280);
	set_skill("bingpo-blade", 280);
	set_skill("throwing", 300);
        set_skill("force", 290);   
	set_skill("ningxie-force", 280);
        set_skill("literate", 280);
	set_skill("spells", 250);
	set_skill("dengxian-dafa", 250);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 3500);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);


	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="男性"  )
	{
		command("kick " + ob->query("id"));
		command("say 快走，快走！我一看到和尚就有气。\n");
		return;
	}

       if (ob->query("obstacle/number") < 26) {
	command("say 这位" + RANK_D->query_respect(ob) + "拜我为师，要先先历尽取经劫难！\n");
	command("sigh");
	return;
	}
	if( (string)ob->query("family/family_name")=="大雪山" ){
		if( (int)ob->query("family/generation") > 2   ){
			command("say 你不是我弟弟的徒弟，本王不收。\n");
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1000000 ){
				command("nod ");
				command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，将来大有可为！\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say 你还是找到我弟弟吧。\n");
			}
		}
	}

	else{
		command("hmm");
		command("say 这位" + RANK_D->query_respect(ob) + "，在本门可没有一步登天的事。\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
    ob->set("title", HBWHT"孔雀明王座下寒冰使"NOR);
}

void init()
{       
	object ob=this_player();

	::init();
	if ( ((string)ob->query("gender")=="男性") && ((string)ob->query("class")=="bonze") && (random(3) > 1) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	switch( random(1) ) {
		case 0:
			command("kick " + ob->query("id"));
			command("say 死贼秃！");
			break;
	}
}


