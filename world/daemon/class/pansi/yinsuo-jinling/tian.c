#include <ansi.h>

inherit SSERVER;
int check_fight(object me, int amount, object weapon);
private int remove_effect(object me, int amount);
int perform(object me)
{
    object weapon = me->query_temp("weapon");  
    int skill;
    
    if(!me->is_fighting() )
                return notify_fail("「天上人间」只能在战斗中使用。\n");

    if ( (int)me->query_skill("jiuyin-xinjing", 1) < 100 )
        return notify_fail("你的内功等级不够，不能使用「天上人间」。\n");
	
	if(me->query("family/family_name")!="盘丝洞")
return notify_fail("“天上人间”只有盘丝洞门人才可以用！\n");
    
    if ( (int)me->query_skill("yinsuo-jinling", 1) < 100 )
        return notify_fail("你的银索金铃不够娴熟，不能真正发挥「天上人间」。\n");
    
    if (!weapon || weapon->query("skill_type") != "whip"
    || me->query_skill_mapped("whip") != "yinsuo-jinling")
        return notify_fail("你现在无法使用「天上人间」来提高防御力。\n");
    
    if ( (int)me->query("force") < 500 )
        return notify_fail("你现在内力太弱，不能使用「天上人间」。\n");
    
    if ( (int)me->query_temp("YSJL_tian") ) 
        return notify_fail("你正在使用「天上人间」。\n");
    
    if (me->query_skill_mapped("force") != "jiuyin-xinjing")
        return notify_fail("你的内功有误，无法使用「天上人间」。\n");

    message_vision(HIW "$N这时一声高喝，脸上殷红如血，衣袍都鼓了起来，手中"+weapon->name()+"急速转动，渐渐收短，守
御相当严密。"+weapon->name()+"似有无穷弹力，似真似幻，无论敌人怎么变招抢攻，总是被弹了出去。\n"NOR, me);
    me->start_busy(2);
    me->add("force", -300);          
    
    skill = me->query_skill("yinsuo-jinling");
	me->add_temp("apply/dodge",  skill);    
    me->add_temp("apply/parry",  skill);
    me->add_temp("apply/attack",  skill/2);
    me->set_temp("YSJL_tian", 1);

    check_fight(me, skill, weapon);
    return 1;
}

int check_fight(object me, int amount, object weapon)
{  
    object wep;    
    if(!me) return 0;
    wep = me->query_temp("weapon");  
    if(!me->is_fighting() || !living(me) || me->is_ghost() || !wep || weapon != wep )
        remove_effect(me, amount);

    else {
	call_out("check_fight", 1, me, amount, weapon);
	me->start_perform(1, "天上人间");
    }
    return 1;
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/dodge", -amount);
    me->add_temp("apply/parry", -amount);
    me->add_temp("apply/attack", -amount/2);
    me->delete_temp("YSJL_tian");
    if(living(me) && !me->is_ghost())
      message_vision(GRN"良久，$N所使天上人间的威力渐渐平息，一切又恢复了原状。\n"NOR, me);
    return 0;
}

