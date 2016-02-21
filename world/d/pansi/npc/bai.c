//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
// int accept_object(object me, object ob);
void create()
{
       set_name(HIC"°×¾§¾§"NOR, ({"bai jingjing", "bai", "jingjing","master"}));
       set("long",
"ÅÌË¿´óÏÉ×ùÏÂµÄ¶þµÜ×Ó°×¹Ç¾«,ËæÅÌË¿´óÏÉÐÞ³ÉÕý¹û,ÒòËïÎò¿ÕµÁÈ¡ÅÌË¿¶´ÖÁ±¦ÔÂ¹â±¦ºÏ¶øÓëÆäÊ¦½ã´º
Ê®ÈýÄïÊÆ³ÉË®»ð¡£ËýÒ»Éú°®´©°×ÒÂ£¬µ±ÕæÈç·ç·÷ÓñÊ÷£¬Ñ©¹üÇí°ú£¬¼æÖ®ÉúÐÔÇåÀä£¬Êµµ±µÃÆð¡°Àä½þÈÜ
ÈÜÔÂ¡±µÄÐÎÈÝ¡£\n");
       set("title", HIW"°×¹Ç¶´Ö÷"NOR);
       set("gender", "Å®ÐÔ");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 40);
       set("int", 30);
       set("max_kee", 2900);
       set("max_sen", 2800);
       set("force", 4200);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
       set("daoxing", 1200000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 150);
       set_skill("dodge", 180);
       set_skill("force", 150);
       set_skill("parry", 100);
       set_skill("qin", 200);
       set_skill("sword", 180);
       set_skill("spells", 150);
   set_skill("pansi-dafa", 150);
   set_skill("lanhua-shou", 150);
   set_skill("jiuyin-xinjing", 150);
   set_skill("chixin-jian", 200);
   set_skill("yueying-wubu", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "chixin-jian");
   map_skill("dodge", "yueying-wubu");
   set("chat_chance",5);
   set("chat_msg", ({
        HIG"°×¾§¾§ÇáÉù¸æËßÄã:Ê®°ËËêÄÇÄêËûËµ¹ý»áÀ´È¢ÎÒ£¬ÎÒµÈÁËËûÈýÄê¡­¡­Ô­À´Ò»ÇÐ¶¼ÊÇÆ­ÎÒµÄ£¡\n"NOR,
        HIG"°×¾§¾§ÇáÉù¸æËßÄã:ÎÒÓöÉÏÒ»¸öÈË£¬ËÍ¸øÎÒÒ»Ì³¾Æ£¬ËûËµÄÇ½Ð×íÉúÃÎËÀ£¬ºÈÁËÖ®ºó£¬¿ÉÒÔ½ÐÄãÍüµôÒÔ×ö¹ýµÄÈÎºÎÊÂ¡£\n"HIC,
        HIG"°×¾§¾§ÇáÉù¸æËßÄã:ÄÇÌìÎÒ¸úËûÔÚÔÂÁÁÏÂºÈ¾Æ£¬Ëû¶ÔÎÒËµ£¬Èç¹ûÎÒÓÐ¸öÃÃÃÃ£¬ËûÒ»¶¨È¢ËýÎªÆÞ¡£ËûÃ÷ÖªÎÒÊÇÅ®×Ó£¬ÎªÊ²Ã´ÒªÕâÑùËµ£¡\n"NOR,
		HIG"°×¾§¾§ÇáÉù¸æËßÄã:²»ÖªµÀÊÇÇÉºÏ»¹ÊÇÆäËûÔ­Òò£¬ÒÔÇ°Ã¿´ÎËûÀ´ÅÌË¿¶´µÄÊ±ºò£¬Ìì¶¼»áÏÂÓê£¡\n"NOR,
		HIG"°×¾§¾§ÇáÉù¸æËßÄã:Ëû±¾À´¾Í²»ÊôÓÚÕâ¸öÊÀ½ç£¬ËûÊÇÒ»¸öÌÓÏÂÌì½çµÄÉñÏÉ¡£ÌýËµÌÓÏÂÌì½çµÄÉñÏÉÃüÔËÍùÍùÊÇ²»ÐÒµÄ£¬ÓÈÆäÊÇ¶¯ÁË·²ÐÄµÄÄÇ
ÖÖ¡£ÉñÏÉÊÇ²»¸ÃÓÐ¸ÐÇéµÄ£¬Õâ¿ÉÄÜÒ²ÊÇÃüÔË£¡\n"NOR,
        }));


create_family("ÅÌË¿¶´", 2, "µÜ×Ó");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{

	if (((int)ob->query("combat_exp") < 100000 )){
//	this_player()->set("mark/pansi_bai", 1);
	command("shake");
	command("say Æ¾ÄãÕâµãÐÞÎª£¿");
	return;}
       	if(!ob->query_temp("marks/zui")){
//        this_player()->set("mark/pansi_bai", 1);
	  command("shake");
	  command("say ÄãÎÒÎÞÔµ£¬»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
	  return ;
	}
	else{
	command("curtain");
	command("say ºÃ£¡" + RANK_D->query_respect(ob) + "Í¶ÈëÎÒµÄÃÅÏÂ£¬ËûÈÕ±ØÓÐËù³É£¡\n");
	command("recruit " + ob->query("id") );
	ob->set("title", "»¨¹ûÉ½°×¹Ç¶´Ö÷×ùÏÂµÜ×Ó");
	ob->set("class", "yaomo");
	return ;}
}
int accept_object(object me, object ob)
{
    
    if(ob->query("name") == "[1;32m×íÉúÃÎËÀ[2;37;0m" && ob->query("realzui"))
    {
        command("say °¡,×íÉúÃÎËÀ£¬¾ÓÈ»Ö»ÊÇÒ»Ì³ÇåË®°ÕÁË£¡\n");
    
	command("say Õâ¾ÍÊÇ×íÉúÃÎËÀ?Ð»Ð»Äã,ÖÕÓÚ¿ÉÒÔÍüµôÄÇ¸ö³ôºï×ÓÁË¡£");
	command("jump");
    	me->set_temp("marks/zui",1);
	return 1;}
	return 0;
}

