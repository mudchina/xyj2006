// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "´ó»Æ",
  "°Í¶¹",
  "°×ÜÆ",
  "ÐÛ»Æ",
  "´Æ»Æ",
  "³ÂÆ¤",
  "Áú¹Ç",
  "´¨±´",
  "×Ï¾£",
  "³µÇ°",
  "ÑòÐë",
  "¹·Î²²Ý",
  "òÀ¿Ç",
  "Ý¸¸ù",
  "ÎÚÖñ»¨",
  "Å£»Æ",
});

void create()
{
  set_name("¸÷ÀàÒ©²ÝÒ©Æ·", ({"yao", "drug"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»Ð¡°üÒ©¡£\n");
    set("unit", "°ü");
    set("value", 300);
    set("no_sell", 1);
    set("food_remaining", 2);
    set("food_supply", 2);
  }
}

void init()
{
  add_action ("do_eat", "eat");
  if (query("name")=="¸÷ÀàÒ©²ÝÒ©Æ·")
  {
    set_name(names[random(sizeof(names))], ({"yao", "drug"}));
    call_out ("become_bad",600,this_object());
  }
  ::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! arg)
    return ::do_eat(arg);

  if (present(arg,who) == me)
  {
    if (! me->query_temp("is_ready"))
      call_out ("uncomfortable",4,who);  
  }
  return ::do_eat(arg);
}

void uncomfortable (object who)
{
  message_vision ("$N¶Ç×ÓÀïÒ»Õó½ÊÍ´£¬º¹ÈçÓêÏÂ£¬½û²»×¡ÉëÒ÷ÁËÒ»Éù¡£\n",who);
}

varargs int move (mixed dest, int silently)
{
  mixed status;
  object where;

  status = ::move(dest,silently);
  where = environment(this_object());
  if (where && where->query("id")=="yin yaozhan")
    where->make_drug();

  return status;
}

void become_bad (object me)
{
  set_name("±äÖÊµÄ»µÒ©", ({"huai yao"}));
  me->set_temp("is_ready",0);
  me->set("value", 0);
  call_out ("destruct_me",1800,me);
}

void destruct_me (object me)
{
  destruct (me);
}

