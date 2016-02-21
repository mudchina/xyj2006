inherit NPC;


void create()
{
       set_name("花豹怪", ({"yao guai","guaiwu"}));
       set("long", "一只作恶多端的妖怪。\n");
       set("gender", "男性");
       set("age", 100);
       set("attitude", "friendly");
       set("per", 40);
       set("str", 40);
       set("cor", 40);
       set("con", 40);
       set("int", 40);
       set("spi", 40);
       set("cps", 40);
       set("kar", 40);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 10000);
       set("max_force", 5000);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set("daoxing", 2000000);
       set("food", 1000);
       set("water", 1000);

       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 170);
       set_skill("parry", 170);
	set_skill("stick", 150);
	set_skill("sword", 150);
	set_skill("liangyi-sword", 150);
	set_skill("spells", 200);
	set_skill("dao", 180);
	set_skill("puti-zhi", 150);
	set_skill("wuxiangforce", 180);
	set_skill("force", 200);
	set_skill("qianjun-bang", 180);
	set_skill("jindouyun", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(: perform_action, "stick","qiankunnew" :),
                (: perform_action, "stick","pili" :)
        }) );

        set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);
        setup();

        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/sea/obj/dragonstick.c")->wield();
}


void heart_beat() {
       
   if (query("kee")<query("eff_kee")) 
     command("exert recover");
    if (query("sen")<query("eff_sen")) 
     command("exert refresh");
     ::heart_beat();
}


