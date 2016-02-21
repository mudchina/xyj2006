//Cracked by Roath

inherit NPC;

void create()
{
  set_name("±ÜË®½ğ¾¦ÊŞ", ({"jinjing shou", "shou"}));
  set("under_water",1);

  set("long", "Ò»Í·Ë«íø·Å¹â£¬ÒøÕÆÓñ°°µÄ½ğ¾¦ÊŞ£¬ÉÏÌìÈëº££¬ÈçÂÄÆ½µØ¡£\n");
  set("race", "Ò°ÊŞ");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "Æï");
  set("ride/dodge", 35);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}

ÿ
