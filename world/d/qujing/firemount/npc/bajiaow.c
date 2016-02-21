// created 4/25/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("°Å½¶¹Ö", ({"bajiao guai", "wannian guai", "guai"}));
  set("title", "ÍòÄê");
  set("gender", "ÄÐÐÔ");
  set("age", 12000+random(6000));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "ÍòÄê°Å½¶¹Ö¡£\n");
  set("attitude", "peaceful");
  set("combat_exp", 10000000);
  set("daoxing", 1000000);

  set_skill("dodge", 350);
  set_skill("parry", 350);
  set_skill("force", 350);
  set_skill("spells", 350);
  set_skill("unarmed", 350);
  set_skill("whip", 350);
  set("max_gin", 9000);
  set("max_kee", 9000);
  set("max_sen", 9000);
  set("force", 9000);
  set("max_force", 9000);
  set("mana", 9000);
  set("max_mana", 9000);
  //set_weight(300000);
  setup();
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  carry_object(dir+"obj/bian")->wield();
  carry_object(dir+"obj/skirt")->wear();

}

void equalize_gifts (object ob, object me)
{
  // encourage players to have equalized gifts
  ob->set("con",(me->query("spi")+me->query("con"))*3/2);
  ob->set("cor",(me->query("kar")+me->query("cor"))*3/2);
  ob->set("cps",(me->query("per")+me->query("cps"))*3/2);
  ob->set("int",(me->query("str")+me->query("int"))*3/2);
}


int allow_split()
{
  object me = this_object();
  object who = this_player();

  me->set_temp("split",1);
  message_vision ("$NÒ»ã¶£¬Ëæ¼´ÉñÃØµØ³¯$nµãÍ·Ò»Ð¦¡£\n",me,who);
  return 1;
}

void init()
{
  object ob;

  ::init();
  /*
  set("inquiry", ([
       "·ÖÉíÊõ": (: allow_split :),
      ]));
      */
}

int accept_fight (object me)
{
  object ob = this_object();
  equalize_gifts (ob, me);
  ob->setup();
  if (! ob->query_temp("split"))
    return 1;
  if (! ob->query("triplicate"))
  {
    object ob0, ob1, ob2, ob3;
    //string str = file_name(ob);
    string str = __DIR__"bajiaow";
    ob0 = present("guai 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("guai 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("guai 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob1 = new(str);
    ob1->setup();
    ob1->move(environment(ob));
    ob2 = new(str);
    ob2->setup();
    ob2->move(environment(ob));
    //ob3 = new(str);
    //ob3->setup();
    //ob3->move(environment(ob));
    message_vision ("$N´óºÈÒ»Éù£¬´ÓÉíºóÍ»È»ÉÁ³öÁ½¸ö$N£¡\n",ob);
    ob->set("kee",ob->query("max_kee")/10*12);
    ob->set("triplicate",1);
    ob1->set("triplicate",1);
    ob2->set("triplicate",1);
    //ob3->set("triplicate",1);
    ob1->fight_ob(me);
    ob2->fight_ob(me);
    //ob3->fight_ob(me);
  }
  return 1;
}

void unconcious()
{
  die();
}

ÿ
