// horse.c

inherit NPC;

void create()
{
  set_name("枣红马", ({"zaohong ma", "ma", "horse"}));
  set("race", "野兽");
  set("age", 10);
  set("combat_exp", 10000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "骑");
  set("ride/dodge", 20);

  setup();
}


