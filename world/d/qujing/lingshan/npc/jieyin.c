// snowcat 12 14 1997

inherit NPC;

void create()
{
  set_name("½ÓÒý·ð×æ", ({ "jieyin fuzu", "jieyin", "fuzu" }));
  set("title", "ÁéÉ½");
  set("gender", "ÄÐÐÔ");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 3000);
  set("max_gin", 3000);
  set("max_sen", 3000);
  set("force", 3000);
  set("max_force", 3000);
  set("force_factor", 100);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 100);
  set("combat_exp", 1500000);
  set("daoxing", 3000000);

  set_skill("literate", 120);
  set_skill("spells", 120);
  set_skill("buddhism", 120);
  set_skill("unarmed", 120);
  set_skill("jienan-zhi", 120);
  set_skill("dodge", 120);
  set_skill("lotusmove", 120);
  set_skill("parry", 120);
  set_skill("force", 120);
  set_skill("lotusforce", 120);
  set_skill("staff", 120);
  set_skill("lunhui-zhang", 120);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );

  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

ÿ