//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

string *names = ({
  "³¤ÉàÑý",
  "ÈýÍÈÑý",
  "É¨°ÑÑý",
  "¶ÏÍ·Ñý",
});

void create()
{
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("race", "Ò°ÊÞ");
  set("age", 100+random(201));
  set("combat_exp", 500000+random(500001));
  set("daoxing", 500000+random(500001));
  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "Î²°Í", "¶ÇÆ¤", "ºó×¦"}) );
  set("verbs", ({ "bite", "claw"}) );
  set("attitude", "aggressive");
  set("per", 10);
  set_skill("parry", 200);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("blade", 200);
  set("max_sen",2000);
  set("max_kee",2000);
  set("force",2000);
  set("max_force",1500);
  set("max_mana",1500);
  set("force_factor",50);
  set("mana",2000);
  set("mana_factor",50);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jilei/obj/armor")->wear();
  carry_object("/d/obj/weapon/blade/fengdao")->wield();
}
