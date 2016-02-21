// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("云禅台", ({"yun chantai", "chantai"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("long", "一座由五十张桌子级级垒成的禅台，高耸入云。\n"),
    set("value", 50000);
  }
  setup();
}

int is_container()
{
  return 1;
}

void init()
{
  this_object()->set("short",this_object()->short());
  call_out("disturbed",5+random(20),this_object(),this_player());
  call_out ("autoleave",1,this_object(),this_player(),0);
  add_action ("do_look","look");
  add_action ("do_put","put");
  add_action ("do_get","get");
}

void disturbed (object me, object who)
{
  string *msgs = ({
    "$N忍耐不住，晃了一下，赶紧坐定。\n",
    "$N强忍着，就着衣襟蹭了蹭头。\n",
    "$N身子一歪，差点儿摔下。\n",
    "$N略动了一动。\n",
    "$N一个不稳连忙坐正。\n",
    "$N歪歪斜斜有点坐不住了。\n",
    "$N象喝醉了一样，身子直晃。\n",
  });
  string msg = msgs[random(sizeof(msgs))];
  object where = environment(me);

  if (! who)
    return;
  if (environment(who) != me)
    return;

  if (! living (who))
    return;
  message_vision (msg,who);
  msg = replace_string (msg,"$N",who->name());
  tell_room(where,"禅台上"+msg,who);    
  call_out("disturbed",5+random(20),me,who);
}

void autoleave (object me, object who, int i)
{
  if (! who)
    return;
  if (environment(who) != me)
    return;
  if (! living (who))
    return;
  if (i < 60)
  {
    call_out("autoleave",1,me,who,i+1);
    return;
  }
  who->move(environment(me));
  message_vision ("只见$N倒栽葱一般摔将下来，梆地砸在地上。\n",who);
  if (interactive(who))
    who->unconcious(); 
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;
  mixed *inv;
  int i;

  if (!arg)
    return 0;

  ob = present(arg,where);
  if (ob != me)
    return 0;

  tell_object(who,ob->long());
  inv = all_inventory(ob);
  i = sizeof(inv);
  if (i)
  {
    tell_object(who,"上面有：\n");
    while (i--)
    {
      tell_object(who,"  "+inv[i]->short()+"\n");
    }
  }
  return 1;
}

int do_put (string arg)
{
  string item;
  string id;
  object me = this_object();
  object who = this_player();
  object where = environment (me);

  if (sscanf(arg, "%s in %s", item, id)!=2)
    return 0;
  if (me != present(id,where))
    return 0;

  tell_object(who,"这里没有这样东西。\n");
  return 1;
}

int do_get (string arg)
{
  string item;
  string id;
  object me = this_object();
  object who = this_player();
  object where = environment (me);

  if (sscanf(arg, "%s from %s", item, id)!=2)
    return 0;
  if (me != present(id,where))
    return 0;

  tell_object(who,"这里没有这样东西。\n");
  return 1;
}
