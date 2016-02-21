// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("大油锅", ({"da youguo", "youguo"}));
  set_weight(6000000);
  set_max_encumbrance(100000000000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "口");
    set("long", "一口巨大的油锅，里面热油滚滚。\n"),
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
    "$N在滚油里挣扎了一下。\n",
    "$N从油浪里勉强冒出头来，又沉下去。\n",
    "$N扑打着双手。\n",
    "$N浮出油面，又被油浪压了下去。\n",
    "$N探出头来，大口喘气。\n",
    "$N从油面上伸出手乱抓了一下。\n",
    "$N随着油浪翻卷不止。\n",
    "$N的头勉强伸出滚烫的油面，旋即沉下。\n",
    "$N拼命蹿出油面喘着气。\n",
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
  tell_room(where,"油锅中"+msg,who);    
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
  message_vision ("几个内官上来用铁爪篱捞出$N。\n",who);
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
    tell_object(who,"翻滚的热油里有：\n");
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
