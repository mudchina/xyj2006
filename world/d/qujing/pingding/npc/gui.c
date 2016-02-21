// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("¾«Ï¸¹í", ({ "jingxi gui", "jingxi gui", "gui" }));
  set("gender", "ÄÐÐÔ");
  set("age", 24);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 500);
  set("max_gin", 500);
  set("max_sen", 500);
  set("force", 500);
  set("max_force", 500);
  set("force_factor", 20);
  set("max_mana", 500);
  set("mana", 500);
  set("mana_factor", 20);
  set("combat_exp", 400000);
  set("daoxing", 500000);

  set_skill("spells", 40);
  set_skill("dao", 40);
  set_skill("unarmed", 40);
  set_skill("puti-zhi", 40);
  set_skill("dodge", 40);
  set_skill("jindouyun", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("wuxiangforce", 40);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

ÿ