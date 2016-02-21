// dummy.c
// created 9-15.97 pickle

/************************************************************/
// global declaractions etc.

#include <ansi.h>
inherit NPC;

/************************************************************/

void create()
{
  set_name("²âÊÔ´óÃ×", ({"crash test dummy", "dummy"}));
  set("gender", "ÄÐÐÔ");
  set("age", 20+random(15));
  set("str", 5);
  set("attitude", "peaceful");
  set("combat_exp", 100000);
  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("kugu-blade", 100);
  map_skill("blade", "kugu-blade");
  map_skill("parry", "kugu-blade");
  map_skill("dodge", "kugu-blade");

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
}

/************************************************************/

