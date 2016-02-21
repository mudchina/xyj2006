#include <ansi.h>

inherit __DIR__"beast.c";

void create()
{
  set_name(HIW"九色神鹿"NOR, ({"jiuse shenlu", "shenlu"}));
  set("race", "野兽");
  set("age", 100);
  set("long", "一头花角九色梅花鹿，四蹄上似乎有风云滚起。\n");
  set("daoxing", 1500000);

  set("combat_exp", 300000);
  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));

  set("max_kee", 3000);
  set("kee", 3000);
  set("max_sen", 3000);
  set("sen", 3000);

  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("unarmed", 200);

  set("ride/need_train", 1);
  set("ride/msg", "骑");
  set("ride/dodge", 80);

  set_temp("apply/dodge", 100);
  set_temp("apply/attack",100);
  set_temp("apply/armor", 100);

  setup();
}





  
