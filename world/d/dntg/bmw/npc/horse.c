inherit NPC;

string *names = ({
  "骅骊马",
  "骐骥马",
  "紫燕马",
  "超光马",
  "赤兔马",
  "追风马",
  "奔霄马",
  "绝尘马",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"horse", "ma"}));
  set("race", "野兽");
  set("age", 20);
  set("long", "一匹能腾云驾雾的天马。\n");
  set("combat_exp", 50000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("unarmed", 100);
  set("ride/msg", "骑");
  set("ride/dodge", 20+random(6));
  set_temp("apply/dodge", 40);
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

