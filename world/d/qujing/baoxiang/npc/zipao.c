// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("×ÏÅÛ¹Ö", ({"zipao guai", "guai"}));
  set("title", "Ìì²òĞÇ");
  set("gender", "ÄĞĞÔ");
  set("age", 60);
  set("str", 30);
  set("cor", 30);
  set("con", 20);
  set("per", 20);
  set("cps", 10);
  set("int", 10);
  set("attitude", "peaceful");
  set("combat_exp", 1500000);
  set("daoxing", 1000000);

  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("unarmed", 180);
  set_skill("gouhunshu", 180);
  set_skill("tonsillit", 180);
  set_skill("ghost-steps", 180);
  set_skill("jinghun-zhang", 180);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-90000);
  set("nkgain",90);

  set("max_gin", 2500);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("force", 2500);
  set("max_force", 2500);
  set("mana", 2500);
  set("max_mana", 2500);
  set("force_factor", 30);
  set("mana_factor", 80);

  setup();
  carry_object("/d/qujing/baoxiang/obj/sppifeng")->wear();
  call_out ("appearing",1);
}

void appear ()
{
  set_temp("already_ready",1);
  set("force_factor",30+random(30));
}

void appearing ()
{
  if (! this_object()->is_fighting())
    message_vision ("ºôµØÒ»Éù£¬ÕÓÀïÃ°ÉÏÀ´³¤ÅÛ¹ÖÎï£¡\n",this_object());
}

void disappear()
{
  remove_call_out ("disappearing");
  call_out ("disappearing",9);
}

void disappearing ()
{
  if (this_object()->is_fighting())
  {
    remove_call_out ("disappearing");
    call_out ("disappearing",9);
    return;
  }
  message_vision ("$NÒ»¸ö·´Éí´ó·­×ª£¬Ò»Í·×êÈëÕÓÔóÖ®ÖĞ¡£\n",this_object());
  destruct (this_object());
}

int allow_split()
{
  object me = this_object();

  if (me->query_temp("already_ready"))
    return 0;

  me->set_temp("split",1);
  message_vision ("$N×óÓÒ»·¹Ë£¬´óºğÒ»ÉùĞÖµÜºÎÔÚ£¡\n",me);
  return 1;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "ĞÖµÜ": (: allow_split :),
       "brother": (: allow_split :),
       "brothers": (: allow_split :),
      ]));
}

int accept_fight (object me)
{
  object ob = this_object();
  command ("haha "+me->query("id"));
  if (! ob->query_temp("split"))
    return 1;
  if (! ob->query("triplicate"))
  {
    object ob0, ob1, ob2, ob3;
  
    ob0 = present("guai 2",environment(me));
    if (ob0 && ! userp(ob0))
      destruct (ob0);
    ob0 = present("guai 2",environment(me));
    if (ob0 && ! userp(ob0))
      destruct (ob0);
    ob0 = present("guai 2",environment(me));
    if (ob0 && ! userp(ob0))
      destruct (ob0);
    ob1 = new("/d/qujing/baoxiang/npc/lupao");
    ob1->setup();
    ob1->move(environment(ob));
    ob2 = new("/d/qujing/baoxiang/npc/qingpao");
    ob2->setup();
    ob2->move(environment(ob));
    ob3 = new("/d/qujing/baoxiang/npc/lanpao");
    ob3->setup();
    ob3->move(environment(ob));
    ob->set("kee",ob->query("max_kee")/10*12);
    ob->set("triplicate",1);
    ob1->set("triplicate",1);
    ob2->set("triplicate",1);
    ob3->set("triplicate",1);
    ob->fight_ob(me);
    ob1->fight_ob(me);
    ob2->fight_ob(me);
    ob3->fight_ob(me);
    me->fight_ob(ob);
    me->fight_ob(ob1);
    me->fight_ob(ob2);
    me->fight_ob(ob3);
  }
  return 1;
}

void unconcious()
{
  message_vision ("\n$NºôµØÒ»Éù»¯×÷¹ÉÑÌÏòÌìÉÏ·ÉÈ¥¡£\n",this_object());
  destruct(this_object());
}

void die()
{
  message_vision ("\n$NºôµØÒ»Éù»¯×÷¹ÉÑÌÏòÌìÉÏ·ÉÈ¥¡£\n",this_object());
  destruct(this_object());
}

ÿ