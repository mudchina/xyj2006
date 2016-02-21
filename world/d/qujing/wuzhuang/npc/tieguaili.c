// tieguaili.c...weiqi, 98.02.24.

#include <ansi.h>
inherit NPC;
int fly_sea();

void create()
{
	set_name("Ìú¹ÕÀî", ({"tieguai li", "tieguai", "li"}));
	//set("title", "");
	set("gender", "ÄÐÐÔ" );
	set("age", 42);
	set("per", 12);
	set("long", "Ëû½ÅµÇÒ»Ë«ÀÃ²ÝÐ¬£¬Éí×ÅÒ»¼þÔç¾ÍÃ»ÁË±¾À´ÃæÄ¿µÄÔàÅÛ£¬×ìÀïºß×Å×ßµ÷Ð¡Çú£¬Ò»¸±ÓÆÏÐÉñÌ¬¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 300000);

	set("attitude", "peaceful");
	create_family("Îå×¯¹Û", 3, "µÜ×Ó");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 80);
	set_skill("parry", 80);
	set_skill("staff", 90);
	set_skill("fumo-zhang", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 20);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("staff", "fumo-zhang");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	set("inquiry",([
    "ÖØÓÎ¶«º£": (: fly_sea :),
		]));

	setup();
	carry_object("/d/obj/cloth/pobuyi")->wear();
	carry_object("/d/obj/cloth/lancaoxie")->wear();
	carry_object("/d/obj/weapon/staff/tieguai")->wield();
}

int fly_sea()
{
  string *jnames = ({
    "ÈÈ¾Æ",
    "Çå°×ÀÏ¾Æ",
    "Ë®¾Æ",
    "ËÖºÏÏãÓÍ",
    "µ­²è",
    "½­Ã×¾Æ",
    "ÀÏ°×¸É",
	"Ã×¾Æ",
	"ÑòÄÌ¾Æ",
	"ÅÝµÄÒÑ¾­Ã»ÓÐÎ¶µÄ²èË®",
	"ÇåË®",
	"°×ÉÕ¾Æ",
	"Î÷ºþÁú¾®²è",
	"Çå²è",
	"¹ð»¨¾Æ",
	"ÔÆÎíÉ½Ïã²è",
	"±ÌéØ²è",
	"Ðþ»ð¾Æ",
  });  
   	string jname;
	object me,ob;
    me=this_player();
	ob=this_object();

	  if( me->query_temp("wzg_baxian")!="go" )
		  return 0;
      if (me->query("wzggive/tieguaili"))
    	{
	 		  message_vision(HIG"\nÌú¹ÕÀîÎÊµÀ£ºÎÒÒªµÄ"+CYN""+me->query("wzggive/tieguaili")+HIG"¿ÉÔøÄÃµ½ÁËÂð£¿£¡\n"NOR,me);
			  return 1;
		}
	  if( me->query_temp("wzg/tieguaili")!="give")
	    {
	      jname = jnames[random(sizeof(jnames))];
		  message_vision(HIG"\nÌú¹ÕÀîÑÛ¾¦Ò»ÁÁ¶Ô$NËµµÀ£ººÃ£¬ºÃ£¬ºÃ£¬ÒªÊÇÔÙ´øÉÏµã"+CYN""+jname+HIG"¾Í¸üºÃÁË£¡\n"NOR,me);
		  me->set("wzggive/tieguaili",jname);
		  return 1;
		}
	command("say " + RANK_D->query_respect(me) + "¿ìÈ¥½ÐÉÏÆäËû°ËÏÉ£¬ÎÒÏÈ×ßÒ»²½ÁË£¡\n");
	ob->move("/d/changan/eastseashore");
    return 1;
}

int accept_object(object who, object ob)
{
	  object me = this_object();

	  if( !who->query("wzggive/tieguaili"))
		  return 0;
	  if ((string)ob->query("liquid/name")!=who->query("wzggive/tieguaili"))
   {
     command ("shake "+who->query("id"));
	call_out ("return_ob",1,who,ob);
    return 1;
  }
  

  message_vision(HIG"\n$NÐ¦ÃÐÃÐµÄÅõ×Å$n×ÔÑÔ×ÔÓïµÀ£ºÐ¡$nÑ½£¬½ñÌìÎÒ¾Í´øÄãÈ¥¶«º£ÍæÍæ£®\n"NOR,me,ob);
  who->set_temp("wzg/tieguaili","give");
  who->delete("wzggive/tieguaili");
  return 1;
}



void return_ob (object who, object ob)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="Îå×¯¹Û" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦Êå¼ûÐ¦ÁË¡£\n");
			else command("say Ê¦¹Ã¼ûÐ¦ÁË¡£\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			command("kick " + ob->query("id") );
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "£¬¸ÒÀ´ÏûÇ²ÀÏ×Ó£¡\n");
		}
		else 
		{
			command("consider");
			command("say ÊÇÄã×Ô¼ºÒª°ÝµÄ£¬ÄãÊ¦¸¸´òÉÏÃÅÀ´ÎÒ¿ÉµÃÄÃÄãµ²¡£\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say ºÃ£¬ÎÒÎå×¯¹ÛÒ»ÃÅÈË²Å±²³ö£¬Äã¿ÉµÃ¸øÊ¦¸¸ÕùÆø¡£\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}




ÿ