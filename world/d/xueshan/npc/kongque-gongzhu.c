// kongque-gongzhu.c...weiqi, 97.09.15.

inherit NPC;

string get_ice(object me);
void do_drop(object ob);

void create()
{
	set_name("¿×È¸¹«Ö÷", ({"kongque gongzhu", "kongque", "gongzhu"}));
	set("title", "Ã÷Íõ»¤·¨");
	set("gender", "Å®ÐÔ" );
	set("age", 23);
	set("per", 21);
set("long", @LONG
ÕâÎ»¿×È¸¹«Ö÷ÊÇ¿×È¸Ã÷ÍõµÄÅ®¶ù¡£¿×È¸Ã÷Íõ±»·ð×æÈçÀ´
ÑºÖÁÁéÉ½ºó£¬ËýÓÉ´óÅôÃ÷ÍõÒ»ÊÖ´ø´ó¡£ËµÊÇÖ¶Å®£¬Óë´ó
ÅôÃ÷ÍõÊµÔòÓÐ¸¸Å®Ö®Çé¡£
LONG );
	set("class", "yaomo");
	set("combat_exp", 800000);
 	set("daoxing", 500000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 2, "µÜ×Ó");
	set_skill("unarmed", 140);
	set_skill("cuixin-zhang", 140);
	set_skill("dodge", 140);
	set_skill("xiaoyaoyou", 140);
	set_skill("parry", 140);
       set_skill("throwing", 140);
	set_skill("sword", 140);
       set_skill("bainiao-jian", 140);
	set_skill("force", 140);   
	set_skill("ningxie-force", 140);
	set_skill("literate", 100);
	set_skill("spells", 140);
	set_skill("dengxian-dafa", 140);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 1000);
	set("max_sen", 600);
	set("force", 3000);
	set("max_force", 1500);
	set("mana", 3000);
	set("max_mana", 1500);	
	set("force_factor", 75);
	set("mana_factor", 76);
       set("eff_dx", -200000);
       set("nkgain", 400);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
            (: perform_action, "sword", "chaofeng" :),
             }) );

            setup();
	carry_object("/d/xueshan/obj/nihong-yuyi")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
       carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/sword/fenghuangqin")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="´óÑ©É½" ){
		if( (int)ob->query("family/generation") < 2  ){
			command("say ²»¸Ò£¬²»¸Ò¡£ÎÒ¸Ã°Ý" + RANK_D->query_respect(ob) + "ÄúÎªÊ¦²ÅÊÇ¡£\n");
		}
		else if( (int)ob->query("family/generation") ==2  ){
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "±ðÀ´ÏûÇ²Äã¼Ò¹ÃÄÌÄÌÎÒÁË£¡\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command("blush ");
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "£¬ÕâÊÇÄã×ÔÔ¸µÄ£¬¿É²»ËãÎÒÍÚÇ½½Ç...\n");
			command("recruit " + ob->query("id") );
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 200000 ){
				command(":) ");
				command("say ºÃ£¬" + RANK_D->query_respect(ob) + "¼ÈÈ»µ½ÎÒÃÅÏÂ¾ÍµÃ¸øÎÒÕùÆø£¬¿É²»ÐíÍµÀÁ£¡\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say Äã»¹ÊÇÕÒðÐðÄ£¬ÎÚÑ»ËûÃÇÏÈÁ·×Å°É¡£\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "£¬Äã»¹ÊÇÕÒðÐðÄ£¬ÎÚÑ»ËûÃÇÏÈÁ·Á·°É¡£\n");
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
	object ob, me;

	me = this_player();

	::init();

	set("chat_chance", 5);
	set("inquiry", ([
		"name" : "²»¸æËßÄã¡£\n",
		"here" : "Äã»¹Ã»ÍêÁË...±ðÔÚÕâ¶ù´ò½Á£¡\n", 
		"´óÅôÍõ" : (: get_ice :),
		"´óÅôÃ÷Íõ" : (: get_ice :),
		"¸¸Íõ" : (: get_ice :),
	 ]) );

	set("chat_msg", ({
		"¿×È¸¹«Ö÷Ì¾ÁË¿ÚÆø¡£\n",	
		"¿×È¸¹«Ö÷×ÔÑÔ×ÔÓïµÀ£ºÒ²²»ÖªµÀ¸¸ÍõµÄ²¡Ê²Ã´Ê±ºòÄÜºÃ¡£\n",
		"¿×È¸¹«Ö÷ÖåÁËÖåÃ¼µÀ£º°´ËµÕâÖÖ²ÝÐÔÅ¯£¬¸¸ÍõÔõÃ´»áÈÏÎª¿ÉÒÔÌáÁ¶º®¶¾ÄØ£¿\n",
		"¿×È¸¹«Ö÷ÓÖÌ¾ÁË¿ÚÆø£º×öÁËÕâÃ´¾Ã»¹²»³É£¬¿Ï¶¨»¹²îµãÊ²Ã´...ÕâÃ´¶à»¨²Ý»ìÀ´»ìÈ¥Ò²Ã»ÓÃÑ½£¿\n",
		"¿×È¸¹«Ö÷×ÔÑÔ×ÔÓïµÀ£º¸¸ÍõÔÙÅª²»µ½º®¶¾£¬¿ÖÅÂ´óÊÂ²»ÃîÁË¡£\n",        
	}) );

	if ( ((string)me->query("gender") == "ÄÐÐÔ") && ((int)me->query("per") > 25) && ((int)me->query("combat_exp") < 10000) && (random(3) >1) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}

}

void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;

	switch( random(1) ) {
		case 0:
			command("say ºÃ¸öÃÀÄÐ×Ó£¡\n");
			command("say ¿ÉÏ§ÊÇ¸öÐå»¨ÕíÍ·...\n");
			command("kick " + me->query("id"));
			break;
	}
}

string get_ice(object me)
{
	object env;

	me = this_player();
	env = environment(this_object());

	if( (me->query_temp("ice_given") || (int)me->query("family/generation")<=2) && (string)env->query("short")=="Ð¡Ä¾ÎÝ" && (string)me->query("family/family_name")=="´óÑ©É½")
	{
		me->delete_temp("ice_given");
		message_vision("¿×È¸¹«Ö÷ÔÚ$N¶ú±ßÇÄÉùËµÁË¼¸¾ä»°¡£\n", me);
		write("¿×È¸¹«Ö÷¸æËßÄãµÀ£º¼ÈÈ»ÄãÏë¼ûËû£¬Õâ¾ÍÈÃÄãÈ¥¡£\n");
		message_vision("Ö»¼û¿×È¸¹«Ö÷ÉìÊÖÔÚ×À×Óµ×ÏÂ°´ÁËÒ»°´¡£\n", me);
		env->open_down();
		return "ÉÏÀ´Ê±ÇÃÒ»ÇÃÇ½¼´¿É¡£\n";
	}
	else
	{
		return "´óÅôÃ÷Íõ¾ÍÊÇÎÒ¸¸Íõ£¬ÎÒ¸¸Íõ¾ÍÊÇ´óÅôÃ÷Íõ¡£\n";
	}
}

int accept_object(object me, object ob)
{
	if ( ((string)ob->query("id") != "lan bingkuai") && 
		((string)ob->query("id") != "shuangse bing") ) 
	{
		command("say È¥£¡È¥£¡È¥£¡±ðÀ´·³Äã¼Ò¹ÃÄÌÄÌÎÒ£¡\n");
		//command("drop " + ob->query("id"));
		//this does not work due to time problem...
		//have to use call_out().
		//call_out("do_drop", 1, ob);
		return 1;
	}

	else {
		command("ah ");
		command("jump ");
		command("say ÕâÎ»" + RANK_D->query_respect(me) + "ÕæÊÇÓÐÐÄÈË£¡\n");
		command("whisper " + me->query("id")+" ÄÇÎÒ¸æËßÄãÒ»¸ö´óÃØÃÜ£ºÎÒ¸¸ÍõÏÖÔÚ¸ù±¾¾Í²»ÔÚ±ù¹¬Àï¡£Ëû²¡µÃºÜÀ÷º¦£¬ÕýÐèÒªÕâÖÖº®¶¾¡£\n");
		me->set_temp("ice_given", 1);
       		return 1;
	}
}

void do_drop(object ob)
{
	command("drop "+ob->query("id"));
}
ÿ
