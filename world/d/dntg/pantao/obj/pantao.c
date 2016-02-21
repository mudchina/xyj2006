#include <ansi.h>

inherit ITEM;

int do_eat(string);
int give_reward(object);
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
  set_name(HIM "蟠桃" NOR, ({"pan tao","pantao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
//    set("long", "一桃，真叫人垂涎欲滴。\n");
    set("value", 5000);
    set("drug_type", "补品");
    set("reward_value",1);
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player(),taohe;
  int food_allowed=(int)me->max_food_capacity()-me->query("food");
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  if (food_allowed<0) {
     message_vision(HIM"$N连皮带核吞下一枚蟠桃，觉得肚子胀的难受。\n"NOR,me);
     destruct(this_object());
     return 1;
  }
  message_vision(HIM "$N吃下一枚蟠桃，只觉口角生津，舒畅无比，忍不住大叫：好吃！还要！ \n" NOR, me);
  me->set("food",me->query("food")+30);
  give_reward(me);  
  
  taohe=new (__DIR__"taohe");
  taohe->move(me);  
  destruct(this_object());

  return 1;
}

int give_reward(object me) {
  int tao_eaten;

//  if (me->query("title")!="齐天大圣") return 0;
//  if (me->query("dntg/pantao")=="done") return 0;
  if ((int)me->query("dntg/pantao_eaten") )
       tao_eaten=(int)me->query("dntg/pantao_eaten");
  else tao_eaten=0;
  if (tao_eaten>=7) {
     if (random(2)) {
       me->add_maximum_force(query("reward_value"));
       me->add_maximum_mana(query("reward_value"));
    } else
    {
       me->add_maximum_force(-1);
       me->add_maximum_mana(-1);
       tell_object(me,HIR"你突然觉得体内气血翻涌，浑身上下说不出的难受！\n"NOR);
    }
    return 0;
}
  tao_eaten++;
  me->set("dntg/pantao_eaten",tao_eaten);
    me->add_maximum_force(1+random(15*(int)query("reward_value") ));
    me->add_maximum_mana(1+random(15*(int)query("reward_value")));
  return 1;
}  
