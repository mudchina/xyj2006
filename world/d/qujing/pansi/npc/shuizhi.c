// created 11/25/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  string dir;

  set_name("Ë®òÎ¾«", ({"shuizhi jing", "jing"}));
  set("gender", "Å®ÐÔ");
  set("age", 24);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 20);
  set("attitude", "peaceful");
  set("combat_exp", 750000);
  set("daoxing", 500000);

  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set_skill("unarmed", 100);
  set_skill("whip", 100);
  set("max_gin", 1500);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("force", 1500);
  set("force_factor", 20);
  set("max_force", 1500);
  set("mana", 1500);
  set("max_mana", 1500);
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/armor/gujia")->wear();

}

void equalize_gifts (object ob, object me)
{
  // encourage players to have equalized gifts
  ob->set("con",(me->query("spi")+me->query("con"))*2/3);
  ob->set("cor",(me->query("kar")+me->query("cor"))*2/3);
  ob->set("cps",(me->query("per")+me->query("cps"))*2/3);
  ob->set("int",(me->query("str")+me->query("int"))*2/3);

}

/*
void kill_ob (object me)
{
  object ob = this_object();
  equalize_gifts (ob, me);
  ob->setup();
  if (! ob->query("triplicate"))
  {
    object ob0, ob1, ob2, ob3;
    //string str = file_name(ob);
    string str = __DIR__"shuizhi";
    ob0 = present("jing 2",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("jing 3",environment(me));
    if (ob0)
      destruct (ob0);
    ob0 = present("jing 4",environment(me));
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
    message_vision ("àáµØÒ»Éù´Ó$NÉíºóË®ÁÜÁÜµØ×ê³ö¼¸¸ö$n£¡\n",me,ob);
    ob->set("kee",ob->query("max_kee")/10*12);
    ob->set("triplicate",1);
    ob1->set("triplicate",1);
    ob2->set("triplicate",1);
    //ob3->set("triplicate",1);
    ob1->kill_ob(me);
    ob2->kill_ob(me);
    //ob3->fight_ob(me);
  }
	return;
}
*/ÿ
