//Changed 
#include <skill.h>

inherit NPC;

string show_king (object who);

void create()
{
  set_name("井龙王", ({"jing longwang","longwang","wang"}));
  set("long","井里的龙王，掌管着井底的世界。\n");
  set("gender", "男性");
  set("age", 55);
  set("class","dragon");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 550000);
  set("rank_info/respect", "陛下");
  set("per", 24);
  set("str", 30);
  set("max_kee", 1000);
  set("max_gin", 800);
  set("max_sen", 800);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 90);
  set("max_mana", 800);
  set("mana", 1200);
  set("mana_factor", 40);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("force", 80);
  set_skill("parry", 80);
  set_skill("fork", 80);
  set_skill("spells", 80);
  set_skill("seashentong", 80);
  set_skill("dragonfight", 80);
  set_skill("dragonforce", 80);
  set_skill("fengbo-cha", 80);
  set_skill("dragonstep", 80);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");

  set("inquiry", ([ "宝贝": (: show_king :),
                    "国王": (: show_king :),
                    "king": (: show_king :),
                 ]) );

  setup();

  carry_object("/d/obj/cloth/longpao")->wear();
}

string show_king (object who)
{  
  object me = this_object();
  object where = environment(me);
  object king;

  who = this_player();
  if (present ("guo wang",where))
    return ("国王在此！\n");
  if (where->query("short") != "水晶宫")
    return ("莫提，莫提！\n");
  if (! present("wuji jing",who))
    return ("国王与你何故也？\n");
  if (where->query("has_given"))
    return ("国王被救了也！\n");
  where->set_given();
  command("sigh");
  message_vision ("$N一挥手，水下浮起两夜叉，将什么东西抬将过来。\n\n",me);
  king = new ("/d/qujing/wuji/obj/kingbody");
  king->move(where);
  return ("可怜可怜也！\n");
}

