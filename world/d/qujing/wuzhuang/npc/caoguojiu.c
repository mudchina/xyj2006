// caoguojiu.c...weiqi, 98.02.24.
#include <ansi.h>

inherit NPC;
int fly_sea();

void create()
{
	set_name("²Ü¹ú¾Ë", ({"cao guojiu", "cao", "guojiu"}));
	//set("title", "");
	set("gender", "ÄÐÐÔ" );
	set("age", 40);
	set("per", 20);
	set("long", "Ò»Î»ÉñÇéÑÏËàµÄÖÐÄêÈË¡£²Ü¹ú¾ËÃû¾°ÐÝ£¬Ìì×Ê´¿ÉÆ£¬\n²»Ï²¸»¹ó£¬¿áÄ½ÇåÐé¡£ÆäµÜ½¾×Ý²»·¨£¬ºóØèÌÓ¹úÏÜ¡£\n²Ü¹ú¾ËÉîÒÔÎª³Ü£¬ËìÒþ¼£É½ÁÖ£¬¾«Ë¼ÔªÀí¡£ºóÍ¶ÈëÕòÔªÃÅÏÂ¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 200000);

	set("attitude", "peaceful");
	create_family("Îå×¯¹Û", 3, "µÜ×Ó");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 70);
	set_skill("parry", 80);
	set_skill("hammer", 90);
	set_skill("kaishan-chui", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 60);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("hammer", "kaishan-chui");
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
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/hammer/baiyuban")->wield();
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
	"Çå²è",
	"ÑòÄÌ¾Æ",
	"ÅÝµÄÒÑ¾­Ã»ÓÐÎ¶µÄ²èË®",
	"ÇåË®",
	"°×ÉÕ¾Æ",
	"Î÷ºþÁú¾®²è",
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
      if (me->query("wzggive/caoguojiu"))
    	{
	 		  message_vision(MAG"\n²Ü¹ú¾ËÎÊµÀ£ºÎÒÒªµÄ"+CYN""+me->query("wzggive/caoguojiu")+MAG"¿ÉÔøÄÃµ½ÁËÂð£¿£¡\n"NOR,me);
			  return 1;
		}
	  if( me->query_temp("wzg/caoguojiu")!="give")
	    {
	      jname = jnames[random(sizeof(jnames))];
		  message_vision(MAG"\n²Ü¹ú¾ËÀÖºÇºÇµÄ´ò×Å°×Óñ°åËµµÀ£ººÃÖ÷Òâ£¬¼ÇµÃ´øÉÏµã"+CYN""+jname+NOR"£¡\n",me);
		  me->set("wzggive/caoguojiu",jname);
		  return 1;
		}
	command("say " + RANK_D->query_respect(me) + "¿ìÈ¥½ÐÉÏÆäËû°ËÏÉ£¬ÎÒÏÈ×ßÒ»²½ÁË£¡\n");
	ob->move("/d/changan/eastseashore");
    return 1;
}

int accept_object(object who, object ob)
{
	  object me = this_object();

	  if( !who->query("wzggive/caoguojiu"))
		  return 0;
	  if ((string)ob->query("liquid/name")!=who->query("wzggive/caoguojiu"))
   {
     command ("shake "+who->query("id"));
	call_out ("return_ob",1,who,ob);
    return 1;
  }

  message_vision(MAG"\n$NÀÖºÇºÇµÄÅõ×Å$n×ÔÑÔ×ÔÓïµÀ£º$nÑ½£¬$n£¬½ñÌìÄã¾ÍÅã×Å¹ú¾ËÒ¯È¥¶«º£ÍæÍæ£®\n"NOR,me,ob);
  who->set_temp("wzg/caoguojiu","give");
  who->delete("wzggive/caoguojiu");
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
			if ( (string)ob->query("gender") == "ÄÐÐÔ" ) command("say Ê¦ÐÖÌ«¿ÍÆøÁË¡£\n");
			else command("say Ê¦ÃÃÌ«¿ÍÆøÁË¡£\n");
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
		command("say ºÃ£¬²»¹ýÔÚÎÒÕâ¶ù¿É²»ÐíÍµÀÁ£¡\n");
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