// Changed by sjmao  09-11-97
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("ÁúÉÙÒ¯", ({"long shaoye","shaoye","taizi","long","prince"}));

set("long","ÁúÍõµÄ´óÉÙÒ¯£®\n");
       set("gender", "ÄÐÐÔ");
	set("int", 25);
       set("age", 26);
       set("title", "Áú¹¬Ì«×Ó");
       set("attitude", "peaceful");
       set("combat_exp", 450000);
  set("daoxing", 300000);

       set("rank_info/respect", "µîÏÂ");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
       set_skill("literate", 50);
       set_skill("unarmed", 120);
       set_skill("dodge", 100);
       set_skill("force", 100);
       set_skill("parry", 100);
       set_skill("fork", 80);
       set_skill("spells", 80);
        set_skill("seashentong", 80);
        set_skill("dragonfight", 120);
        set_skill("dragonforce", 80);
        set_skill("fengbo-cha", 80);
        set_skill("dragonstep", 80);
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");

        set("inquiry", ([ "Àë¹¬": (: expell_me :),
                "leave": (: expell_me :), ]) );


      create_family("¶«º£Áú¹¬", 2, "Ë®×å");
	setup();

        carry_object("/d/ourhome/obj/choupao")->wear();
}

void attempt_apprentice(object ob)
{
        command("look " + ob->query("id"));
        if ( (string)ob->query("gender")=="ÄÐÐÔ"){
           command("kick " + ob->query("id"));
           command("say ÎÒÃ»¹¦·ò½ÌÄã£¡\n");
           return;
        }

        command("sister " + ob->query("id"));
        command("recruit " + ob->query("id") );
        command("say ºÙºÙ£¬Ö»Òª" + RANK_D->query_respect(ob) +
"°ÑÊ¦¸¸ÎÒÅª¸ßÐËÁË£¬±£ÄãÈÙ»ª¸»¹óÏíÊÜ²»¾¡¡£\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="¶«º£Áú¹¬")
    {
        if ( (string)me->query("gender")=="ÄÐÐÔ"){
           command("slap " + me->query("id"));
           return("ÈÂÊ²Ã´ÈÂ£¡Òª¹öµ°È¥ÎÊÎÒÃÇ¼ÒÀÏÍ·×Ó£¡\n");
        }

      message_vision("ÁúÉÙÒ¯ÑÛÀáÍôÍôµØÍû×Å$N£¬Éì³öÊÖÏëÀ­×¡$N£¬µ«ÓÖËõÁË»ØÀ´¡£\n", me);
      return ("ÄãÈ¥ÎÊÎÒ¸¸Íõ°É¡£¡£¡£ÎÒÔõÃ´ÖªµÀ£¿\n");
    }
  return ("²»ÖªµÀ£¡\n");
}

void die()
{
	object me,who,longjin;
    string whoid;
    me=this_object();
    if(me->query_temp("longjin_kill"))
	{
		  whoid=me->query_temp("longjin_kill");
    	  if (!present(whoid,environment()))
        	  return ::die();
	  	  who=present(whoid,environment());
          if((who->query("fangcun/panlong_hell_18")=="done")&&(who->query("fangcun/panlong_hell_longjin")=="begin")&&(environment()))
		{
			  longjin=new("/d/sea/obj/longjin");
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
      ::die();
}

ÿ