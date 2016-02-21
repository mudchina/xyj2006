#include <ansi.h>

inherit NPC;

void create()
{
  set_name("乐老板", ({ "le laoban", "le", "laoban" }) );
  set("gender", "男性");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 200);
  set("max_gin", 200);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));

  setup();

  carry_object("/d/qujing/tianzhu/obj/huapao")->wear();
  carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}

int random_move ()
{
  object me = this_object ();

  if (random(2))
    message_vision ("$N哈哈仰天大笑。\n",me);
  else
    message_vision ("$N哈哈哈哈地笑了几声。\n",me);
}

