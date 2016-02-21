// hexiangu.c...weiqi, 98.02.24.
#include <ansi.h>
int fly_sea();
inherit NPC;
void create()
{
	set_name("ºÎÏÉ¹Ã", ({"he xiangu", "he", "xiangu"}));
	//set("title", "");
	set("gender", "Å®ÐÔ" );
	set("age", 25);
	set("per", 20);
	set("long", "ºÎÏÉ¹ÃÉîµÃÕòÔª´óÏÉÏ²°®£¬¸÷Î»Í¬ÃÅ´ó¶à¸úËý½»ºÃ¡£\nºÎÏÉ¹ÃÔ­ÃûºÎÐã¹Ã£¬¸¸Ç×ÊÇ¿ª¶¹¸¯·»µÄ£¬ËýÍ¶ÈëÎå×¯¹ÛÇ°ÊÇµ±µØÓÐÃûµÄ¡°¶¹¸¯Î÷Ê©¡±¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 200000);

	set("attitude", "peaceful");
	create_family("Îå×¯¹Û", 3, "µÜ×Ó");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 80);
	set_skill("parry", 80);
	set_skill("sword", 90);
	set_skill("sanqing-jian", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 50);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
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
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
}

int fly_sea()
{
  string *jnames = ({
    "ËÖºÏÏãÓÍ",
	"ÑòÄÌ¾Æ",
	"¹ð»¨¾Æ",
	"ÔÆÎíÉ½Ïã²è",
	"±ÌéØ²è",
	"Ðþ»ð¾Æ",
	"Î÷ºþÁú¾®²è",
	});  
   	string jname;
	object me,ob;
    me=this_player();
	ob=this_object();

	  if( me->query_temp("wzg_baxian")!="go" )
		  return 0;
      if (me->query("wzggive/hexiangu"))
    	{
	 		  message_vision(HIM"\nºÎÏÉ¹ÃÎÊµÀ£ºÄÇ"+CYN""+me->query("wzggive/hexiangu")+HIM"¿ÉÔøÄÃµ½ÁËÂð£¿£¡\n"NOR,me);
			  return 1;
		}
	  if( me->query_temp("wzg/hexiangu")!="give")
	    {
	      jname = jnames[random(sizeof(jnames))];
		  message_vision(HIM"\nºÎÏÉ¹ÃÇ·ÉíÊ©ÀñµÀ£ºÈç" + RANK_D->query_respect(me) + "ÄÜ´øÉÏ"+CYN""+jname+HIM"ÄÇÐã¹ÃÒ²Í¬È¥£¡\n"NOR,me);
		  me->set("wzggive/hexiangu",jname);
		  return 1;
		}
	command("say " + RANK_D->query_respect(me) + "¿ìÈ¥½ÐÉÏÆäËû°ËÏÉ£¬ËµÐã¹ÃÔÚ¶«º£±ßµÈËûÃÇ£¡\n");
	ob->move("/d/changan/eastseashore");
    return 1;
}

int accept_object(object who, object ob)
{
	  object me = this_object();

	  if( !who->query("wzggive/hexiangu"))
		  return 0;
	  if ((string)ob->query("liquid/name")!=who->query("wzggive/hexiangu"))
   {
     command ("shake "+who->query("id"));
	call_out ("return_ob",1,who,ob);
    return 1;
  }

  message_vision(HIM"\n$N½Ó¹ý$nÁ¬Éù³ÆÔÞµÀ£ºÔç¾ÍÏë³¢³¢Õâ"+who->query("wzggive/hexiangu")+"ÁË£®\n"NOR,me,ob);
  who->set_temp("wzg/hexiangu","give");
  who->delete("wzggive/hexiangu");
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
			command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "£¬¸ÒÄÃ¹ÃÄÌÄÌÎÒÀ´ÏûÇ²£¡\n");
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
