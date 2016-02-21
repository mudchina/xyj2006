// by snowcat 11/22/1997

inherit ITEM;

string *names = ({
  "葫芦蛇",
  "大肥雕",
  "水老鼠",
  "短腿狗",
  "飞蚂蚁",
  "断臂猴",
});

void create()
{
  set_name("法简", ({"fa jian", "jian"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("long", "一细长的法简，上刻有一些蝇头佛文。\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("斜风突起，$n随风而去……\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  add_action ("do_apply", "apply");
  add_action ("do_apply", "point");
  add_action ("do_apply", "zhi");
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

int do_apply (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object xiaoyao;

  if (! arg ||
      ! (xiaoyao = present(arg,where)))
    return notify_fail ("你要拿法简干什么？\n");

  message_vision ("$N拿起法简，口中念念有辞地对$n一晃。\n",who,xiaoyao);
  remove_call_out ("applying");    
  call_out ("applying",2,who,xiaoyao);    
  return 1;
}

void applying (object who, object xiaoyao)
{
  if (! xiaoyao ||
      xiaoyao->query("id") != "xiao yao")
  {
    message_vision ("什么奇迹都没发生。\n",who);
    return;
  }
  if (! xiaoyao->query_temp("disabled"))
  {
    message_vision ("$N连眼皮都没有抬一下。\n",xiaoyao);
    return;
  }
  message_vision ("$N浑身一软，一下子显了原形。\n",xiaoyao);
  if (xiaoyao->query("name") == "小妖")
    xiaoyao->set_name(names[random(sizeof(names))],({"xiao yao","yao"}));
}
