inherit NPC;

string *names = ({
  "青鬃马",
  "灰鬃马",
  "枣红马",
  "长鬃马",
  "花骠马",
  "高背马",
  "短腿马",
  "细腿马",
  "宽背马",
  "花斑马",
  "白马",
  "黑马",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"horse", "ma"}));
  set("race", "野兽");
  set("age", 10);

  set_skill("dodge", 60);
  set("combat_exp", 10000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "骑");
  set("ride/dodge", 10+random(6));
  set_temp("apply/attack", 10);
  set_temp("apply/armor", 20);

  setup();
}

