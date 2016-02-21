// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("ÀÏ¹«¹«", ({"gong gong", "gong"}));
  set("gender", "ÄÐÐÔ");
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set("daoxing", 800000);

  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jinghun-zhang", 50);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 700);
  set("max_kee", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("mana", 800);
  set("max_mana", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/qujing/baoxiang/obj/longtou");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

  if (present("nu zi",where) ||
      present("fu ren",where) ||
      present("gong gong 2",where))
  {
    if (where->query("short") == "Ò°Â·")
    {
      load_object("/obj/empty");
      me->move("/obj/empty");
    }
    call_out ("destruct_me",1,me);  
  }
  else
  {
    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
  }
}

void destruct_me (object me)
{
  destruct (me);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
  return;

  message_vision ("$N¶Ô$nËµµÀ£º°¦°¦£¬¿É¼ûÎáÐ¡Å®ÀÏÆÞ£¿\n",me,who);
}

void unconcious()
{
  die();
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
    ob->set_temp("obstacle/baoxiang_killed_gonggong",1);
  message_vision ("\n$NÒ»Éù²Ò½Ð£¬ÆË·­ÔÚµØËÀÁË¡£\n",me);
  command ("drop long tou");
  corpse = new ("/d/qujing/baoxiang/obj/baigu");
  corpse->move(where);
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
 
ÿ