inherit NPC;

void create()
{
        set_name("Ğ¦²¨¶ùÌì", ({"xiaoboer tian", "tian"}));
        set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄĞ¡Ñı¡£\n");
        set("age", 30);
	set("title", "Çà÷­¹Ö");
        set("attitude", "friendly");
        set("gender", "ÄĞĞÔ");
	set("class", "dragon");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",1000);
        set("max_sen", 1000);
        set("combat_exp", 350000);
  set("daoxing", 450000);

        set("force", 1600);
        set("max_force", 1600);
        set("mana",400);
        set("max_mana", 700);
        set("force_factor", 40);
        set("mana_factor", 20);
        set_skill("unarmed", 120);
        set_skill("force", 120);
        set_skill("spells", 120);
        set_skill("dodge", 120);
	set_skill("fork", 120);
	set_skill("parry", 120);
	set_skill("yueya-chan", 100);
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
set("inquiry", ([
"ºó»¨Ô°": "ÌıËµÕâºó»¨Ô°ÊÇ¸ö°ËØÔÕó£¬²»ÖªµÀ·½Î»µÄ£¬ºÙºÙ£®£®£®\n",
]) );

        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
	if( random(5) > 3  ) {
        if (objectp(present("xiao", environment(this_object())))) {
                switch( random(6) ){
                        case 0:
                                command("say Ìì²¨¶ùĞ¦£¬±ğÓÖË¯×ÅÁË£¡");
                                command("wake xiao");
                        break;
                        case 1:
                                command("say Ìì²¨¶ùĞ¦£¬ÌıËµÁúÍõÓÖÉÍÄãÁË¡£");
                                command("consider xiao");
                        break;
                        case 2:
                                command("say Ìì²¨¶ùĞ¦£¬ÏëÂïÄØ£¿");
                                command("poke xiao");
                        break;
                        case 3:
                                command("say Ìì²¨¶ùĞ¦£¬ÉÏÔÂÀ´µÄÄÇ¸öĞ¡¹¬¶ğ»¹ÕæÆ¯ÁÁ£¡");
                                command("grin xiao");
                        break;
                        case 4:
                                command("say Ìì²¨¶ùĞ¦£¬¿´ºÃÁËÃÅ£¬±ğÈÃÈËÁï½øÈ¥£¡");
                                command("kick xiao");
                        break; 
			case 5:
				command("say Ìì²¨¶ùĞ¦£¬¿ìÈ¥Ïò¹«Ö÷ÇëÊ¾·½Î»£¡");
				command("lazy xiao");
			break;
                	}
        	}
        }
	}
        return ::heal_up() + 1;
}

ÿ