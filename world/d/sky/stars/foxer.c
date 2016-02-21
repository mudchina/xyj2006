
//note: this is created from player data.
//foxer.c
inherit NPC;

void create()
{
	set_name("阿绣", ({"foxer"}));
	set("long",
"西王母座下杰出弟子。有功夫，有才气，人又长得漂亮，天上地下都吃得开。\n");
	set("title", "心月星官");
	set("gender", "女性");
	set("age", 20);
	set("class", "xian");
	set("attitude", "friendly");
	set("per", 22);
	set("max_kee", 1123);
	set("max_gin", 200);
	set("max_sen", 1381);
	set("force", 4346);
	set("max_force", 2173);
	set("force_factor", 133);
	set("mana", 4286);
	set("max_mana", 2143);
	set("mana_factor", 108);
	set("combat_exp", 1162000);
	set("env/no_teach", 1);

	set("eff_dx", 800000);
	set("nkgain", 800);

	set_skill("baguazhou", 102);
	set_skill("baihua-zhang", 204);
	set_skill("bingpo-blade", 22);
	set_skill("blade", 22);
	set_skill("buddhism", 42);
	set_skill("dodge", 76);
	set_skill("force", 201);
	set_skill("hammer", 51);
	set_skill("hellfire-whip", 102);
	set_skill("huntian-hammer", 2);
	set_skill("literate", 142);
	set_skill("moondance", 205);
	set_skill("moonforce", 167);
	set_skill("moonshentong", 131);
	set_skill("ningxie-force", 29);
	set_skill("parry", 143);
	set_skill("qianjun-bang", 102);
	set_skill("snowsword", 218);
	set_skill("spells", 160);
	set_skill("stealing", 102);
	set_skill("sword", 82);
	set_skill("tonsillit", 11);
	set_skill("unarmed", 141);
//	set_skill("xuanhu-blade", 202);
	set_skill("yaofa", 19);

	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
//	map_skill("blade", "xuanhu-blade");

	create_family("月宫", 2, "弟子");
	setup();

	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}

void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="女性"))
	{	
		if( (string)ob->query("id") != "ppl" )
		{
			command("say 哼！\n");
			return;
		}
		else //note here, "ppl" is "foxer"'s husband.
		{
			command("jump " + ob->query("id") );
			command("recruit " + ob->query("id") );
		}
	}

	command("pat "+ob->query("id"));
	command("say 我还没准备收徒呢。\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) ob->set("class", "xian");
}


