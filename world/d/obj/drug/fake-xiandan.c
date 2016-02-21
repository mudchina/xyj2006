//假仙丹


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
  set_name(HIW "仙丹" NOR, ({"xian dan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("long", "一枚青黄色的丹药，发出淡淡的的黄光。\n");
    set("drug_type","补品");
  }
  
  // the following line is added by snowcat
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
    message_vision(HIG "$N将仙丹嚼碎了咽到肚中，脸色突然转绿，一下跌倒在地！\n" NOR, me);
    tell_object(me,BLK "你腹中如同刀搅一般难受，痛的你在地下直打滚！\n\n" NOR);

    this_player()->unconcious();

  destruct(this_object());
  return 1;
}

