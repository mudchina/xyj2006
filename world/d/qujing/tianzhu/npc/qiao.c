#include <ansi.h>

inherit NPC;

void create()
{
  set_name("乔老板", ({ "qiao laoban", "qiao", "laoban" }) );
  set("gender", "男性");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 500);
  set("max_gin", 500);
  set("force", 500);
  set("max_force", 500);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 50);
  set_skill("parry", 50);
  set_skill("dodge", 50);
  set_skill("blade", 50);
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));

  setup();

  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/obj/weapon/blade/caidao");
}

int random_move ()
{
  object me = this_object ();

  if (random(2))
    message_vision ("$N卷起袖子。\n",me);
  else
    message_vision ("$N拿起一把剁肉刀，想想又将刀往桌边一扔。\n",me);
}

