inherit ITEM;
int do_apply (string arg);
void create()
{
  set_name("金龙符", ({"jinlong fu", "jinglong", "fu"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_sell", 1);
    set("no_drop", 1);
    set("unit", "张");
  
  set("long", "一张黄色的纸符，上面画了尾喷云吐雾的金龙。
可用来显化(apply)咒语。\n");
    }
    setup();
}
void init()
{
	add_action("do_apply", "apply");
}
int do_apply (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object ob;

  if ((! arg ||
     ! (ob = present(arg, who)))&&
	(! arg || ! (ob = present(arg, where))))
  {
    return notify_fail("你要将金龙符做什么用？\n");
  }
  if (ob == who)
  {
    message_vision ("$N拿起金龙符往自己脑门上一帖，金龙符“轰”的一声就着了起来。\n",who);
    message_vision ("顿时$N只觉得一股精气入髓七窍生烟，乾坤倒置！\n",who);
    who->unconcious();
  }
  else if ((string)ob->query("name") != "八瓣梅花锤" &&
	(string)ob->query("name")!="九股托天叉" ) {

    message_vision ("$N拿起金龙符往$n上一帖，金龙符“轰”的一声就着了起来。\n",who,ob);
  }
  else
  {
	message_vision("$N拿起金龙符往$n上一帖，金龙符“轰”的一声就着了起来。\n
只见$n上下光影游动，周身上下现出盘龙般的篆咒。\n",who,ob);
	ob->set("OK_to_STUDY", 1);
  }
  destruct (me);
  return 1;
}

