inherit NPC;

void create()
{
  set_name("Öí±ø", ({ "zhu bing", "zhu", "bing" }));
  set("age", 28);
  set("gender", "ÄÐÐÔ");
  set("attitude", "peaceful");
  set("str", 40);
  set("combat_exp", 50000);
  set("daoxing", 20000);

  set("max_kee", 500);
  set("max_sen", 500);
  set("max_force", 500);
  set("force", 500);
  set("force_factor", 50);
  set("mana_factor", 50);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set_skill("rake", 30);
  set_skill("force", 30);
  set_skill("baguazhou", 30);
  set_skill("yanxing-steps", 30);
  set_skill("skyriver-rake", 30);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  setup();
  carry_object("/d/obj/weapon/rake/gangpa")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}

void inint ()
{
  call_out ("looking",1,this_player());
}

void looking (object who)
{
  command ("look "+who->query("id"));
}

ÿ