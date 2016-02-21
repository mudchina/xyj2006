// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("蒸酥", ({"zheng su", "su"}));
  set_weight(1500);
  set("long", "一块供给三清的新鲜蒸酥。\n");
  set("unit", "块");
  set("value", 140);
}

void init()
{
  add_action ("do_eat","eat");
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object yuanshi1 = present("yuanshi",where);
  object lingbao1 = present("lingbao",where);
  object taishang1 = present("taishang",where);
  object yuanshi2 = present("yuanshi 2",where);
  object lingbao2 = present("lingbao 2",where);
  object taishang2 = present("taishang 2",where);
  object yuanshi3 = present("yuanshi",who);
  object lingbao3 = present("lingbao",who);
  object taishang3 = present("taishang",who);
  object ob;

  if (! arg)
    return 0;

  ob = present(arg,who);
  if (! ob)
    ob = present(arg,where);
  if (ob != me)
    return 0;

  who->set("food",who->max_food_capacity());

  if (! where || where->query("short")!="三清殿")
  {
    message_vision ("$N将$n吃了下去。\n",who,me);
    destruct(me);
    return 1;     
  }
  // not valid sanqing
  if (! yuanshi1 || ! lingbao1 || ! taishang1)
  {
    where->daoshi_appear(who);
    message_vision ("$N饥不择食地将$n吃了下去。\n",who,me);
    destruct(me);
    return 1;     
  }   
  // too many sheng xiangs
  if (yuanshi2 || lingbao2 || taishang2)
  {
    where->daoshi_appear(who);
    message_vision ("$N狼吞虎咽地将$n吃了下去。\n",who,me);
    destruct(me);
    return 1;     
  }   
  // haven't thrown sheng xiang away
  if (yuanshi3 || lingbao3 || taishang3)
  {
    where->daoshi_appear(who);
    message_vision ("$N风卷残云一般将$n吃了下去。\n",who,me);
    destruct(me);
    return 1;     
  }   
  // player hasn't become one of sanqing
  if (who!=yuanshi1 && who!=lingbao1 && who!=taishang1)
  {
    where->daoshi_appear(who);
    message_vision ("$N囫囵吞枣一般将$n吃了下去。\n",who,me);
    destruct(me);
    return 1;     
  }   
  // player is too weak to solve the quest
  if (who->query("combat_exp")<50000)
  {
    where->daoshi_appear(who);
    message_vision ("$N急急忙忙地将$n吃了下去。\n",who,me);
    destruct(me);
    return 1;     
  }   
  if (! who->query("obstacle/chechi"))
    who->set("obstacle/chechi","eaten");
  who->set_temp("obstacle/chechi","eaten");
  message_vision ("$N一本正经地将$n吃了下去。\n",who,me);
  where->daotong_appear(who);
  destruct(me);
  return 1;     
}
