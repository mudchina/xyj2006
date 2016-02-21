inherit NPC;


void create()
{

  set_name("蝴蝶", ({"hu die","die","butterfly"}));
  set("race", "野兽");
  set("age", 10);
  set("long", "一只小蝴蝶。\n");

  set_skill("dodge", 10);
  set("combat_exp", 100);
  set("limbs", ({ "头部", "身体", "前腿","後腿", "尾巴" }) );
  set("verbs", ({ "bite"}));

  setup();

  set("chat_msg", ({
    (: random_move :),
    }) );
  set("chat_chance", 50);
}
