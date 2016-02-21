inherit NPC;

void create()
{
  set_name("水蛇", ({"shui she","she","snake"}));
  set("race", "野兽");
  set("long","一条水蛇，钻在岸边的水草中游来游去。\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "头部","七寸", "身体", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
