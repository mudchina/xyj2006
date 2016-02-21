// created 1/15/1999 by smile
#include <ansi.h>
inherit NPC;

string *prefixs = ({
  "黑脸",
  "青面",
  "白眉",
  "黄牙",
  "紫须",
  "蓝耳",
});


void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+"僵尸", ({"jiang shi", "shi"}));
  set("title", "僵尸");
  set("gender", "男性");
  set("age", 100);
  set("attitude", "aggressive");
  set("combat_exp", 2000000);
  set_skill("dodge", 240);
  set_skill("parry", 240);
  set_skill("force", 240);
  set_skill("spells", 240);
  set_skill("unarmed", 240);
  set("con", 30);
  set("cor", 30);
  set("int", 20);
  set("per", 20);
  set("spi", 10);
  set("cps", 10);

  set("eff_dx",-26000);
  set("nkgain",400);

  set("max_gin", 2800);
  set("max_kee", 2800);
  set("max_sen", 2800);
  set("force", 2800);
  set("max_force", 2800);
  set("mana", 3500);
  set("max_mana", 3500);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void unconcious()
{
   die();
}

void die()
{
  message_vision ("\n$N浑身一软瘫在地上，散落在地上化做一摊黄水。\n",
                  this_object());
    destruct(this_object());
}

