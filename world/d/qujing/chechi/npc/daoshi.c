// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("µÀÊ¿", ({"dao shi", "dao", "shi"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 20000);
  set("daoxing", 40000);

  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",5);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);
  set_skill("unarmed", 40+random(90));
  set_skill("dodge", 40+random(90));
  set_skill("parry", 40+random(90));
  set_skill("force", 40+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


ÿ