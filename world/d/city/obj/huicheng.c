#include <skill.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("回城符", ({"huicheng seal", "seal", "fu"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸，中央有个大大的“回城”字。\n");
        set("unit", "张");
       set("value", 3000);
	set("no_put",1);
	set("no_sell",1);
	set("no_give",1);
	
	}
	setup();
}

void init()
{
    add_action("do_ji","ji");

}

int do_ji(string arg)
{
	object seal=this_object();
	object me=this_player();
	object where=environment(me);

	
	if(!arg || (arg!="huicheng seal"
                        && arg!="seal"
                        && arg!="fu") )
		return notify_fail("你要祭什么？\n");
		
	if(me->is_busy())
		return notify_fail("你正忙着呢，无法祭回城符。\n");
	if( where->query("no_magic"))
		return notify_fail("这里不能祭回城符。\n");
      
         if(me->query_temp("in_tiaozhan"))
                return notify_fail("你还在挑战中，怎么能离开呢？\n");
        
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不能控制回城符。\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，很难驾驭回城符。\n");
        if(me->query_temp("in_tiaozhan"))
               return notify_fail("你还在挑战中，怎么能离开呢？\n");

	message_vision(HIC"\n$N大喊一声“走”，手一挥，祭出了一张回城符。。。\n"NOR, me);
        message_vision(HIC"只见风沙乍起，$N化做一阵狂风,呼啸而去。\n"NOR, me);
       me->set("mana",0);
        me->start_busy(2+random(2));
        me->move("/d/city/kezhan");
        message("vision", HIC"一阵飞沙走石过后，"+me->name()+"的身影突然出现在你面前。\n"NOR,
				  environment(me), me);
		tell_object(me, HIC"狂风过后，你总算是回来了。\n"NOR);
	destruct(seal);
	return 1;
	
}
