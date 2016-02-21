//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;


void create()
{
  set_name("白龙马", ({"bailong ma", "horse"}));
  set("race", "野兽");
  set("age", 10);

  set("combat_exp", 200000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "骑在");
  set("ride/dodge", 10+random(10));
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

