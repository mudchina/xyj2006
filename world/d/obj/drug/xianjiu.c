// by snowcat 6/1/1997
// xianjiu.c 仙酒
// updated pickle 6-20-97

#include <ansi.h>

inherit ITEM;


void create()
{
  set_name(YEL "仙酒" NOR, ({"xian jiu", "jiu"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "盅");
    set("long", "一盅天上才有的玉液穹浆。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  setup();
}

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"丹从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                                    
  add_action("do_drink", "drink");
}


int do_drink(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("你要喝什么？\n");

  me->set("water", (int)me->max_water_capacity());
  switch (random(3))
  {
    case 0:
    {
      message_vision(HIG "$N喝下一盅仙酒，果真精神抖擞！\n" NOR, me);
      me->set("eff_gin", me->query("max_gin"));
      me->set("gin",     me->query("max_gin"));
      me->set("force",   me->query("max_force"));
      me->set("mana",    me->query("max_mana"));
    break;
    }
    case 1:
    {
      message_vision(HIG "$N喝下一盅仙酒，果真气色极佳！\n" NOR, me);
      me->set("eff_kee", me->query("max_kee"));
      me->set("kee",     me->query("max_kee"));
      me->set("force",   me->query("max_force"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
    case 2:
    {
      message_vision(HIG "$N喝下一盅仙酒，果真神采飞扬！\n" NOR, me);
      me->set("eff_sen", me->query("max_sen"));
      me->set("sen",     me->query("max_sen"));
      me->set("force",   me->query("max_force"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
  }
  destruct(this_object());
  return 1;
}
