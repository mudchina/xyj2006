// created 4/25/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("°Å½¶¹Ö", ({"bajiao guai", "guai"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40+random(30));
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("long", "°Å½¶¹Ö¡£\n");
  set("attitude", "peaceful");
  set("combat_exp", 70000);
  set("daoxing", 10000);

  set_skill("dodge", 12);
  set_skill("parry", 12);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("whip", 50);
  set("max_gin", 900);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 900);
  set("max_force", 900);
  set("mana", 900);
  set("max_mana", 900);
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
  ob->set("con",(me->query("spi")+me->query("con"))/2);
  ob->set("cor",(me->query("kar")+me->query("cor"))/2);
  ob->set("cps",(me->query("per")+me->query("cps"))/2);
  ob->set("int",(me->query("str")+me->query("int"))/2);
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
    string str = __DIR__"bajiao";
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
