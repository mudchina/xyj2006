// qingshi-laomo.c...weiqi, 97.09.15.

inherit NPC;
void create()
{
	set_name("ÇàÊ¨ÀÏÄ§", ({"qingshi laomo", "qingshi", "laomo"}));
	set("title", "Ã÷Íõ»¤·¨");
	set("gender", "ÄÐÐÔ" );
	set("age", 63);
	set("per", 112);//no rongmao description.

	set("long", "ÕâÎ»ÇàÊ¨ÀÏÄ§Ô­À´ÔÚÊ¨ÍÕÉ½åÐÒ££¬¸ú´óÅôÃ÷ÍõÆÄÓÐ½»Çé¡£\nºóÀ´Ê¨ÍÕÉ½±»·½´çÉ½ÈýÐÇ¶´µÄÒ»Î»µÃµÀ¸ßÈË½ËÃð£¬\nÀÏÄ§¾ÍÍ¶±¼´óÅôÃ÷Íõ×öÁË»¤·¨×ðÕß¡£Ò»¸ö¸úºÍÉÐÓÐ³ð£¬\nÒ»¸ö¸úµÀÊ¿ÓÐ³ð£¬Ò²ËãÊÇÖª½»ºÃÓÑ¡£\n");
	set("class", "yaomo");
	set("combat_exp", 800000);
	set("daoxing", 1000000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 2, "µÜ×Ó");
	set_skill("unarmed", 150);
	set_skill("cuixin-zhang", 80);
	set_skill("dodge", 90);
	set_skill("xiaoyaoyou", 100);
	set_skill("parry", 70);
	set_skill("blade", 120);
	set_skill("bingpo-blade", 110);
	set_skill("force", 90);   
	set_skill("ningxie-force", 90);
	set_skill("literate", 70);
	set_skill("spells", 90);
	set_skill("dengxian-dafa", 120);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 60);
	set("mana_factor", 25);

	set("eff_dx", -200000);
	set("nkgain", 400);

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="´óÑ©É½" ){
		if( (int)ob->query("family/generation") < 2  ){
			command("say ²»¸Ò£¬²»¸Ò¡£ÎÒ¸Ã°Ý" + RANK_D->query_respect(ob) + "ÄúÎªÊ¦²ÅÊÇ¡£\n");
		}
		else if( (int)ob->query("family/generation") ==2  ){
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "±ðÀ´ÏûÇ²ÄãÒ¯Ò¯ÎÒÁË£¡\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command(":D");
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "ÀÏ»»Ê¦¸¸¿É²»ºÃ£¡ÄãÊ¦¸¸Ò²²»ÊÇÊ²Ã´¶¼²»¶®Âï...\n");
			command("recruit " + ob->query("id") );
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 200000 ){
				command(":D ");
				command("say ºÃ£¬" + RANK_D->query_respect(ob) + "ºÃºÃ¸úÎÒ¸É£¬ÒÔºóÉ±»ØÊ¨ÍÕÉ½ÎÒÇëÃ÷Íõ·âÄã¸öÑ²É½´ó½«¾ü£¡\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say Äã»¹ÊÇÕÒðÐðÄ£¬ÎÚÑ»ËûÃÇÏÈÁ·×Å°É¡£\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "£¬Ã»ÓÐÍÆ¼öÈËÎÒ¿É²»ÄÜÊÕÄã¡£\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

void init()
{       
	object ob=this_player();

	::init();
	if ( ((string)ob->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") 
		&& ((int)ob->query("combat_exp")  >= 100000) )
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
		command("say ÄãÕâÔôµÀºÃÏó»¹ÓÐÁ½ÊÖ£¬¿É¸Ò¸úÄãÒ¯Ò¯ÎÒ¶·Ò»¶·£¿");
		command("fight " + ob->query("id"));
		break;
	}
}

ÿ
