inherit NPC;

void create()
{
        set_name("Îå×¦½ðÁú", ({ "golden dragon", "dragon" }) );
        set("race", "Ò°ÊÞ");
        set("gender", "ÐÛÐÔ");
        set("age", 100);
        set("long", "Ò»Ö»ÂúÉí½ð¼×µÄÎå×¦½ðÁú¡£\n");
        set("attitude", "peaceful");
        set("looking", "Íþ·çÁÝÁÝ£¬ÆøÊÆ±ÆÈË¡£");
        set("str", 40);
        set("con", 40);
        set("max_kee", 2000);
        set("max_sen", 2000);
	set("max_force", 1000);
	set("force", 1500);
	set("max_mana", 1000);
	set("mana", 1500);
	set("force_factor", 50);
	set("mana_factor", 50);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "ºó×¦", "Î²°Í"}) );
        set("verbs", ({ "bite", "claw"}) );
        set("combat_exp", 1400000);
  set("daoxing", 1000000);

	set("eff_dx", -500000);
	set("nkgain", 500);
        set_skill("dodge", 179);
        set_skill("parry", 179);
        set_skill("force", 179);
	set_skill("spells", 179);
        set_skill("unarmed", 179);
        set_temp("apply/damage", 40);
	set_temp("apply/armor", 60);	
	set_weight(5000000);
        setup();
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);
        set("chat_msg", ({
	    "Îå×¦½ðÁúÔÚ°ë¿ÕÖÐÅÌÐýÁË¼¸È¦¡£\n",
            "Îå×¦½ðÁú·¢³öÒ»ÕóÁúÒ÷¡£\n",
        }) );
}


int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 0);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{       object obj;
	this_object()->add("time", 1);
	if( (int)this_object()->query("time") < 6 )  return;

        message("vision",name() + "¿ÕÖÐÉíÐÎÒ»±ä£¬ÓÖ±ä³ÉÁúÍõÄ£Ñù¡£\n", environment(), this_object() );
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/longwang");
                obj->move(environment(this_object()));
        destruct(this_object());
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
			  longjin->set_temp("iambaddragon",1);
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
    ::die();
}



ÿ