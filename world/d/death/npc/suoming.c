inherit NPC;

void create()
{
       set_name("Ë÷Ãü¹í", ({"suoming gui", "gui"}));
       set("gender", "ÄĞĞÔ");
       set("age", 30);
	set("long", "Ò»¸öÇàÃæâ²ÑÀµÄĞ¡¹í£¬Éí´©ÊŞÆ¤£¬ÊÖ³ÖÌúÁ´£®
ËûµÄÈÎÎñ¾ÍÊÇ´ÓÑô¼ä½«ËÀÈËµÄ»êÆÇ´ø»Ø£®\n");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 60000+random(30000));
  set("daoxing", 30000);

	set("bellicosity", 300);
	set_skill("unarmed", 65);
	set_skill("dodge", 65);
	set_skill("whip", 65);
	set_skill("parry", 45);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 15);
	set("max_kee", 450);
set("inquiry", ([
"here": "Õâ¾ÍÊÇÒõ²ÜµØ¸®£¬ºß£¬µÈ×Å°şÆ¤³é½î°ÉÄã£¡\n",
]) );

set("chat_chance", 8);
set("chat_msg", ({
"Ë÷Ãü¹íµÄÉÏÉÏÏÂÏÂ´òÁ¿ÁËÄã¼¸ÑÛ¡£\n",
"Ë÷Ãü¹íËµµÀ£ºÑÖÍõ½ĞÄãÈı¸üËÀ£¬²»¸ÒÁôÄãµ½Îå¸ü£¡\n",
(: random_move :)
}) );

setup();

        carry_object("/d/obj/cloth/shoupi")->wear();
        carry_object("/d/obj/weapon/whip/tielian")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
	
	if ((string)ob->query("family/family_name")!="ÑÖÂŞµØ¸®") {
	if (random((int)ob->query("age")) > 20 ){
	command("tell " + ob->query("id") + " ÑÖÍõÒ¯½ĞÎÒÀ´¹´ÄãµÄ»ê£¬ÄãÈ´×Ô¼ºËÍÉÏÃÅÀ´£¬¸úÎÒ×ß°É£¡\n");
	kill_ob(ob);
	set_leader(ob);
	return;
	}
	return;
	}
return;
}
return;
}

int accept_fight(object me)
{
        command("say Äã»îµÃ²»ÄÍ·³ÁË£¿\n");
        kill_ob(me);
        return 1;
}

ÿ