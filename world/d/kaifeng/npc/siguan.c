inherit NPC;

#include <greeting.h>

void create()
{
  set_name("ËÅ¹Ù", ({ "si guan", "si", "guan" }));
  set("age", 18+random(10));
  set("gender", "ÄÐÐÔ");
  set("attitude", "peaceful");
  set("str", 20);
  set("combat_exp", 30000);
  set("max_kee", 500);
  set("max_sen", 500);
  set("max_force", 200);
  set("force", 200);
  set("force_factor", 10);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("sword", 50);
  set_skill("force", 50);

  setup();
  carry_object("/d/obj/weapon/sword/changjian")->wield();
  carry_object("/d/obj/cloth/changpao")->wear();
}

