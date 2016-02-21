inherit NPC;

void create()
{
        set_name("ÍòÊ¥ÁúÍõ", ({"wansheng longwang", "longwang", "long"}));
        set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄÀÏÁúÍõ¡£\n");
        set("age", 68);
        set("attitude", "peaceful");
        set("gender", "ÄÐÐÔ");
	set("class", "dragon");
        set("str", 30);
        set("int", 30);
        set("per", 10);
        set("con", 30);
        set("max_kee",1000);
        set("max_sen", 1000);
        set("combat_exp", 700000);
  set("daoxing", 1000000);

        set("force", 1000);
        set("max_force", 1000);
        set("mana", 800);
        set("max_mana", 800);
        set("force_factor", 40);
        set("mana_factor", 40);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("spells", 100);
        set_skill("dodge", 100);
        set_skill("dragonfight", 100);
        set_skill("dragonstep", 100);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        setup();
        carry_object("/d/sea/obj/longpao")->wear();

}

void unconcious()
{
        object me,obj;   
        if( !me = query_temp("last_damage_from") )
		me= this_player(1);
        if( environment() ) {
        message("sound", "\n\nÍòÊ¥ÁúÍõÅ­µÀ£ºÄã¾¹¸ÒÆÛÈËÌ«Éõ£¡\n\n", environment());
        message("sound", "\nÍòÊ¥ÁúÍõ°ë¿ÕÖÐÒ»×ª£¬ÏÖÁËÕæÉí£¡¾¹ÊÇÒ»ÌõÎå×¦½ðÁú£¡\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon"); 
                obj->move(environment(me));
		obj->kill_ob(me);
		me->fight_ob(obj);
        }

        destruct(this_object());
}

void die()
{
        object me,obj;
        if( !me = query_temp("last_damage_from") )
                me= this_player(1);
        if(environment() ) {
        message("sound", "\n\nÍòÊ¥ÁúÍõÅ­µÀ£ºÄã¾¹¸ÒÆÛÈËÌ«Éõ£¡\n\n", environment());
        message("sound", "\nÍòÊ¥ÁúÍõ°ë¿ÕÖÐÒ»×ª£¬ÏÖÁËÕæÉí£¡¾¹ÊÇÒ»ÌõÎå×¦½ðÁú£¡\n\n", environment());
                seteuid(getuid());
                obj=new("/d/qujing/bibotan/npc/dragon");
		if (this_object()->query_temp("longjin_kill"))
			obj->set_temp("longjin_kill",this_object()->query_temp("longjin_kill"));
		        obj->move(environment(me));
                obj->kill_ob(me);
                me->fight_ob(obj);
        }

        destruct(this_object());
}

ÿ