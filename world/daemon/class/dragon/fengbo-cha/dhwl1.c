// dhwl.c
//write by yeahsi
//yeahsi@21cn.com

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
    int how_long,times;
    string str;
    object weapon;
    
    if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「大海无量」？\n");
    
    
    if (!me->query_temp("dhwl"))
           return notify_fail("你没有蓄力。\n");
           
    if (me->query_temp("dhwl_target") != target)
           return notify_fail("你搞错对象了吧。\n");              
           
    weapon=me->query_temp("weapon");
    how_long = me->query_temp("dhwl");
    times = random(how_long)+1;
    if (how_long > 6 && times < 6) times=5;
    if (how_long > 10) times=10;
    
    
    message_vision(HIC"$N长啸一声，天地为之变色，手中"+weapon->name()+HIC"卷起一阵震耳欲聋的海潮声，暴风骤雨地袭向$n。
$n只觉得$N激荡起来的真气以海纳百川般的气势一浪接一浪扑来，连呼吸也感到困难了。\n"NOR,me,target);

    me->delete_temp("no_move");
    me->add_temp("apply/damage",how_long*5);
    me->add_temp("apply/attack", how_long*5);  
    for (int i=0; i<=times; i++)
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    
    if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"中了"+me->name()+"的「大海无量」，在"+me->name()+"的内力震荡下，顿时吐血身亡！";
	                CHANNEL_D->do_channel(me, "rumor",str);
	                me->delete_temp("last_channel_msg");}

    me->set_temp("apply/dodge",me->query_temp("before_dhwl_dodge"));
    me->delete_temp("dhwl");
    me->delete_temp("before_dhwl_dodge");
    me->add_temp("apply/damage",-how_long*5);
    me->add_temp("apply/attack", -how_long*5);
    me->set_temp("dhwl_end",time());
    me->delete_temp("dhwl_target");
    return 1;
	        
        
}

