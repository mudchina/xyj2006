// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("¼À¹Ù", ({"ji guan", "guan"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",12);
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  carry_object("/d/obj/weapon/blade/jidao")->wield();
}

ÿ