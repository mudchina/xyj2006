inherit NPC;

void create()
{
  set_name("鱼儿", ({"fish","yu"}));
  set("race", "野兽");
  set("long","一条不起眼的鱼儿，似鲤鱼，尾巴不红；似鳜鱼，花鳞不见；\n似黑鱼，头上无星；似鲂鱼，腮上无针。\n");
  set("age", 20);
  set("combat_exp", 50000);
  set("limbs", ({ "头部", "身体", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set_skill("dodge", 20);
  set_skill("parry", 20);
  set_skill("unarmed", 20);

  setup();
}
