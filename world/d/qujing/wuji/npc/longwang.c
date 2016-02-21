//Changed 
#include <skill.h>

inherit NPC;

string show_king (object who);

void create()
{
  set_name("¾®ÁúÍõ", ({"jing longwang","longwang","wang"}));
  set("long","¾®ÀïµÄÁúÍõ£¬ÕÆ¹Ü×Å¾®µ×µÄÊÀ½ç¡£\n");
  set("gender", "ÄĞĞÔ");
  set("age", 55);
  set("class","dragon");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 550000);
  set("daoxing", 300000);

  set("rank_info/respect", "±İÏÂ");
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

  set("inquiry", ([ "±¦±´": (: show_king :),
                    "¹úÍõ": (: show_king :),
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
    return ("¹úÍõÔÚ´Ë£¡\n");
  if (where->query("short") != "Ë®¾§¹¬")
    return ("ÄªÌá£¬ÄªÌá£¡\n");
  if (! present("wuji jing",who))
    return ("¹úÍõÓëÄãºÎ¹ÊÒ²£¿\n");
  if (where->query("has_given"))
    return ("¹úÍõ±»¾ÈÁËÒ²£¡\n");
  where->set_given();
  command("sigh");
  message_vision ("$NÒ»»ÓÊÖ£¬Ë®ÏÂ¸¡ÆğÁ½Ò¹²æ£¬½«Ê²Ã´¶«Î÷Ì§½«¹ıÀ´¡£\n\n",me);
  king = new ("/d/qujing/wuji/obj/kingbody");
  king->move(where);
  return ("¿ÉÁ¯¿ÉÁ¯Ò²£¡\n");
}

ÿ