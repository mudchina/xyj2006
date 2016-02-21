#include <ansi.h>

inherit NPC;

void create()
{
  set_name("府令", ({ "fu ling", "ling" }) );
  set("gender", "男性");
  set("age", 50);
  set("combat_exp", 120000);
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 600);
  set("max_gin", 600);
  set("force", 600);
  set("max_force", 600);
  set("force_factor", random(30)+15);
  set_skill("unarmed", 60);
  set_skill("parry", 60);
  set_skill("dodge", 60);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();
}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jinping") == "done")
    return;
  if (who->query_temp("obstacle/jinping_oil") < 10)
    return;
  if (! who->query_temp("obstacle/jinping_pi1_killed"))
    return;
  if (! who->query_temp("obstacle/jinping_pi2_killed"))
    return;
  if (! who->query_temp("obstacle/jinping_pi3_killed"))
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/jinping","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"金平府灯会解难，青龙山除犀牛精！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
 who->save();
}
