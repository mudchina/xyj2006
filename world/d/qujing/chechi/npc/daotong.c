// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("µÀÍ¯", ({"dao tong", "dao", "tong"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 10000);
  set("daoxing", 10000);

  set("age", 15);
  set("per", 20);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",3);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",300);
  set("max_mana",300);
  set_skill("unarmed", 30+random(90));
  set_skill("dodge", 30+random(90));
  set_skill("parry", 30+random(90));
  set_skill("force", 30+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


ÿ