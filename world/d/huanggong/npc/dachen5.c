// by snowcat

inherit NPC;

#include <reporting.h>

void create()
{
  set_name("孟子如", ({ "meng ziru", "meng", "ziru", "da chen" }));
  set("title", "大臣");
  set("gender", "男性");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
}

void reward (object who)
{
  object me = this_object ();
  int points = who->query_temp("quest/reward_point");
  object silver = new ("/obj/money/silver");
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

//  points = points * 10;
  points = points * 15;
  if(points>2000)
      points=2000;
  message_vision ("$N对$n一拜：陛下有旨，赐"+RANK_D->query_respect(who)+
                  chinese_number(points)+"两白银！\n",me,who);
/*  
  command (channel+" "+who->query("name")+who->query("quest/reason")+"陛下有旨，赐"+
           chinese_number(points)+"两白银！\n");
*/  
  who->add("quest/gain/silver",points);
  reporting (who, who->query("quest/reason"), points, "两白银");
  
  silver->set_amount(points);
  if(!(silver->move(who)))
    silver->move(environment(who));
  message_vision ("$N递给$n一包白银。\n",me,who);
}

