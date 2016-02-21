// by snowcat oct 15 1997

inherit NPC;

void create()
{
  set_name("¹¬åú", ({"gong fei","girl"}));
  set("gender", "Å®ĞÔ");
  set("combat_exp", 10000);
  set("age", 15);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);

  setup();
  carry_object("/d/qujing/baoxiang/obj/gongpao")->wear();
}

