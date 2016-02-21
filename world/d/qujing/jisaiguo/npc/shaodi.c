inherit NPC;

void create()
{
       set_name("Ğ¡ºÍÉĞ", ({"heshang", "heshang"}));
       set("gender", "ÄĞĞÔ");
       set("age", 16);
        set("long", "Ò»¸öÍ·¶ù¹â¹âµÄĞ¡ºÍÉĞ¡£\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 18);
	set("str", 25);
       set("combat_exp", 1500);
  set("daoxing", 3000);

        set_skill("unarmed", 15);
	set_skill("stick", 15);
        set_skill("dodge", 15);
        set_skill("parry", 15);
setup();
	carry_object("/d/lingtai/obj/shaoba")->wield();
	carry_object("/d/obj/cloth/sengyi")->wear();
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
	switch( random(3) ) {
	case 0:
               say("Ğ¡ºÍÉĞÄÃ×Å°Ñ´óÖñÉ¨Öã£¬ÔÚµØÏÂ»®À­ÁËÁ½ÏÂ¡£\n");
	break;
	case 1:
		say("Ğ¡ºÍÉĞÃşÁËÃş¹âÍ·£¬¡¸ÎûÎûÎû¡¹µØĞ¦³öÁËÉù¡£\n");
	break;
	}
}

ÿ