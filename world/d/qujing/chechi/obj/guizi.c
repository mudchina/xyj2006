// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("朱红柜子", ({"zhuhong guizi", "guizi"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "箱");
    set("long", "一箱朱红漆嵌玉金锁大柜子。\n"),
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
  call_out ("autoleave",1,this_object(),this_player(),0);
  add_action ("do_command","",1);
  add_action ("do_look","look");
  add_action ("do_put","put");
  add_action ("do_get","get");
}

void autoleave (object me, object who, int i)
{
  if (! who)
    return;
  if (environment(who) != me)
    return;
  if (! living(who))
    return;
  if (i < 180)
  {
    call_out("autoleave",1,me,who,i+1);
    return;
  }
  who->move(environment(me));
  message_vision ("只见$N面如死灰地被内官拖了出来。\n",who);
  if (interactive(who))
    who->unconcious();
}

int do_command (string arg)
{
  string *strs = ({
    "你听见",
    "你好像听见里面",
    "柜子里",
    "柜子里似乎",
  });
  string *msgs = ({
    "$N在黑暗中胡乱踢打了几下。\n",
    "$N砰地撞在柜顶上。\n",
    "$N颠三倒四地发出噪音。\n",
    "$N胡乱挣扎着。\n",
    "$N摸摸索索地折腾着。\n",
    "$N发出一声哀鸣。\n",
    "$N狠狠地撞在柜壁上。\n",
    "$N不知所措地在黑暗中踢打着。\n",
    "$N发出笨重的撞击声。\n",
    "$N头撞在壁板上，发出沉闷的一声响。\n",
  });
  string str = strs[random(sizeof(strs))];
  string msg = msgs[random(sizeof(msgs))];
  object who = this_player();
  object me = this_object();

  if (environment(who) != me)
    return 0;
/*
  if (wizardp(who))
  {
    return 0;
  }
*/
  message_vision (msg,who);
  msg = replace_string (msg,"$N",who->name());  
  tell_room(environment(me),str+msg);
  return 1;
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if (!arg)
    return 0;

  ob = present(arg,where);
  if (ob != me)
    return 0;

  tell_object(who,ob->long());
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
