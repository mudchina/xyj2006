#include <ansi.h>

inherit __DIR__"beast.c";

void create()
{
  set_name("花斑豹", ({"huaban bao", "bao"}));
  set("race", "野兽");
  set("age", 20);
  set("long", "一头身带花斑的金钱大豹，象是要随时扑上来。\n");
  set("combat_exp", 150000);
  set("daoxing", 150000);
  set("attitude", "aggressive");
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("max_kee", 800);
  set("kee", 800);
  set("max_sen", 900);
  set("sen", 900);

  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("unarmed", 150);

  set("ride/need_train", 1);
  set("ride/msg", "骑");
  set("ride/dodge", 28);

  set_temp("apply/dodge", 40);
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

