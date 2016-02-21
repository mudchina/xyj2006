// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  int i = random(3)+6;
  set_name("»Ê¹¬ËÅÎÀ", ({"si wei", "wei"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("long","Ò»Î»ÊØÎÀ»Ê¹¬µÄËÅÎÀ¹Ù¡£\n");
  set("combat_exp", 20000*i);
  set("per", 15);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 20*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",20*i);
  setup();
  carry_object("/d/obj/armor/tiejia")->wear();
  switch (random (5))
  {
    case 0:
    {
      carry_object("/d/obj/weapon/spear/changqiang")->wield();
      break;
    }
    case 1:
    {
      carry_object("/d/obj/weapon/sword/changjian")->wield();
      break;
    }
    case 2:
    {
      carry_object("/d/obj/weapon/blade/blade")->wield();
      break;
    }
    case 3:
    {
      carry_object("/d/obj/weapon/fork/gangcha")->wield();
      break;
    }
    case 4:
    {
      carry_object("/d/obj/weapon/rake/gangpa")->wield();
      break;
    }
  }
}

void kill_ob (object ob)
{
  object me = this_object();
  object where = environment (me);
  object bing1 = present ("gong bing 1",where);
  object bing2 = present ("gong bing 2",where);

  if (bing1)
    bing1->kill_ob(ob);
  if (bing2)
    bing2->kill_ob(ob);
  ::kill_ob(ob);
}

void unconcious ()
{
  object me = this_object();
  object where = environment (me);
  object siwei = present ("siwei 3",where);

  message_vision ("\n$Nµøµø×²×²ÃãÇ¿ÅÀ»Ø¹¬ÃÅ¡£\n",me);
  message_vision ("\n$N×ßÁË¹ýÀ´¡£\n",me);
  if (! siwei)
  {
    object ob = new ("/d/qujing/tianzhu/npc/siwei");
    ob->move(where);
  }
  destruct (me);
}

void die ()
{
  unconcious();  
}


