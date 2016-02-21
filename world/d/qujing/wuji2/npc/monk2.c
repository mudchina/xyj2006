// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("ÊØËÂÉ®", ({"shousi seng", "seng"}));
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 1000+random(50000));
  set("age", 40+random(20));
  set("per", 14+random(20));
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",6);
  set("max_gin",600);
  set("max_kee",600);
  set("max_sen",600);
  set("max_force",400);
  set("max_mana",400);
  set_skill("unarmed", 30+random(90));
  set_skill("dodge", 30+random(90));
  set_skill("parry", 30+random(90));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
}



