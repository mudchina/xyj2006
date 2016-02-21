// created 12/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("µÀÊ¿", ({"dao shi", "xie gong", "xie", "shi"}));
  set("title", "Ë«Í·Ğ«¹«");
  set("gender", "ÄĞĞÔ");
  set("age", 80);
  set("attitude", "aggressive");
  set("combat_exp", 3500000);
  set("daoxing", 2000000);

  set_skill("dodge", 260);
  set_skill("parry", 260);
  set_skill("force", 260);
  set_skill("spells", 260);
  set_skill("unarmed", 260);
  set_skill("gouhunshu", 260);
  set_skill("tonsillit", 260);
  set_skill("ghost-steps", 100);
  set_skill("jienan-zhi", 260);
  set("con", 30);
  set("cor", 30);
  set("int", 20);
  set("per", 20);
  set("spi", 10);
  set("cps", 10);
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");

  set("eff_dx",-320000);
  set("nkgain",400);

  set("max_gin", 3700);
  set("max_kee", 3700);
  set("max_sen", 3700);
  set("force", 3700);
  set("max_force", 3700);
  set("mana", 3700);
  set("max_mana", 3700);
//  set("force_factor", 30);
  set("mana_factor", 90);

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void unconcious()
{
  object shell = new ("/d/obj/misc/shell");

  shell->move(environment(this_object()));
  message_vision ("\n$N»ëÉíÒ»ÈíÌ±ÔÚµØÉÏ£¬»¯×öÒ»¶Ñ¿Õ¿ÕµÄ³æ¿Ç¡£\n",
                  this_object());
  destruct(this_object());
}

void die()
{
  object shell = new ("/d/obj/misc/shell");

  shell->move(environment(this_object()));
  message_vision ("\n$N»ëÉíÒ»ÈíÌ±ÔÚµØÉÏ£¬»¯×öÒ»¶Ñ¿Õ¿ÕµÄ³æ¿Ç¡£\n",
                  this_object());
  destruct(this_object());
}

ÿ