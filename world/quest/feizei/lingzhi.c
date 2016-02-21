// lingzhi.c 千年灵芝
//

#include <ansi.h>
inherit ITEM;

void setup()
{}

int do_eat(string);
void destroy();
void init();
void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
//     set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
    add_action("do_eat", "eat");
    call_out("destroy", 120);
}
void create()
{
    set_name(HIB"含笑半步颠"NOR, ({"hanxiao banbudian", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "颗");
        set("long", "这是香奈儿炼的一颗灵丹，据说是杀人必备之良药。\n");
		set("value", 0);
	}
	  set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	  object me = this_player();
	  int force_add, howold;
  howold = (int)me->query("mud_age") + (int)me->query("age_modify");
        if (me->query("lestatgift/giftt"))
        {  
           tell_object(me,"你为什么这么贪心呢?\n");
           destruct(this_object()); 
           return 1;
        }
        me->set("lestatgift/gift",1);
        me->save();
  	if (!id(arg))
	return notify_fail("你要吃什么？\n");

    this_player()->add("combat_exp", 50000);
    this_player()->add("potential",100000);
    message_vision("$N吃下一颗黑黝黝的丸药，突然放了个响屁 !\n", this_player());
	  if( howold > 1382400 ) {
    me->add("age_modify", -1200);
    me->add("age_modify_time", 1);
    me->add("eat/biou",1);
  }
  destruct(this_object());
  return 1;

}

void destroy()
{
  destruct(this_object());
}

