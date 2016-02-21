// snowcat 12 14 1997

inherit NPC;

void create()
{
  set_name("ÏÉÍ¯", ({ "xian tong", "xian", "tong" }));
  set("gender", "ÄÐÐÔ");
  set("age", 10);
  set("attitude", "peaceful");
  set("str",30);
  set("per",30);
  set("max_kee", 200);
  set("max_gin", 200);
  set("max_sen", 200);
  set("force", 300);
  set("max_force", 300);
  set("force_factor", 10);
  set("max_mana", 300);
  set("mana", 300);
  set("mana_factor", 10);
  set("combat_exp", 60000);
  set("daoxing", 100000);

  set_skill("spells", 20);
  set_skill("buddhism", 20);
  set_skill("unarmed", 20);
  set_skill("jienan-zhi", 20);
  set_skill("dodge", 20);
  set_skill("lotusmove", 20);
  set_skill("parry", 20);
  set_skill("force", 20);
  set_skill("lotusforce", 20);
  set_skill("staff", 20);
  set_skill("lunhui-zhang", 20);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");

  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
}

ÿ