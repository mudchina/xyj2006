// yingwu-guai.c...weiqi, 97.09.15.
// drooler parts added by pickle 9-18-97

#include <ansi.h>
inherit NPC;

// from drooler file, some global variables

string *rnd_say = ({
	"ÎÒÑ©É½ÅÉµÜ×Ó¸÷¸öÉñÓÂÎŞ±È£¬ÌìÏÂÎŞµĞ£¡",
	"¡¸¸Â¡«¡«¸Â¡«¡«¡¹",
	"É±Èë´óÀ×ÒôËÂ£¬ÇÀÁËËûµÄÁ«»¨±¦×ù£¡",
	"ÄãÃÇ¶¼ÒªºÃºÃÁ·¹¦£¡²»Òª¹¼¸ºÁËÃ÷ÍõµÄÒ»Æ¬¿àĞÄ£¡",
	"´ó¼ÒºÃ£¡",
});

varargs void drool(string msg, string who);

/************************************************************/
void create()
{
	set_name("ğĞğÄ½«¾ü", ({"yingwu jiangjun", "yingwu", "jiangjun"}));
	set("gender", "ÄĞĞÔ" );
	set("age", 23);
	set("per", 112);//no rongmao description.

	set("long", "Ñ©É½ÃÅÏÂÓĞÃûµÄ¸ßÊÖÖ®Ò»ğĞğÄ½«¾ü¡£\nËûÔ¶¿´»¹²»´í£¬×ß½üÁË²Å·¢ÏÖËû³¤×Å³¤³¤µÄÒ»ÕÅÄñ×ì¡£\n");
	set("class", "yaomo");
	set("combat_exp", 100000);
  set("daoxing", 50000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 3, "µÜ×Ó");
	set_skill("unarmed", 50);
	set_skill("yingzhaogong", 50);
	set_skill("cuixin-zhang", 60);
	set_skill("dodge", 50);
	set_skill("xiaoyaoyou", 80);
	set_skill("parry", 80);
	set_skill("blade", 60);
	set_skill("bingpo-blade", 80);
        set_skill("sword", 60);
        set_skill("bainiao-jian", 80);
	set_skill("force", 60);   
	set_skill("ningxie-force", 70);
	set_skill("literate", 80);
	set_skill("spells", 50);
	set_skill("dengxian-dafa", 50);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 700);
	set("max_sen", 600);
	set("force", 700);
	set("max_force", 700);
	set("mana", 700);
	set("max_mana", 700);	
	set("force_factor", 10);
	set("mana_factor", 15);

	// the following are from the drooler
	set("chat_chance", 30);
	set("chat_msg", ({
		(: drool :),
	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");

	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

/************************************************************/

// things involving the menpai: apprentice, ......

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="´óÑ©É½" ){
		if( (int)ob->query("family/generation") < 3  ){
			command("say ²»¸Ò£¬²»¸Ò¡£ÎÒ¸Ã°İ" + RANK_D->query_respect(ob) + "ÄúÎªÊ¦²ÅÊÇ¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "±ğÀ´ÏûÇ²´óÒ¯ÎÒÁË£¡\n");
		}
		else {
			command(":D");
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "Ôç¾Í¸ÃÀ´°İÎÒÎªÊ¦£¡ÄãÄÇ¸öÆÆÊ¦¸¸Ê²Ã´¶¼²»¶®...\n");
			command("recruit " + ob->query("id") );
                        ob->set("title", "´óÑ©É½»¤É½Ğ¡Ñı");
	                ob->set("class", "yaomo");
	}
	}

	else{
		command(":D ");
		command("say ºÃ£¬µ½ÎÒÃÇ´óÑ©É½À´Ñ§ÒÕ£¬ÓÖÕÒÁË¸öºÃÊ¦¸¸¡£" + RANK_D->query_respect(ob) + "¿ÉÒÔËµÊÇÇ°Í¾ÎŞÁ¿°¡£¡\n");
		command("recruit " + ob->query("id") );
                ob->set("title", "´óÑ©É½»¤É½Ğ¡Ñı");
                ob->set("class", "yaomo");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

/************************************************************/

// the following copies some functions of the drooler
// from /obj/example/drooler to allow the yingwu to
// repeat what a human says, as a ğĞğÄ's nature is.

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "£¿", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "£¡", "");
	msg = replace_string(msg, "°¡", "");
	msg = replace_string(msg, "Âğ", "");
	msg = replace_string(msg, "Ò®", "");
	msg = replace_string(msg, "°É", "");

	if( msg!="" ) {
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who, phrase;

	if( !userp(ob) ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
	case "kick":
		if( random(10)<5 ) {
			command("say ¹·ÍÈÓÖ·¢Ñ÷ÁË...\n");
		}
		break;
	case "pat":
		if( random(10)<5 ) {
			command("say ²»ĞíÅÄ£¡ÔÙÅÄÄãÒ¯Ò¯ÎÒ°ÑÄãµÄ×¦×Ó¶çÏÂÀ´£¡\n");
		}
		break;
	default:
		if( random(10)<5 )
			command(verb + " " + ob->query("id"));
		else
			drool();
	}
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) return;

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

	if( (strsrch(msg, "ÎªÊ²Ã´") >= 0) ) {
		if( sscanf(msg, "%*sªÊ²Ã´%s", msg)==2 ) msg = "ÎªÊ²Ã´" + msg;
		switch(random(8)) {
		case 0: command("say " + who + "£¬ÄãÊÇÔÚÎÊÎÒÂğ£¿"); break;
		case 1: command("say ¹ØÓÚ" + msg + "¡­¡­"); break;
		case 2: command("say ßÀ¡­¡­"); drool(); break;
		case 3: command("say Õâ¸öÎÊÌâÂï¡­¡­"); break;
		case 4: command("say " + who + "£¬ÖªµÀÕâ¸öÎÊÌâµÄ´ğ°¸¶ÔÄãÄÇÃ´ÖØÒªÂğ£¿"); break;
		case 5: command("say " + msg + "£¿"); break;
		case 6: command("say " + who + "ÄãÄÜ²»ÄÜËµÇå³şÒ»µã£¿"); break;
		case 7: command("say " + who + "£¬ÎÒ²»¶®ÄãÎÊµÄÎÊÌâ¡£"); break;
		}
	}
	else if( (strsrch(msg, "Äã") >= 0)
	||	(strsrch(msg, "drooler") >= 0)
	||	(strsrch(msg, "Drooler") >= 0)) {
		if( sscanf(msg, "%*sã%s", msg) == 2 ) msg = "Äã" + msg;
		msg = replace_string(msg, "Äã", "ÎÒ");
		switch(random(10)) {
		case 0:	command("say " + who + "£¬ÄãÊÇËµ" + msg + "Âğ£¿");	break;
		case 1:	command("say ÄãÈ·¶¨" + msg + "£¿");	break;
		case 2:	command("say " + msg + "¸úÄãÓĞÊ²Ã´¹ØÏµ£¿");	break;
		case 3:	command("say àÅ¡­¡­" + who + "ËµµÃºÃ"); break;
		case 4:	command("say " + who + "ÄãÎªÊ²Ã´¶Ô" + msg + "ÕâÃ´ÓĞĞËÈ¤£¿"); break;
		case 5:	command("say ÎªÊ²Ã´ÄãÈÏÎª" + msg + "£¿"); break;
		case 6:	command("say »»¸ö»°Ìâ°É¡£"); drool(); break;
		case 7:	command("say ²Å¹Ö£¡"); break;
		case 8:	command("say ²»Ò»¶¨°É£¿"); break;
		case 9:	command("say ÓĞÕâ¸ö¿ÉÄÜ¡­¡­"); break;
		}
	}
	else if( (strsrch(msg, "ÎÒ") >= 0)) {
		if( sscanf(msg, "%*sÒ%s", msg) == 2 ) msg = "ÎÒ" + msg;
		msg = replace_string(msg, "ÎÒ", "Äã");
		msg = replace_string(msg, "?", "");
		switch(random(8)) {
		case 0:	command("say ÄãÊÇËµ" + msg + "Âğ£¿"); break;
		case 1:	command("say ÕæµÄ£¿" + msg + "£¿");	break;
		case 2:	command("say Èç¹û" + msg + "£¬ÎÒÄÜ°ïÄãÊ²Ã´Ã¦Âğ£¿");	break;
		case 3:	command("hmm");	break;
		case 4:	command("say ÄãÈÏÎª" + msg + "£¿"); break;
		case 5:	command("say ÎÒÓĞÍ¬¸Ğ"); break;
		case 6:	command("say ÄãËµµÄ¡¸" + msg + "¡¹ÎÒ²»ÄÜ¹¶Í¬£¡"); break;
		case 7:	command("say ÓĞ¹Ø¡¸" + msg + "¡¹µÄ»°Ìâµ½´ËÎªÖ¹ºÃÂğ£¿"); break;
		}
	} else {
		switch(random(20)) {
			case 0: command("say ÎªÊ²Ã´Ëµ" + msg + "£¿"); break;
			case 1: command("say ¡¸" + msg + "¡¹ÊÇÊ²Ã´ÒâË¼£¿"); break;
			case 2: command("say " + msg + "£¿"); break;
			case 3: command("hehe"); break;
			case 4: command("sister"); break;
			case 5: command("?"); break;
			case 6: command("say ¡­¡­"); break;
			case 7: command("hmm"); break;
			case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("say ÄãÔõÃ´ÖªµÀ" + msg + "£¿"); break;
			case 10: command("say ¸Õ¸Õ" + who + "²»ÊÇËµÁË£¬" + msg); break;
			case 11: command("say ÎÒµ±È»ÖªµÀ£¬" + msg); break;
			case 12: command("say È»ºóÄØ£¿"); break;
			case 13: command("say ÕæµÄÂğ£¿"); break;
			case 14: command("say ÎÒ²»ÕâÃ´ÈÏÎª¡£"); break;
			default:
				break;
		}
	}
}

void reset()
{
	delete("memory");
}
ÿ
