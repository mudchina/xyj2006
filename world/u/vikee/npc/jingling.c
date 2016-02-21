#include <ansi.h>
inherit NPC;
void create()
{
set_name(""HIR"公正法官"NOR"", ({"judger"}));
set("gender", "男性");
set("age", 20);
set("per", 30);
 set("combat_exp", 5000);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set("gin", 500);
  set("max_gin", 500);
  set("kee", 500);
  set("max_kee", 500);
  set("sen", 500);
  set("max_sen", 500);
  set("force", 150);
  set("max_force", 150);
  set("mana", 150);
  set("max_mana", 150);
  set("force_factor", 10);
  setup();
  carry_object("/d/obj/cloth/magua")->wear();
}

