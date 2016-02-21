inherit NPC;

void create()
{
  set_name("麻雀", ({"maque"}));
  set("race", "野兽");
  set("age", 20);
  set("long", "一只小麻雀，钉在树梢儿上。\n");
  set("combat_exp", 50000);
  set("limbs", ({ "头部", "身体", "翅膀", "左脚","右脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
