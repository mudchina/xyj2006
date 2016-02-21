//Cracked by Roath
// lifeheal.c

#include <ansi.h>

int cast(object me, object target)
{
        if( !target )
                return notify_fail("你要用法力为谁疗伤？\n");
		if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("你不是不是佛门弟子,不懂这佛门奥义！\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");

        if( (int)me->query("mana") - (int)me->query("max_mana") < 150 )
                return notify_fail("你的法力不够。\n");

        if( (int)target->query("eff_sen") < (int)target->query("max_sen") / 5 )
                return notify_fail( target->name() + "神智已失，经受不起你的法力震荡！\n");

        message_vision(
                HIY "$N坐了下来运动法门，将手掌贴在$n灵台，缓缓地将法力输入$n体内....\n\n"
                "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口浊气，精神看起来好多了。\n" NOR,
                me, target );
        target->receive_curing("sen", 10 + (int)me->query_skill("spells")/3 );
        me->add("mana", -150);
        me->set("mana_factor", 0);

        return 1;
}

