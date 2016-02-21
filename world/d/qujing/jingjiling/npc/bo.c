inherit NPC;

#include <allnpc.h>

void create()
{
        set_name("¹ÂÖ±¹«", ({"guzhi gong", "gong"}));
        set("age", 90);
	set("attitude", "peaceful");
        set("gender", "ÄÐÐÔ");
	set("class", "yaomo");
	set("title", "ÉîÉ½ËÄ²Ù");
	set("nickname", "ÎÚÆÜ·ïËÞ");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
	set("max_gin", 1500);
        set("max_kee",2000);
        set("max_sen", 2000);
        set("combat_exp", 1000000);
  set("daoxing", 1000000);


        set("force", 1000);
        set("max_force", 1000);
        set("mana",1500);
        set("max_mana", 1500);
        set("mana_factor", 100);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("spells", 200);
	set_skill("stick", 200);
        setup();

	carry_object("/d/qujing/jingjiling/obj/zhang")->wield();
	carry_object("/d/qujing/jingjiling/obj/cloth")->wear();
}

int accept_fight(object ob)
{
	object me = this_object();
	object who=this_player();

	if(me->is_fighting() )
		return notify_fail("¹ÂÖ±¹«¶ÔÄãËµ£ºÃ»¼ûÀÏ·òÕýÃ¦×ÅÄÇÃ´£¿\n");
	if( (int)me->query("kee")*100/(int)me->query("max_kee") < 30 )
		return notify_fail("¹ÂÖ±¹«¶ÔÄãËµ£ºÀÏ·òÌå·¦ÎÞÁ¦£¬±È²»µÃ£¬±È²»µÃ¡£\n");

	if( who->query_temp("poem_bo") ) {

        command("say ºÃ£¬ºÃ£¬ÄãÎÒÇÐ´êÎäÒÕ£¬µãµ½ÎªÖ¹£¡\n");
	reset_me ();
	call_out ("check_fight",1,who);
        return 1;
	}
	command("say ÇÒ´ýÀÏ·ò¿¼ÄãÒ»¿¼¡£\n");
	who->set_temp("answer_bo", 1);
	call_out("ask_poem", 3, who);
	return 0;	
}

void ask_poem(object who)
{	
	object me=this_object();
	message_vision("$N¶Ô$nÎÊµÀ£º¡°¾ý²»¼û£¬»ÆºÓÖ®Ë®ÌìÉÏÀ´¡±µÄÏÂ¾äÊÇÊ²Ã´£¿\n", me, who);
	message_vision("$NËµ£ºÀÏ·òÏÞÄãÈýÊ®ÃëÄÚ»Ø´ð(answer)¡£\n", me);
	me->set_temp("check_answer", 1);
	call_out("say_answer", 30);
	return;
}
void say_answer(object who)
{
        if(!who) return;
	command("sigh");
	command("say Á¬Õâ¶¼²»ÖªµÀ£¬ÀÏ·ò²»Ð¼ÓëÄãÒ»¶·£¡\n");
	this_object()->delete_temp("check_answer");
	who->delete_temp("answer_bo");
	return ;
}
	
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
	object where=environment(this_object());

	if( !(this_object()->query_temp("check_answer") ) )
		return notify_fail("Ê²Ã´£¿\n");

        if( !arg ) return notify_fail("ÄãËµÊ²Ã´£¿\n");

	message_vision("$N´ðµÀ£ºÊÇ¡°" + arg + "¡±¡£\n", this_player());

	if( this_player()->query_temp("answer_bo") ) {

		if( strsrch(arg, "±¼Á÷µ½º£²»¸´»Ø") >=0  ) {
                command("haha");
		command("say ²»´í£¬²»´í£¡ÀÏ·ò¾ÍÓëÄã¹ýÁ½ÕÐ¡£\n");
		this_player()->set_temp("poem_bo", 1);
		this_player()->delete_temp("answer_bo");
		this_object()->delete_temp("check_answer");
		if(where->query("short")!="Ê¯ÑÂ") {
			command("say ÕâÀï²»Éõ¿í³¨£¬ÄãÎÒÊ¯ÑÂÒ»¾Û¡£\n");
			message_vision("$NÉíÓ°Ò»»Î±ã²»¼ûÁË¡£\n", this_object());
			this_object()->move("/d/qujing/jingjiling/shiya");
			message_vision("$N×ßÁË¹ýÀ´¡£\n", this_object());
		}
	remove_call_out("say_answer");
		return 1;
		}else{
		command("shake");
		command("say ²»¶Ô£¬²»¶Ô£¡\n");
		return 1;
		}
	}else{
	command("sigh " + this_player()->query("id") );
	command("say ¶à×ì£¬¶à×ì£¡");
	return 1;
	}
}
ÿ