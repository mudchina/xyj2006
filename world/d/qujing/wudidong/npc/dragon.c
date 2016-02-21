
inherit NPC;
void create()
{
  set_name("¶ñÁú", ({"dragon"}));
  set("gender", "ÄÐÐÔ");
  set("long", "Ò»ÌõÕÅÑÀÎè×¦µÄ¶ñÁú£¬Ñù×ÓÊ®·Ö¿ÉÅÂ¡£\n");
  set("attitude", "peaceful");
//  set("attitude", "aggressive");
  set("combat_exp", 50000+random(1000000));
  set("daoxing", 500000);
  set("class","dragon");
  set("age", 100);
  set("per", 100);
  set("str", 30);
  set("int", 30);
  set("cor", 30);
  set("cps", 30);
  set("con", 30);
  set("max_kee", 500+random(1500));
  set("max_sen", 1000);
  set("force", 1000);
  set("max_force", 1000);
  set("max_mana", 600);
  set("mana",600);	
  set_skill("spells", 100);
  set_skill("force",100);
  set_skill("parry", 50+random(150));
  set_skill("dodge", 50+random(150));
  set_skill("unarmed", 50+random(150));
  set_skill("dragonstep", 50+random(150));
  set_skill("dragonfight", 50+random(150));
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");


  setup();
}

void die()
{
    object me,who,longjin,rope;
    string whoid;
	string rp="/d/obj/fabao/kunxian-suo.c";
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
			  longjin->set_temp("iambaddragon",1);
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
	if( rp->in_mud() )
    {
	rope = new(rp->query("replace_file"));
    }
    else
	rope = new(rp);
    if( environment() ) {
	message("vision", "Ò»Õóºì¹âÉÁ¹ý£¬¶ñÁúÂäÔÚµØÉÏ¡£¶¨¾¦Ò»¿´£¬Ô­À´¶ñÁúÒÑ¾­¶ÝÈ¥£¬µØÉÏÖ»ÁôÏÂÒ»ÌõºìË÷¡£\n", environment());
    }
    rope->move(environment(this_object()));
    destruct(this_object());
}
ÿ