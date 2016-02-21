inherit NPC;
void create()
{
        set_name("ÀÏ»¢¾«", ({"laohu jing", "jing"}));
        set("long", "Ò»¸öÐ×Éñ¶ñÉ·°ãµÄÀÏ»¢¾«£¬ÕÅ×ÅÑªÅè´ó¿Ú£¬Òª³ÔÈËµÄÑù×Ó¡£\n");
        set("age", 30);
        set("attitude", "aggressive");
	set("bellicosity", 1000);
        set("gender", "ÄÐÐÔ");
	set("class", "yaomo");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",1000);
        set("max_sen", 900);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 50);
        set("combat_exp", 350000);
  set("daoxing", 100000);


	set("eff_dx", -150000);
        set("nkgain", 400);

        set("force", 500);
        set("max_force", 500);
        set("mana",100);
        set("max_mana", 100);
        set("force_factor", 40);
        set("mana_factor", 10);
        set_skill("unarmed", 90);
        set_skill("force", 90);
        set_skill("spells", 90);
        set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("blade", 90);
	set_skill("wuhu-blade", 90);
	map_skill("blade", "wuhu-blade");
	map_skill("parry", "wuhu-blade");
	set_weight(5000000);
        setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
}
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{

        this_object()->add("time", 1);

        if( (int)this_object()->query("time") >= 10 ) {
        message("vision",name() + "Ò»¸ö»¢Ìø£¬×êÈë²Ý´ÓÖÐ²»¼ûÁË¡£\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

void die()
{
	object skirt, env;
        if( environment() ) {
        message("sound", "\nÀÏ»¢¾«¼ûÊÆ²»ºÃ£¬ºöÈ»°ÇÏÂ×Ô¼ºµÄÆ¤À´£¬±ä³ÉÒ»¸öÀÏ»¢Ä£Ñù¡£\n", environment());

		seteuid(getuid());
		if( skirt=new("/d/qujing/bibotan/obj/hupiqun") )
		skirt->move(environment());
		message("vision", "¾ÍÔÚÕâÒ»»Ðã±Ö®¼û£¬ÕæÉíÒ»¸ö»¢Ìø£¬×êÈë²Ý´ÓÖÐ²»¼ûÁË¡£\n",environment());
        }
	env=environment(this_object());
	env->set("done", 1);
        destruct(this_object());
}

ÿ