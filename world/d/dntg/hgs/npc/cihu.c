inherit NPC;

void create()
{
  set_name("鹚鹄", ({"ci hu","bird"}));
  set("race", "野兽");
  set("long","一只大鹚鹄，张开一对大翅膀，在空中鸟瞰。\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "头部", "身体", "翅膀", "左脚","右脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
