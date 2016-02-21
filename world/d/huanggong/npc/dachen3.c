// by snowcat

inherit NPC;

#include <reporting.h>

void do_improve(object who, string name, int points, int level);

void create()
{
  set_name("杜如晦", ({ "du ruhui", "du", "ruhui", "da chen" }));
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
  mapping skills = who->query_skills();
  string *names;
  string name;
  string channel = "sldh";
  string *channels = who->query("channels");
  int level;

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  if (sizeof(skills) == 0) {
    name = "force";
    level = 2;
  } else {
    names = keys(skills);
    name = names[random(sizeof(names))];
    level =skills[name]+1;
  }

  points = points * (who->query("kar")/2+1);
  message_vision ("$N对$n一拜：菩萨托陛下传法旨，赐"+RANK_D->query_respect(who)+
                  chinese_number(points)+"点"+to_chinese(name)+"技能！\n",me,who);
/*  
  command (channel+" "+who->query("name")+who->query("quest/reason")+"陛下有旨，赐"+
           chinese_number(points)+"点"+to_chinese(name)+"技能！");
*/                  
  who->add("quest/gain/skills/"+name,points);
  reporting (who, who->query("quest/reason"), points, "点"+to_chinese(name)+"技能");

  do_improve(who, name, points, level);
}

// mon 3/30/98 allow players to increase several levels of skill
// if they got big skill reward points.
// (though the penalty is need double the normal points to increase
//  one level)
void do_improve(object who, string name, int points, int level)
{
    int pot;
    int high=(level>50);
    // for level>50, can't increase level.
    // for level<=50, possible to increase level.

    if(!who) return;

    pot=level*level*2;
    if(points>pot) {
    //level<50 so this is only useful for low level skills.
    //players can't use this method to improve their high level skills.
    //must learn to improve.

      who->improve_skill(name, pot, high);
      call_out("do_improve", 1, who, name, points-pot, level+1);
    } else
      who->improve_skill(name, points, high);

//tell_object(who,name+" "+level+" "+pot+"\n");
}

