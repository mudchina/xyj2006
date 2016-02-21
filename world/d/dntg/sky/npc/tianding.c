// tian-ding1.c
// created 4-8-97 pickle
#include <ansi.h>
inherit NPC;

varargs void drool(string msg, string who);

void create()
{
  string name, id;


  set_name("天丁", ({ "tian ding", "tian", "ding" }) );
  set("gender", "男性" );
  set("long", "

增长天王手下八大天王之一，正在这里仔细的寻查
每一个过往行人。
");
  set("title", "大力天丁");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 27);
  set("int", 25);
  set("combat_exp",400000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 20);
  set("max_kee", 900);
  set("max_sen", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
  set_skill("unarmed",99);
  set_skill("dodge",99);
  set_skill("parry",99);
  set_skill("spear",99);
  set_skill("force",99);
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}
