// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("油葫芦", ({"you hulu", "hulu", "hu", "lu"}));
  set_weight(700);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一个用葫芦制成的油壶，上面绘着醉笙花。\n");
    set("unit", "个");
    set("value", 1000);
    set("max_liquid", 10);
  }
  set("liquid", ([
    "type": "oil",
    "name": "酥合香油",
    "remaining": 0,
  ]));
  set("no_get",1);
  set("no_drop",1);
  set("no_sell",1);
}

void destruct_me(object where, object me)
{
  message_vision("$n“叭”地一声摔在地上，砸了个粉碎！\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  add_action ("do_fill", "fill");
  add_action ("do_pour", "pour");
  add_action ("do_fill", "zhuang");
  add_action ("do_pour", "dao");
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

int do_fill (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if (! arg)
    return notify_fail ("你要灌什么？\n");    
  ob = present (arg,who);
  if (! ob)
    return notify_fail ("你想要灌什么？\n");    

  if (! where->query("has_oil"))
  {
    if (where->query("has_oil_pot"))
      return notify_fail ("罐子里已没有酥合香油了。\n");    
    else
      return notify_fail ("这里没有酥合香油可灌。\n");    
  }
 
  if (query("liquid/remaining") > 0)
  {
    //message_vision ("$N将$n里剩下的"+query("liquid/name")+"倒掉。\n",who,me);
    return notify_fail ("葫芦里已装有酥合香油了。\n");
  }
  message_vision ("$N将$n灌满酥合香油。\n",who,me);
  where->set("has_oil",0);
  where->regenerate_oil();
  set("liquid", ([
    "type": "oil",
    "name": "酥合香油",
    "remaining": 10,
  ]));
  return 1;
}

int do_pour (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object guan = present ("deng guan",where);
  object ob;

  if (! arg)
    return notify_fail ("你想倒什么？\n");
  ob = present (arg,where);
  if (! ob)
    return notify_fail ("你想把酥油往哪里倒？\n");
  if (ob->query("name")!="金灯缸")
    return notify_fail ("你想把酥油往哪里倒？\n");
  if (! query("liquid/remaining"))
    return notify_fail ("油葫芦里没有油。\n");
  if (query("liquid/name") != "酥合香油")
    return notify_fail ("油葫芦里装的不是酥合香油。\n");

  message_vision ("$N将$n里的"+query("liquid/name")+"倒进金灯缸。\n",who,me);
  set("liquid", ([
    "type": "oil",
    "name": "酥合香油",
    "remaining": 0,
  ]));

  who->add_temp("obstacle/jinping_oil",1);
  if (guan)
  {
    int i = 40 - who->query("kar");

    if (i < 10)
      i = 10;
    i -= who->query_temp("obstacle/jinping_oil");
    
    if (i > 0)
      message_vision ("$N告诉$n：再倒"+chinese_number(i)+"次便可。\n",
                      guan,who);
    else     
    {
      message_vision ("$N告诉$n：佛爷要来了！\n",guan,who);
      call_out ("coming",random(3)+3,who);
    }
  }  
  return 1;
}

void coming (object who)
{
  object me = this_object();
  object *obs = all_inventory (who);
  int i = sizeof(obs);

  message_vision ("一阵狂风吹来，佛爷出现！\n",who);
  while (i--)
  {
    object ob = obs[i];

    if (ob == me)
      continue;
    if (ob->query("no_get"))
      continue;
    if (ob->query("no_drop"))
      continue;

    message_vision ("佛爷从$N身上搜出$n！\n",who,ob);
    if (! interactive(ob))
      destruct (ob);
    else
      ob->move(environment(who));
  }  
  message_vision ("\n佛爷携着$N飞上天空！\n",who);
  who->move("/d/qujing/qinglong/shantou");
  message_vision ("\n佛爷突然停下来，顺便将$N往地上一扔！\n",who);
  who->unconcious();
}

