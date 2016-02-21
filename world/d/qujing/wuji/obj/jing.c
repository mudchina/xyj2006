// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("乌鸡精", ({"wuji jing", "jing"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_sell", 1);
    set("no_drop", 1);
    set("unit", "小瓶");
    set("long", "一小瓶乌鸡精，据说服用(drink)可以提神，"+
                "施用他人(apply)可以还魂。\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$n掉在地上，碎了。\n",where,me);
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

  add_action ("do_drink","drink");
  add_action ("do_apply","apply");
}

int do_drink (string arg)
{
  object me = this_object();
  object who = this_player();
  object ob = present(arg, who);

  if (! ob)
    return 0;
  if (ob != me)
    return 0;

  message_vision ("$N拿起乌鸡精豪饮而下，顺手将空瓶一扔。\n",who);
  message_vision ("顿时$N只觉得一股精气入髓七窍生烟，乾坤倒置！\n",who);

  who->unconcious();
  destruct (me);
  return 1;
}

int do_apply (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if (! arg ||
     ! (ob = present(arg, where)))
  {
    return notify_fail("你要将乌鸡精洒在什么上面？\n");
  }
  if (ob == who)
  {
    message_vision ("$N拿起乌鸡精往自己身上一洒，顺手将空瓶一扔。\n",who);
    message_vision ("顿时$N只觉得一股精气入髓七窍生烟，乾坤倒置！\n",who);

    destruct (me);
    who->unconcious();
  }
  else if (ob->query("name") != "国王遗体" ||
           who->query("obstacle/wuji") == "done")
  {
    message_vision ("$N拿起乌鸡精往$n上一洒，顺手将空瓶一扔。\n",who,ob);
    message_vision ("顿时"+ob->name()+"晃动了一下。\n",who);
    destruct (me);
  }
  else
  {
    object king = new ("/d/qujing/wuji/npc/kingreal");
    message_vision ("$N掰开$n的口唇，拿起乌鸡精只是灌下，"+
                    "一口气吹入咽喉。\n",who,ob);
    message_vision ("乌鸡精度下重楼，转明堂，径至丹田，顿时国王动了一下。\n",
                    who);

    king->move(where);
    call_out("king_wake",2,king,who);
    call_out("follow_player",4,king,who,me);
    me->move(king);
    destruct (ob);
  }
  return 1;
}

void king_wake (object king, object who)
{
  message_vision ("\n呼的一声响亮，国王气聚神归，翻身坐起。\n",who);  
}

void follow_player (object king, object who, object me)
{
  if (! who)
    return;
  if (environment(who) != environment(king))
    return;
  message_vision ("\n国王对$N拜道：“昨夜鬼魂拜谒，今朝晓返阳神！”\n",who);  
  message_vision ("说罢国王又是一拜。\n",who);  

  if (who->query("obstacle/wuji") == "done")
    return;

  king->command_function("follow "+who->query("id"));
  king->set("my_saver",who->query("id"));
  who->set_temp("obstacle/wuji","saved");
  destruct (me);    
}
