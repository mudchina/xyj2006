// tuying-zunzhe.c...weiqi, 97.09.15.

#include <ansi.h>

inherit NPC;
string expell_me(object me);
void create()
{
	set_name("ÍºÓ¥×ğÕß", ({"tuying zunzhe", "tuying", "zunzhe"}));
	set("title", "Ã÷Íõ»¤·¨");
	set("gender", "ÄĞĞÔ" );
	set("age", 53);
	set("per", 112);//no rongmao description.

	set("long", "´óÅôÃ÷Íõ×ùÏÂËÄ»¤·¨×ğÕßÖ®Ò»¡£¶îÍ·¸ßËÊ£¬Ò»¿´¾ÍÖªµÀ¹¦Á¦Éîºñ¡£\n");
	set("class", "yaomo");
	set("combat_exp", 500000);
	set("daoxing", 400000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 2, "µÜ×Ó");
	set_skill("unarmed", 80);
	set_skill("yingzhaogong", 150);
	set_skill("dodge", 120);
	set_skill("xiaoyaoyou", 120);
	set_skill("parry", 70);
	set_skill("blade", 70);
	set_skill("bingpo-blade", 70);
	set_skill("force", 90);   
	set_skill("ningxie-force", 90);
	set_skill("literate", 60);
	set_skill("spells", 90);
	set_skill("dengxian-dafa", 100);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "yingzhaogong");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	set("max_kee", 800);
	set("max_sen", 600);
	set("force", 1600);
	set("max_force", 800);
	set("mana", 1000);
	set("max_mana", 500);	
	set("force_factor", 50);
	set("mana_factor", 25);

        set("eff_dx", -120000);
        set("nkgain", 300);

	set("inquiry", ([
		"leave": (: expell_me :),
		"name": "ºÙºÙ£¡\n",
		"here": "¶à¿´ÉÙËµ£¡\n",
	]) );


	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	//carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="´óÑ©É½" ){
		if( (int)ob->query("family/generation") < 2  ){
			command("say ²»¸Ò£¬²»¸Ò¡£ÎÒ¸Ã°İ" + RANK_D->query_respect(ob) + "ÄúÎªÊ¦²ÅÊÇ¡£\n");
		}
		else if( (int)ob->query("family/generation") ==2  ){
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "±ğÀ´ÏûÇ²´óÒ¯ÎÒÁË£¡\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command(":D");
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "Ôç¾Í¸ÃÀ´°İÎÒÎªÊ¦£¡ÄãÄÇ¸öÆÆÊ¦¸¸Ê²Ã´¶¼²»¶®...\n");
			command("recruit " + ob->query("id") );
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 150000 ){
				command(":D ");
				command("say ºÃ£¬µ½ÎÒÕâÀïÀ´Ñ§ÒÕ£¬±ğµÄ²»Ëµ£¬±£Ö¤" + RANK_D->query_respect(ob) + "ÄãÒ»Ë«ÊÖÁ·µÃÊÇÉúÁÑ»¢±ª£¡\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say Äã»¹ÊÇÕÒğĞğÄ£¬ÎÚÑ»ËûÃÇÏÈÁ·×Å°É¡£\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ÕâÎ»" + RANK_D->query_respect(ob) + "£¬Ã»ÓĞÍÆ¼öÈËÎÒ¿É²»ÄÜÊÕÄã¡£\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

string expell_me(object me)
{       
	int stage, bonus;
	me=this_player();

	stage=(int)me->query("nx-force_bonus");
	if( stage < 2 ) bonus = 0;
	else if( stage == 2 ) bonus = 100;
	else if( stage == 3 ) bonus = (2+3)*50;
	else if( stage == 4 ) bonus = (2+3+4)*50;
	else if( stage == 5 ) bonus = (2+3+4+5)*50;
	else if( stage == 6 ) bonus = (2+3+4+5+6)*50;
	else if( stage == 7 ) bonus = (2+3+4+5+6+7)*50;
	else if( stage == 8 ) bonus = (2+3+4+5+6+7+8)*50;
	else                  bonus = (2+3+4+5+6+7+8+9)*50;


	if((string)me->query("family/family_name")=="´óÑ©É½") {
		message_vision("ÍºÓ¥×ğÕßÃæÉ«Ò»³Á£¬µÀ£ºÏÖÔÚÕıÊÇ±¾ÃÅÎ£¼±Ö®Ê±...\n", me);
		me->set_temp("xs_betray", 1);
		message_vision("ÍºÓ¥×ğÕßÒõÉ­É­µØ¶¢×Å$N£¬½Ó×ÅµÀ£ºÄãÕæµÄÏëÌÓ(true)£¿\n", me);
		if ( bonus> 0 )
		{
			message_vision("ÍºÓ¥×ğÕß¶ÙÁËÒ»ÏÂ£º»¹ÓĞ£¬Äã´Ó±¾ÃÅ±ù¹ÈÄıÑª¹¦µÃµ½ºÃ´¦¿É±ğÏë´ø×ß£º¹²ÊÇÄÚÁ¦"+chinese_number(bonus)+"µã¡£\n", me);
			me->set_temp("xs_neili_penalty", bonus);
		}
		return ("ºÙºÙ£¡\n");
	}
	return ("ÎÊÊ²Ã´ÎÊ£¡×Ô¼ºÏëÈ¥£¡\n");
}

void init()
{
	add_action("do_true", "true");
}

int do_true(string arg)
{
	if(this_player()->query_temp("xs_betray")) {
		message_vision("$N´ğµÀ£ºµÜ×Ó½²µÄÕæĞÄ»°£¡\n\n", this_player());
		message_vision("ÍºÓ¥×ğÕßÌ¾ÁË¿ÚÆøµÀ£ººÃ£¡Äã´Ó´Ë±ãÊÇ±¾ÃÅµÄµĞÈËÁË£¡\n", this_player());
		this_player()->add("betray/xueshan", 1);
		this_player()->add("betray/count", 1);

this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
		this_player()->delete_skill("ningxie-force");

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/xueshan", 1);
		this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
		this_player()->delete_temp("xs_betray");

		this_player()->set("max_force", 
			(this_player()->query("max_force")  
			- this_player()->query_temp("xs_neili_penalty")) );

		this_player()->delete_temp("xs_neili_penalty");
		this_player()->save();
		message_vision("ÍºÓ¥×ğÕßÒ»½ÅÌßÖĞ$NµÄÆ¨¹É£¬$NÌÚÔÆ¼İÎí°ã·ÉÁË³öÈ¥...\n", this_player());
		this_player()->move("/d/xueshan/binggu");
		tell_room( environment(this_player()),"Ö»ÌıÅüÅ¾£¡Ò»Éù£¬Ò»¸öÈË´Ó¿ÕÖĞ·É¹ıÀ´£¬ËÀÖí°ãµØË¤ÔÚµØÉÏ¡£\n", ({this_player()}));
		return 1;
	}
	return 0;
}

ÿ
