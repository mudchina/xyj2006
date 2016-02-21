// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("ÑýÍõ", ({"yao wang", "wang"}));
  set("title", "Á¬»·¶´");
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 600000);
  set("daoxing", 500000);

  set_skill("dodge", 110);
  set_skill("parry", 110);
  set_skill("force", 110);
  set_skill("spells", 110);
  set_skill("unarmed", 110);
  set_skill("gouhunshu", 110);
  set_skill("tonsillit", 110);
  set_skill("ghost-steps", 110);
  set_skill("jienan-zhi", 110);
  set_skill("lunhui-zhang", 110);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-90000);
  set("nkgain",90);

  set("max_gin", 1200);
  set("max_kee", 1200);
  set("max_sen", 1200);
  set("force", 1200);
  set("max_force", 1200);
  set("mana", 1200);
  set("max_mana", 1200);
  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object where = environment(me);

  if (ob)
  {
    object tudi = new ("/d/qujing/yinwu/npc/tudi");
    ob->set_temp("obstacle/yinwu_yaowang",1);
    tudi->move(where);
    tudi->call_out_announce_success(ob);
  }
  message_vision ("\n$NÌ±»¾ÔÚµØ£¬¾¹ÊÇÒ»Ö»°¬Ò¶»¨Æ¤±ª×Ó¡£\n",me);
  me->set("name","°¬Ò¶»¨Æ¤±ª×Ó");
  ::die();
}

void unconcious()
{
  die();
}

ÿ