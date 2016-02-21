inherit NPC;
void create()
{
        set_name("ÁøÊ÷¾«", ({"liushu jing", "jing"}));
        set("long", "Ò»¸öÄ£Ñù¼«ÏóÊ÷×®×ÓµÄÑı¹Ö£¬ÊÖÀïÌá×ÅÒ»½ØÊ÷¸É¡£\n");
        set("age", 30);
        set("attitude", "aggressive");
        set("gender", "ÄĞĞÔ");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
	set("looking", "»ëÉíÉÏÏÂ¾ÍÊÇÄ¾Í·£¬ÄÇÀïÓĞÊ²Ã´ÈİÃ²¡£");
        set("con", 30);
        set("max_kee",600);
        set("max_sen", 600);
	set_temp("apply/armor", 30);
	set("bellicosity", 2000);
        set("combat_exp", 60000);
  set("daoxing", 100000);


	set("eff_dx", -20000);
        set("nkgain", 200);

        set("force", 600);
        set("max_force", 600);
        set("mana",300);
        set("max_mana",200);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 40);
        set_skill("force", 40);
        set_skill("spells", 40);
        set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("staff", 40);
        setup();
	carry_object("/d/obj/weapon/staff/shugan")->wield();
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
	object stone;
	
	this_object()->add("time", 1);
	if( (int)this_object()->query("time") >= 15 ) {
        message("vision",name() + "Ò»¸ö×İÉí£¬Ìø»Øµ½Ê÷ÉÏ¡£\n", environment(),this_object() );
        destruct(this_object());

	}
	return;
}

ÿ