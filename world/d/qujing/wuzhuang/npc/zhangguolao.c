// zhangguolao.c...weiqi, 98.02.24.
#include <ansi.h>
int fly_sea();
inherit NPC;
void create()
{
	set_name("ÕÅ¹ûÀÏ", ({"zhang guolao", "zhang", "guolao"}));
	//set("title", "");
	set("gender", "ÄÐÐÔ" );
	set("age", 50);
	set("per", 20);
	set("long", "Ò»Î»Ð¦ÎûÎûµÄ»¬»üÀÏÍ·¡£\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 500000);

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
	set_skill("literate", 50);
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

	set("maolu", 0);

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/cloth/pobuxie")->wear();
	carry_object("/d/obj/weapon/hammer/jiuhulu")->wield();
}

void init()
{       
	object ob=this_player();
	object me=this_object();

	::init();

	set("chat_chance", 10);
	set("inquiry", ([
	    "ÖØÓÎ¶«º£": (: fly_sea :),
		"name" : "ºÇºÇ£¡ÕÅ¹ûÀÏÊÇÒ²¡£\n",
		"here" : "½ñ¶ù¸ö×íÁË£¬»¹Õæ±»ÄãÎÊµ¹ÁË¡£\n",
	 ]) );

	set("chat_msg", ({
		"ÕÅ¹ûÀÏÎûÎûÎûµØÐ¦ÁË¼¸Éù¡£\n",	
		"ÕÅ¹ûÀÏÄÃÆð¾ÆºùÂ«ÓÖ¹àÁËÒ»¿Ú£¬ÂúÒâµØßÆÁËßÆ×ì¡£\n",
		"ÕÅ¹ûÀÏ´òÁË¸öÏìÖ¸£º¹þ¹þ£¬ÎÒµÄÐ¡Ã«Â¿¾ÍÊÇÌý»°¡£\n",
		(: random_move :)
	}) );

	if( query("maolu") == 0 )
	{
		call_out("qi_maolu", 1);
		set("maolu", 1);
	}

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
	"¹ð»¨¾Æ",
	"ÔÆÎíÉ½Ïã²è",
	"±ÌéØ²è",
	"Ðþ»ð¾Æ",
	"Î÷ºþÁú¾®²è",
	"Çå²è",
	});  
   	string jname;
	object me,ob;
    me=this_player();
	ob=this_object();

	  if( me->query_temp("wzg_baxian")!="go" )
		  return 0;
      if (me->query("wzggive/zhangguolao"))
    	{
	 		  message_vision(WHT"\nÕÅ¹ûÀÏÎÊµÀ£ºÄÇ"+CYN""+me->query("wzggive/zhangguolao")+WHT"¿ÉÔø´øÀ´ÁËÂð£¿£¡\n"NOR,me);
			  return 1;
		}
	  if( me->query_temp("wzg/zhangguolao")!="give")
	    {
	      jname = jnames[random(sizeof(jnames))];
		  message_vision(WHT"\nÕÅ¹ûÀÏÃþÁËÃþºú×ÓËµµÀ£ºÎÒÃÇ°ËÏÉÒ»Ö±¶¼ÏëÔÙÓÎÒ»´Î¶«º££¬½ñÈÕ" + RANK_D->query_respect(me) + "ËµÆð£¬²»ÈçÎÒÃÇÒ»
		      Í¬È¥£¬Ö»ÊÇÀÏÍ·×ÓÎÒ×î½üÌØ±ðÏëºÈµã"+CYN""+jname+WHT"£®\n"NOR,me);
		  me->set("wzggive/zhangguolao",jname);
		  return 1;
		}
	command("say " + RANK_D->query_respect(me) + "¿ìÈ¥½ÐÉÏÆäËû°ËÏÉ£¬ÎÒÏÈ×ßÒ»²½ÁË£¡\n");
	ob->move("/d/changan/eastseashore");
    return 1;
}

int accept_object(object who, object ob)
{
	  object me = this_object();

	  if( !who->query("wzggive/zhangguolao"))
		  return 0;
	  if ((string)ob->query("liquid/name")!=who->query("wzggive/zhangguolao"))
   {
     command ("shake "+who->query("id"));
	call_out ("return_ob",1,who,ob);
    return 1;
  }
  

  message_vision(WHT"\n$N½Ó¹ý$n³¢ÁË³¢£¬²»ÓÉµÃÖåÁËÖåÃ¼Í·µÀ£ºÈË¶¼Ëµ"+who->query("wzggive/zhangguolao")+"Î¶µÀ¶ÀÌØ£¬ÔõÃ´»¹²»ÈçÎÒµÄÃ×¾ÆÏã´¼£®\n"NOR,me,ob);
  who->set_temp("wzg/zhangguolao","give");
  who->delete("wzggive/zhangguolao");
  return 1;
}



void return_ob (object who, object ob)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void qi_maolu()
{
	object maolu;

        	maolu = new(__DIR__"xiaomaolu.c");
        	maolu->move( environment(this_object()) );
	command("mount maolu");
	return;	
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
		command("say ºÃ£¬ºÃºÃ¸É£¬ÕÅ¹ûÀÏ²»ÐÐ£¬Í½µÜ¿É²»ÄÜ²îÁË¡£\n");
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