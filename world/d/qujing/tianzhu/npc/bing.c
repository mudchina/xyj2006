// snowcat 12 9 1997

inherit NPC;

void create()
{
  set_name("¹¬±ø", ({ "gong bing", "bing" }) );
  set("gender", "ÄÐÐÔ");
  set("age", 35);
  set("combat_exp", 60000+random(20000));
  set("daoxing", 20000);

  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 600);
  set("max_gin", 600);
  set("force", 600);
  set("max_force", 600);
  set("force_factor", random(50)+25);
  set_skill("unarmed", 80);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("blade", 80);
  setup();

  carry_object("/d/obj/weapon/blade/wandao")->wield();
  carry_object("/d/qujing/tianzhu/obj/tiekui")->wear();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}


ÿ