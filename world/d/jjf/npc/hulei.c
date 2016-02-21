// dog.c

inherit NPC;

void create()
{
        set_name("ºôÀ×±ª", ({"hulei bao", "hulei", "horse", "ma"}));
        set("race", "Ò°ÊŞ");
        set("age", 20);

	set("combat_exp", 10000);
  set("daoxing", 5000);

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
        set("verbs", ({ "bite"}));

	set("ride/msg", "Æï");
        set("ride/dodge", 18);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 20);

        setup();
}

ÿ