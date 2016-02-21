// snowcat 12 14 1997

inherit NPC;

void create()
{
  if (random(2))
  {
    set_name("ÓÅÆÅÈû", ({ "youpo sai", "youpo", "sai" }));
    set("gender", "ÄÐÐÔ");
  }
  else
  {
    set_name("ÓÅÆÅÒÄ", ({ "youpo yi", "youpo", "yi" }));
    set("gender", "Å®ÐÔ");
  }
  set("title", "ÁéÉ½");
  set("age", 60);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_kee", 800);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 40);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 200000);
  set("daoxing", 300000);

  set_skill("spells", 60);
  set_skill("buddhism", 60);
  set_skill("unarmed", 60);
  set_skill("jienan-zhi", 60);
  set_skill("dodge", 60);
  set_skill("lotusmove", 60);
  set_skill("parry", 60);
  set_skill("force", 60);
  set_skill("lotusforce", 60);
  set_skill("staff", 60);
  set_skill("lunhui-zhang", 60);
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