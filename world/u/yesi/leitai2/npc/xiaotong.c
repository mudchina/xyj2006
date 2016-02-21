// created by snowcat

inherit NPC;

void create()
{
  set_name("小童", ({"xiao tong", "tong"}));
  set("gender", "男性");
  set("age", 10);
  set("per", 25);
  set("long", "一位头上扎鬏的小童。\n");
  set("attitude", "friendly");
  set("max_kee", 200);
  set("max_gin", 200);
  set("max_sen", 200);
  set("force", 200);
  set("max_force", 200);
  set("mana", 200);
  set("max_mana", 200);
  set("combat_exp", 5000);
  set("force_factor", 5);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}


