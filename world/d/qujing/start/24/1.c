//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("À×Éñ", ({"lei shen", "shen", "lei"}));
       	set("gender", "ÄÐÐÔ");
       	set("age", 40);
        set("class", "taoist");
       	set("attitude", "friendly");
       	set("rank_info/respect", "À×¹«");
        set("per", 26);
        set("looking", "¼âÍ·Í»×ì£¬ÑÛÔ²¾¦³à£¬ÉíÓÐË«Òí£¬ÐÎÈÝ¹Å¹Ö¡£");
        set("int", 30);
       	set("max_kee", 1000);
       	set("max_gin", 1000);
       	set("max_sen", 1000);
       	set("force", 2000);
       	set("max_force", 2000);
       	set("force_factor", 80);
       	set("max_mana", 2000);
       	set("mana", 2000);
       	set("mana_factor", 80);
       	set("combat_exp", 1000000);
        set("daoxing", 1000000);

       	set_skill("dodge", 150);
       	set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("lunhui-zhang", 150);
        set_skill("spells", 150);
        set_skill("dao", 150);
        set_skill("lingfu-steps", 150);
        map_skill("spells", "dao");
        map_skill("parry", "lunhui-zhang");
        map_skill("dodge", "lingfu-steps");
        map_skill("staff", "lunhui-zhang");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "thunder" :)
        }) );

	setup();
        carry_object("/d/qujing/start/obj/leigongzhui")->wield();
	carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void init()
{
	object who=this_player();

	call_out("start", 1, who);
	call_out("check", 1, who);
}

int start(object who)
{
	if( !who ) return;
	if( !who->query_temp("qujing_24") ) return;

	this_object()->fight_ob(who);
	who->fight_ob(this_object());

	return 1;
}

int check(object who)
{
	int mysen, mykee, tasen, takee;

	mysen=this_object()->query("eff_sen");
	mykee=this_object()->query("eff_kee");
	tasen=who->query("eff_sen");
	takee=who->query("eff_kee");

	if( mysen < this_object()->query("max_sen")/10
	|| mykee < this_object()->query("max_kee")/10 ) {
		stop_fight(who);
		call_out("won", 1, who);
	}
	
	if( tasen < who->query("max_sen")/10
	|| takee < who->query("max_kee")/10 ) {
		stop_fight(who);
		call_out("lost", 1 who);
	}

	return 1;
}

int stop_fight(object who)
{
	who->remove_all_killer();
	this_object()->remove_all_killer();
//	message_vision();
	return 1;
}

int won(object who)
{
	
}

int lost(object who)
{

}

