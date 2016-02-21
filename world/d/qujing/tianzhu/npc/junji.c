// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  set_name("军机大臣", ({"jun ji", "ji"}));
  set("gender", "男性");
  set("age", 40);
  set("combat_exp", 20000);
  set_skill("parry", 60);
  set_skill("unarmed", 60);
  set_skill("dodge", 60);
  set("max_sen",800);
  set("max_gee",800);
  set("max_gin",800);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",20);
  setup();
  set_temp("no_return",1);
  carry_object("/d/qujing/tianzhu/obj/guanpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}


