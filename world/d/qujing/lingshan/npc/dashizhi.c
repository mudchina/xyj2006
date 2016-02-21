//created by greenwc
//created by greenwc
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("大势至菩萨", ({"dashizhi pusa", "dashizhi", "dashi", "pusa"}));
  set ("long", @LONG
南无阿弥陀佛次徒，观世音菩萨的师弟，三
人并称西方三神。
LONG);
  set("title", "西方三神之");
  set("gender", "男性");
  set("age", 400);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
       set_skill("literate", 150);
	set_skill("spells", 180);
	set_skill("buddhism", 180);
	set_skill("unarmed", 160);
	set_skill("jienan-zhi", 160);
	set_skill("dodge", 150);
	set_skill("lotusmove", 170);
	set_skill("parry", 150);
	set_skill("force", 180);
	set_skill("lotusforce", 180);
	set_skill("hammer", 180);
	set_skill("bighammer", 180);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "bighammer");
	map_skill("hammer", "bighammer");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
                      	(: perform_action, "hammer", "dashi" :),
	}) );
           set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2000000);
	set("daoxing", 10000000);

	create_family("南海普陀山", 1, "菩萨");
  setup();

	carry_object("/d/obj/weapon/hammer/falun2")->wield();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

int accept_fight(object me)
{
  command("say 施主玩笑了\n");
return 0;
}

int attempt_apprentice(object ob)
{
	string myname=RANK_D->query_respect(ob);
            if (!((string)ob->query("bonze/class") =="bonze" )) {
		command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
return 0;
}
if ((int)ob->query_skill("buddhism")< 100) 
{
      command("say 施主对佛法的研究还不够精深！");
return 0;
}
	command("pat " + ob->query("id") );
	command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");
	command("recruit " + ob->query("id") );
	return;	
}

void die()
{
        if( environment() ) {
        message("sound", "\n\n大势至菩萨摇头叹道：冤孽！真是冤孽！n\n", environment());
        command("sigh");
        message("sound", "\n大势至菩萨驾祥云，登彩雾，径往西方去了。。。\n\n", environment());
}

	destruct(this_object());
}
