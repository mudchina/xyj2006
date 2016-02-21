inherit NPC;

void create()
{
  set_name("ÓíÍõ×ä", ({ "yuwang zu", "zu" }));
  set("age", 18+random(10));
  set("gender", "ÄÐÐÔ");
  set("attitude", "peaceful");
  set("str", 20);
  set("combat_exp", 20000);
  set("daoxing", 20000);

  set("max_kee", 400);
  set("max_sen", 400);
  set("max_force", 200);
  set("force", 200);
  set("force_factor", 10);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("mace", 40);
  set_skill("force", 40);

  setup();
  carry_object("/d/obj/weapon/mace/copperjian")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}



ÿ