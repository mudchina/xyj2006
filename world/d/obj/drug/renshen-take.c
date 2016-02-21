#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init ()
{
  object me = this_object();
  object who = this_player();
  object where = environment();
  if (!me->query("my_owner") &&
      interactive (who))
  me->set("my_owner",who->query("id"));
  add_action ("do_eat", "eat");
  
}
void create()
{
        set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
                  set("value", 5);
set("no_put",1);
set("no_drop",1);
set("no_sell",1);
                set("drug_type", "补品");
        }
  
        set("is_monitored",1);
        setup();
}

int do_eat(string arg)
{
        int howmany;

        object me = this_player();
      
        if (!id(arg)) return notify_fail("你要吃什么？\n");
        if(!this_object()->query("my_owner"))
                return notify_fail("刚拿到就想吃?\n");
if ((string)environment(me)->query("short")=="禹王林" )
return notify_fail("这里这么危险还吃什么东西啊？\n");
        howmany = (int)me->query("rsg_eaten");
  
        me->set("food", (int)me->max_food_capacity());

        if(me->query("id")==this_object()->query("my_owner"))
        {
        
        if( howmany <= 100 ) me->add_maximum_force(0);
        if( howmany <= 100 ) me->add_maximum_mana(0);
        }
        else  message_vision(HIY "好像不是自己的劳动成果!\n" NOR, me);  
//       me->set("rsg_eaten", howmany+1);

        message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快晕了过去。\n" NOR, me);  

//         me->set("obstacle/wuzhuang","done");

        //for live forever...
        if( me->query("rsg_eaten") >= 36 )
        {
                me->announce_live_forever( me->query("name")+"坚持不懈地吃人参果，终于修成了不堕轮回，从此跳出三界外，不在五行中，永无生死大限了！" );
        }

//         me->unconcious();
 if (!wizardp(me))
         me->unconcious();
        destruct(this_object());

        return 1;
}
