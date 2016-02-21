// snowcat 12 14 1997

inherit NPC;

void create()
{
  if (random(2))
  {
    set_name("±ÈÇðÉ®", ({ "biqiu seng", "biqiu", "seng" }));
    set("gender", "ÄÐÐÔ");
  }
  else
  {
    set_name("±ÈÇðÄá", ({ "biqiu ni", "biqiu", "ni" }));
    set("gender", "Å®ÐÔ");
  }
  set("title", "ÁéÉ½");
  set("age", 80);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 1200);
  set("max_gin", 1200);
  set("max_sen", 1200);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 60);
  set("max_mana", 1200);
  set("mana", 1200);
  set("mana_factor", 60);
  set("combat_exp", 600000);
  set("daoxing", 800000);

  set_skill("spells", 70);
  set_skill("buddhism", 70);
  set_skill("unarmed", 70);
  set_skill("jienan-zhi", 70);
  set_skill("dodge", 70);
  set_skill("lotusmove", 70);
  set_skill("parry", 70);
  set_skill("force", 70);
  set_skill("lotusforce", 70);
  set_skill("staff", 70);
  set_skill("lunhui-zhang", 70);
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