// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("金厢白玉圭", ({"yu gui", "yu", "jade"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("value", 100000);
    set("no_sell", "天下没人敢认买金厢白玉圭。\n");
    set("no_drop", "谁敢乱扔金厢白玉圭？\n");
    set("unit", "柄");
    set("long", "一柄金厢白玉圭，乃乌鸡国之国宝。\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$n青光一闪，化成一道烟去了……\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

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

