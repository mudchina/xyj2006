#include <ansi.h>

inherit __DIR__"beast.c";

void create()
{
  set_name("青毛狮", ({"qingmao shi", "shi"}));
  set("race", "野兽");
  set("age", 20);
  set("long", "一头青毛狮子，端是百兽之王。\n");
  set("daoxing", 150000);
  set("combat_exp", 150000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("attitude", "aggressive");
  set("max_kee", 800);
  set("kee", 800);
  set("max_sen", 900);
  set("sen", 900);

  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("unarmed", 150);

  set("ride/need_train", 1);
  set("ride/msg", "骑");
  set("ride/dodge", 30);

  set_temp("apply/dodge", 40);
  set_temp("apply/attack", 40);
  set_temp("apply/armor", 40);

  setup();
}

