#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int cast(object me)
{
	int skill;
	me=this_player();


	if( (int)me->query_skill("buddhism", 1) < 50 )
		return notify_fail("你的大乘佛法等级不够。\n");
	if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("不是佛门弟子不能用「莲花护体」！\n");
        if( (int)me->query("mana") < 300 )     
                return notify_fail("你的法力不够。\n");
	if( (int)me->query("kee") < 300 )
		return notify_fail("你的气血不足。\n");
	if( (int)me->query("sen") < 300 )
		return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("anti_magic") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("spells");

        me->add("mana", -100);
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

        message_vision(
                HIC"$N微一凝神，背后幻出一朵白莲，五色毫光闪现。\n" NOR, me);

        me->set_temp("anti_magic", skill);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("anti_magic");
        tell_object(me, "你身后的白莲渐渐隐去了。\n");
	return;
}

