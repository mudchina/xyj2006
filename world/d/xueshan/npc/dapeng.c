// dapeng.c...weiqi, 97.09.27.

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("´óÅôÃ÷Íõ", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "Ñ©É½Ö®×æ");
	set("gender", "ÄĞĞÔ" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "ÕâÎ»´óÅôÃ÷ÍõµÄÈ·´óÓĞÀ´Àú£¬ËµÆğÀ´¸ú·ğ×æÈçÀ´Ò²ÓĞµãÇ×Æİ¹ØÏµ£¬\nËãÊÇÈçÀ´µÄ¡°¾Ë¾Ë¡±¡£Ëû²»ËÆÆäĞÖ¿×È¸Ã÷Íõ×÷¶ñ¶à¶Ë£¬È´Ò²²¢·ÇÉÆÀà£¬\nÇÒÒòÆäĞÖÖ®¹Ê¸ú·ğÃÅ½áÏÂÉî³ğ¡£ÉúÆ½×îÌÖÑáµÄ¾ÍÊÇºÍÉĞ¡£\n");
	set("class", "yaomo");
	set("combat_exp", 1800000);
	set("daoxing", 3000000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 1, "×æÊ¦");
	set("rank_info/respect", "Ã÷Íõ");
	set_skill("unarmed", 200);
	set_skill("cuixin-zhang", 200);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("bainiao-jian", 200);
	set_skill("blade", 200);
	set_skill("bingpo-blade", 200);
	set_skill("throwing", 200);
	set_skill("force", 200);   
	set_skill("ningxie-force", 200);
	set_skill("literate", 150);
	set_skill("spells", 200);
	set_skill("dengxian-dafa", 200);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "juanbi" :),
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng" :),

       }) );
            setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="ÄĞĞÔ"  )
	{
		command("kick " + ob->query("id"));
		command("say ¿ì×ß£¬¿ì×ß£¡ÎÒÒ»¿´µ½ºÍÉĞ¾ÍÓĞÆø¡£\n");
		return;
	}

	if( (string)ob->query("family/family_name")=="´óÑ©É½" ){
		if( (int)ob->query("family/generation") > 3   ){
			command("say Ã»ÓĞËÄ´ó»¤·¨µÄÍÆ¼ö£¬±¾ÍõºÜÄÑ¿¼ÂÇ¡£\n");
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 500000 ){
				command("nod ");
				command("say ºÃ£¬" + RANK_D->query_respect(ob) + "ºÃºÃ¸úÎÒ¸É£¬½«À´´óÓĞ¿ÉÎª£¡\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say Äã»¹ÊÇÕÒÇàÊ¨£¬°×ÏóËûÃÇÏÈÁ·×Å°É¡£\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "£¬ÔÚ±¾ÃÅ¿ÉÃ»ÓĞÒ»²½µÇÌìµÄÊÂ¡£\n");
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
	if ( ((string)ob->query("gender")=="ÄĞĞÔ") && ((string)ob->query("class")=="bonze") && (random(3) > 1) )
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
			command("say ËÀÔôÍº£¡");
			break;
	}
}

ÿ
