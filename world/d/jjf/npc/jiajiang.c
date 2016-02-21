// jiading.c 家丁

inherit NPC;

void create()
{
  set_name("家将", ({ "jia jiang", "jia", "jiang"}));
  set("gender", "男性");
  set("age", 19+random(30));
  
  set("combat_exp", 200000+random(50000));
  set_skill("spear", 70);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("unarmed", 70);
  set("force", 500);
  set("max_force",400);
  setup();

  carry_object("/d/obj/cloth/bingfu")->wear();
  carry_object("/d/obj/weapon/spear/muqiang")->wield();
  add_money("silver", 2+random(5));

}
	
