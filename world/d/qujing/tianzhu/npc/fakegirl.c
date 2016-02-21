// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("¹«Ö÷", ({"gong zhu", "zhu", "princess"}));
  set("title", "ÌìóÃ¹ú");
  set("gender", "Å®ÐÔ");
  set("age", 20);
  set("attitude", "peaceful");
  set("combat_exp", 900000);
  set("daoxing", 800000);

  set_skill("dodge", 200);
  set_skill("parry", 200);
  set_skill("force", 100);
  set_skill("spells", 100);
  set_skill("unarmed", 100);
  set_skill("staff", 100);
  set_skill("moonshentong", 100);
  set_skill("moonforce", 100);
  set_skill("moondance", 150);
  set_skill("baihua-zhang", 100);
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moondance");
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
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixie")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
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
  call_out ("move_to_cave",5+random(10),this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  string location = "/d/qujing/maoying/tuxue1";
  object room;
  int i = 9;

  while (i--)
  {
    location[strlen(location)-1] = '1'+random(3);
    room = load_object(location);
    if (room != where)
    break;
  }

  if (me->is_fighting())
  {
    message_vision ("$NÍùÅÔ±ßÒ»Ìø£¬Ò»×ªÑÛÒÑÎÞ×ÙÎÞÓ°£¡\n",me);
    me->move(room);
  }
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();

  if (ob)
  {
    ob->set_temp("obstacle/tianzhu_killed",1);
  }
  message_vision ("\n$NÏÖÁËÔ­ÐÎ£¬¾¹ÊÇÒ»Ö»ÓñÍÃ¡£\n",me);
  message_vision ("Ö»ÌýÔ¶Ô¶µØ´«À´Ì«ÒõÐÇ¾ýµÄÅ­³â£º¡°ÓñÍÃ¶ù£¡¡±\n",me);
  message_vision ("\nÓñÍÃÎÅÉù¹Ô¹ÔµØÏòÍâÌøÈ¥¡£\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}

ÿ