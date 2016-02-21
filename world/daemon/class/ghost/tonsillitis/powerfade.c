//Cracked by Roath
// powerfade.c

#include <ansi.h>

inherit F_CLEAN_UP;


int exert(object me, object target)
{
        int skill;
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
        if( target != me ) return
notify_fail("你只能用反五行摄气诀压制自己的杀气。\n");

        if( (int)me->query("force") < 100 )     return
notify_fail("你的内力不够。\n");
        if( me->query_temp("powerup") ) return
notify_fail("你已经在运功中了。\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("你现在毫无杀气。\n");

//        skill = me->query_skill("force");
        skill = me->query_skill("tonsillit",1);

        me->add("bellicosity", - 50 - skill/3 );
        me->add("force", -100);
	if(me->query("bellicosity") <0) me->set("bellicosity",0);
        me->receive_damage("sen", 100);

        message_vision(
                HIC
"$N盘膝坐下，双眼微闭，运起反五行摄气诀压制心中的杀气。。。\n" NOR, me);

        if( me->is_fighting()
        &&      (random(skill) < (int)me->query("cps") ) )
                me->unconcious();

        return 1;
}

