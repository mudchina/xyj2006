// by snowcat

inherit NPC;

#include <reporting.h>

void create()
{
  set_name("张士衡", ({ "zhang shiheng", "zhang", "shiheng", "da chen" }));
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
  int limit = 40;
  int i = 10;
  string str;
  string name;
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  while (i--)
  {
    switch (random(8))
    {
      case 0: 
      {
        if (who->query_str() < limit)
        {
          str = "apply/strength";
          name = "膂力";
          break;
        }
      }
      case 1: 
      {
        if (who->query_cor() < limit)
        {
          str = "apply/courage";
          name = "胆识";
          break;
        }
      }
      case 2: 
      {
        if (who->query_int() < limit)
        {
          str = "apply/intelligence";
          name = "悟性";
          break;
        }
      }
      case 3: 
      {
        if (who->query_spi() < limit)
        {
          str = "apply/spirituality";
          name = "灵性";
          break;
        }
      }
      case 4: 
      {
        if (who->query_cps() < limit)
        {
          str = "apply/composure";
          name = "定力";
          break;
        }
      }
      case 5: 
      {
        if (who->query_per() < limit)
        {
          str = "apply/personality";
          name = "容貌";
          break;
        }
      }
      case 6: 
      {
        if (who->query_con() < limit)
        {
          str = "apply/constitution";
          name = "根骨";
          break;
        }
      }
      case 7: 
      {
        if (who->query_kar() < limit)
        {
          str = "apply/karma";
          name = "福缘";
          break;
        }
      }
    }
  }
  if (! str)
  {
    str = "apply/personality";
    name = "容貌";
  }
  
  points = 2;
  message_vision ("$N对$n一拜：菩萨托陛下传法旨，赐"+RANK_D->query_respect(who)+
                  chinese_number(points)+"点"+name+"！\n",me,who);
/*  
  command (channel+" "+who->query("name")+who->query("quest/reason")+"陛下有旨，赐"+
           chinese_number(points)+"点"+name+"！");
*/  
  who->add("quest/gain/"+str,points);
  reporting (who, who->query("quest/reason"), points, "点"+name);

  who->add_temp(str,points);
}


