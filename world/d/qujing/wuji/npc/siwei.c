// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("ËÅÎÀ¹Ù", ({"siwei guan", "guan"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 100000);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",10);
  set("max_gin",500);
  set("max_kee",500);
  set("max_sen",500);
  set("max_force",600);
  set("max_mana",600);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

