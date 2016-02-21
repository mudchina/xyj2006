#include <ansi.h>

inherit NPC;

void create()
{
  set_name("歌女", ({ "ge nu", "nu" }) );
  set("gender", "女性");
  set("age", 15);
  set("combat_exp", 2000);

  set("str", 10);
  set("max_kee", 100);
  set("max_gin", 100);
  set("force", 100);
  set("max_force", 100);
  set("force_factor", 4);
  set_skill("unarmed", 10);
  set_skill("parry", 10);
  set_skill("dodge", 10);
  set_skill("blade", 10);
  set("chat_chance", 25);
  set("chat_msg", ({ (: random_move :) }));

  setup();

  carry_object("/d/obj/cloth/skirt")->wear();
}

int random_move ()
{
  object me = this_object();
  string *strs = ({
    "$N迷人一笑。\n",
    "$N张开樱桃小口轻唱起来。\n",
    "$N面颊桃红，唱着曲儿。\n",
  });

  message_vision (strs[random(sizeof(strs))],me);
  return 1;
}
