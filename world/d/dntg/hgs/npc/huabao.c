inherit NPC;

void create()
{
  set_name("花鸨", ({"hua bao","bird"}));
  set("race", "野兽");
  set("long","一只花鸨，乃鸟中至贱之物。\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "头部", "身体", "翅膀", "左脚","右脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
