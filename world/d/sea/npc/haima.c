inherit NPC;

void create()
{
        set_name("½ğ±³º£Âí", ({"hai ma", "ma"}));
        set("race", "Ò°ÊŞ");
        set("age", 25);
        set("long", "Ò»Ö»½ğ±³µÄ´óº£Âí£¬ÊÇÁúÉÙÒ¯µÄ×ùÆï¡£\n");
        set("attitude", "friendly");

     set("under_water",1);
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 10000);
  set("daoxing", 20000);


	set("ride/msg", "Æï");
  	set("ride/dodge", 15);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 20);

        setup();
}


ÿ
