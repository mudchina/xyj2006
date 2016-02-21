// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("¾üÊ¿", ({"jun shi", "jun", "shi"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 50000+random(50000));
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",30);
  set("max_gin",500);
  set("max_kee",500);
  set("max_sen",500);
  set("max_force",600);
  set("max_mana",600);
  set_skill("unarmed", 60);
  set_skill("spear", 60);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 60);
  set_skill("spells", 60);
  setup();
  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/obj/cloth/zhanpao")->wear();
  switch (random(6))
  {
    case 0 :
    {
      carry_object("/d/obj/weapon/spear/tieqiang")->wield();
      break;
    }
    case 1 :
    {
      carry_object("/d/obj/weapon/axe/bigaxe")->wield();
      break;
    }
    case 2 :
    {
      carry_object("/d/obj/weapon/blade/blade")->wield();
      break;
    }
    case 3 :
    {
      carry_object("/d/obj/weapon/fork/fork")->wield();
      break;
    }
    case 4 :
    {
      carry_object("/d/obj/weapon/sword/changjian")->wield();
      break;
    }
    case 5 :
    {
      carry_object("/d/obj/weapon/rake/gangpa")->wield();
      break;
    }
  }
}

