
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松，月饼从指间滑落！\n");
    set("no_give","这么珍贵的月饼，哪能随便给人？\n");
    set("no_drop","这么宝贵的月饼，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  switch (random(5)) {
    case 0:
      set_name( HIW "莲蓉月饼" NOR , ({"yue bing", "cookie"}));
      break;
    case 1:
      set_name( HIW "蛋黄月饼" NOR , ({"yue bing", "cookie"}));
      break;
    case 2:
      set_name( HIW "五仁月饼" NOR , ({"yue bing", "cookie"}));
      break;
    case 3:
      set_name( HIW "火腿月饼" NOR , ({"yue bing", "cookie"}));
      break;
    case 4:
      set_name( HIW "蟹黄月饼" NOR , ({"yue bing", "cookie"}));
  }
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一个小巧玲珑的月饼，令人垂涎欲滴。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="cookie" && arg!="yue bing")	return 0;
  if (me->query("wizgift/cookie_2000_eaten") <=4)
 {
  me->add("wizgift/cookie_2000_eaten",1); 
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  me->add("potential",1000);
  me->add("combat_exp",1000);
  me->save();
  log_file("static/COOKIEGIFT","["+ctime(time())+"] "+
  sprintf("%s(%s)吃了一个%O\n",
  this_player()->query("name"),this_player()->query("id"),
  this_object()));

 }
  message_vision(HIG "$N轻轻拿起一个月饼咬了一口，心中不免泛起一股思乡之意。
\n" NOR, me);
  destruct(this_object());
  return 1;
}

