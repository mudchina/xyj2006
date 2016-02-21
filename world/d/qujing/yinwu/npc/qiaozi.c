// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("éÔ×Ó", ({"qiao zi","zi"}));
  set("gender", "ÄÐÐÔ");
  set("age", 30);
  set("combat_exp", 10000);
  set("per", 25);
  set_skill("parry", 40);
  set_skill("unarmed", 40);
  set_skill("dodge", 50);
  set("max_sen",400);
  set("max_gee",400);
  set("max_gin",400);
  set("force",400);
  set("max_force",400);
  set("max_mana",400);
  set("force_factor",30);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/obj/weapon/axe/tiefu")->wield();
}
