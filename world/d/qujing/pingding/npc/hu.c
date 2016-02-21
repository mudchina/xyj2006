// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("°ÍÉ½»¢", ({ "bashan hu", "bashan", "hu" }));
  set("gender", "ÄÐÐÔ");
  set("age", 34);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 600);
  set("max_gin", 600);
  set("max_sen", 600);
  set("force", 600);
  set("max_force", 600);
  set("force_factor", 30);
  set("max_mana", 600);
  set("mana", 600);
  set("mana_factor", 30);
  set("combat_exp", 500000);
  set("daoxing", 500000);

  set_skill("spells", 50);
  set_skill("dao", 50);
  set_skill("unarmed", 50);
  set_skill("puti-zhi", 50);
  set_skill("dodge", 50);
  set_skill("jindouyun", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("wuxiangforce", 50);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

ÿ