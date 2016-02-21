inherit NPC;

void create()
{
        set_name("Ìì²¨¶ùÐ¦", ({"tianboer xiao", "xiao"}));
        set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄÐ¡Ñý¡£\n");
        set("age", 30);
	set("title", "Äàöú¾«");
        set("attitude", "friendly");
        set("gender", "ÄÐÐÔ");
	set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",1200);
        set("max_sen", 1000);
        set("combat_exp", 400000);
  set("daoxing", 500000);

        set("force", 1200);
        set("max_force", 1200);
        set("mana",400);
        set("max_mana", 700);
        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("spells", 120);
        set_skill("dodge", 120);
	set_skill("whip", 120);
	set_skill("hellfire-whip", 100);
	set_skill("parry", 120);
	map_skill("whip", "hellfire-whip");
	map_skill("parry", "hellfire-whip");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/whip/tielian")->wield();
}
void relay_emote(object ob,string verb)
{
	if( ob->query("name")!="Ð¦²¨¶ùÌì" ) return;
        switch(verb) {
        case "kick":
                        command("say ¹·ÍÈÓÖ·¢Ñ÷ÁË...\n");
                break;
        case "wake":
                        command("wake");
		break;
        case "poke":  
                        command("poke xiao");                                        
                break;
        case "consider":  
                        command("poor tian");                                        
                break;
        case "grin":  
                        command("hehe tian");                                        
                break;
	case "lazy":
			command("lazy xiao");
		break;
        }
}

ÿ