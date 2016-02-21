// kulou.c ÷¼÷Ã
// created 9-15.97 pickle

/************************************************************/
// global declaractions etc.

#include <ansi.h>
inherit NPC;

int accept_object(object me, object ob);
/************************************************************/

void create()
{
  set_name("÷¼÷Ã", ({"ku lou", "yao", "kulou", "skeleton", "monster"}));
  set("long","ÕâÃ÷Ã÷ÊÇÒ»¸¶¸É¿İµÄº¡¹Ç£¬µ«²»ÖªÔõÃ´Ëû¾¹È»ÊÇ»îµÄ£¡\n");
  set("gender", "ÄĞĞÔ");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("combat_exp", 100000);
  set("daoxing", 50000);

  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "kugu-blade");
  set("chat_chance", 1);
  set("chat_msg", ({
	"÷¼÷ÃµÀ£º°¦£¬Ò²²»ÖªÔÚÕâÀïË¯ÁË¶à¾ÃÁË¡£\n",
	"÷¼÷ÃµÀ£º¶¼ÍüÁËÈËÈâÊÇÊ²Ã´Î¶¶ùÁË¡£\n",
	}) );
  set("inquiry", ([
	"name":		"Ãû×Ö£¿Ê²Ã´Ãû×Ö£¿ÎÒÔç¾Í²»¼ÇµÃÁË¡£",
	"here":		"ÕâÀï£¿ÕâÀïÊÇ¸öÆÆ¶´¡£Òª²»ÊÇÄÇ¸ö»ìÕÊÂÌÃ«ÀÏÊó½ĞÎÒ¿´×Å£¬ÎÒÔç³öÈ¥³ÔÈËÈâ£¬ÏíÇå¸£ÁË£¡",
	"rumors":	"ºÙºÙ£¬ÎÒ¶¼ÔÚÕâÀïË¯ÕâÃ´¶àÄêÁË£¬»¹ÄÜÖªµÀµãÊ²Ã´£¿",
	"ÈËÈâ":		"°¦¡£ÄÜ³ÔÉÏµãÈËÈâ¾ÍºÃÁË¡£",
	]));

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

/************************************************************/

void init()
{
    object ob;
    ::init();

    if (interactive(ob=this_player()) && !is_fighting())
    {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
    }
}

void greeting(object me)
{
    string myrude=RANK_D->query_rude(me);
    command("hehe "+me->query("id"));
    command("say ÄãÕâ"+myrude+"À´¸ÉÊ²Ã´£¿ÊÇ²»ÊÇ´øºÃ¶«Î÷Ğ¢¾´ÎÒÀ´×Å£¿");
    return;
}
/************************************************************/
int accept_object(object me, object ob)
{
    if (ob->query("name_recognized") == "ÈËÈâ°ü×Ó")
    {
//	if (!me->query_temp("wudidong/received_renroubao"))
//	{
//	    message_vision(CYN"÷¼÷ÃÖåÁËÖåÃ¼µÀ£ºÕâ¶«Î÷ÄãÄÄ¸ãÀ´µÄ£¿Î¶µÀ²»¶Ô£¡\n"NOR, me);
//	    return 2;
//	}
	command("say ²»´í²»´í£¬ÄãĞ¡×Ó¹ûÈ»»¹Ã»ÍüÁËÎÒ£¡");
	me->add_temp("wudidong/gave_bookguard_baozi", 1);
	return 1;
    }
    command("say Ê²Ã´ÆÆÀÃ£¿");
    return 0;
}
/************************************************************/

void die()
{
    string msg;

    msg="÷¼÷ÃÉ¢³ÉÒ»¶Ñ°×¹Ç£¬¹öÁË¿ªÈ¥¡£\n";
    msg+=CYN"ËÄÃæ°Ë·½´«À´ÕóÕó²ÒĞ¦£ºÏëÉ±ËÀÒ»¾ß¿İ¹Ç£¬ÄãÕæÊÇ³ÕĞÄÍıÏë£¡ÎÒ»á»ØÀ´µÄ£¡\n"NOR;
    if(environment())
	message("vision", msg, environment());
    destruct(this_object());
}
ÿ