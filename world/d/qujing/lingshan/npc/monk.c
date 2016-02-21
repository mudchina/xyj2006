// snowcat 12 14 1997

inherit NPC;

void create()
{
  if (random(2))
    set_name("°¢ÂÞ", ({ "a luo", "a", "luo" }));
  else
    set_name("½ÒÚÐ", ({ "jie di", "jie", "di" }));
  set("title", "ÁéÉ½");
  set("gender", "ÄÐÐÔ");
  set("age", 100);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 1800);
  set("max_gin", 1800);
  set("max_sen", 1800);
  set("force", 1800);
  set("max_force", 1800);
  set("force_factor", 80);
  set("max_mana", 1800);
  set("mana", 1800);
  set("mana_factor", 80);
  set("combat_exp", 1000000);
  set("daoxing", 1500000);

  set_skill("spells", 80);
  set_skill("buddhism", 80);
  set_skill("unarmed", 80);
  set_skill("jienan-zhi", 80);
  set_skill("dodge", 80);
  set_skill("lotusmove", 80);
  set_skill("parry", 80);
  set_skill("force", 80);
  set_skill("lotusforce", 80);
  set_skill("staff", 80);
  set_skill("lunhui-zhang", 80);
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