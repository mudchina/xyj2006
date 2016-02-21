inherit NPC;

string *names = ({
"Ğ¡Ã«Â¿",
"»¨Ã«Â¿",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"mao lu", "lu"}));
  set("race", "Ò°ÊŞ");
  set("age", 10);

  set("combat_exp", 10000);
  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "áá½Å", "Î²°Í" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "µ¹Æï");
  set("ride/dodge", 10+random(10));
  set_temp("apply/attack", 10);
  set_temp("apply/armor", 20);

  setup();
}

