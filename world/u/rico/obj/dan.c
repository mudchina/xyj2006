#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
    add_action("do_eat", "eat");
}

void create()
{
  set_name(HIW "无名丹" NOR, ({"wuming dan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("long", "一枚不知道有什么用的丹。\n");
    set("value", 5000);
        set("drug_type", "补品");
  }

  set("is_monitored",0);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="huanhun dan") return 0;

   me->add_maximum_force(500);
   me->add_maximum_mana(500);
  message_vision("$N吃下一颗丹药,不过没有什么反应.\n");
  destruct(this_object());
  return 1;
}
