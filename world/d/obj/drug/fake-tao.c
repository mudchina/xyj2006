// fake-tao.c 猕猴桃干

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"丹从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                            
  add_action("do_eat", "eat");
}

void create()
{
  set_name("猕猴桃干", ({"mihou taogan","mihoutaogan","tao","gan","taogan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "黄橙橙的一颗猕猴桃干。据说是由傲来国花国山真正的猕猴桃制成，有强身健体延年益寿的功效。\n");
    set("value", 3000);
	set("drug_type", "假货");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  if((int)me->query("food")*100>(int)me->max_food_capacity()*90)
    return notify_fail("你已经吃得太饱，这颗弥猴桃干下去就要撑死了。\n");
  
  me->add("food", 50);
  if(random(10)==1){
      me->add_maximum_force(1);
    message_vision(HIG "$N吃下一颗弥猴桃干，忍不住抓耳挠腮，高兴得直想翻跟头！ \n" NOR, me);
    destruct(this_object());
    return 1;
  }
  if(random(10)==2){
      me->add_maximum_mana(1);
    message_vision(HIG "$N吃下一颗弥猴桃干，忍不住抓耳挠腮，高兴得直想翻跟头！ \n" NOR, me);
    destruct(this_object());
    return 1;
  }
  message_vision(HIG "$N吃下一颗弥猴桃干，忍不住舔了舔嘴唇，连声赞道：好吃！好吃！\n" NOR, me);
  destruct(this_object());
  return 1;
}
