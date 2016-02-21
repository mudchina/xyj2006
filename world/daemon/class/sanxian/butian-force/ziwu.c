// ziwu.c
// written by mind 2001/2
// /daemon/class/sanxian/butian-force/ziwu.c

#include <ansi.h>

int exert(object me, object target)
{

        if ( !target
      ||      !userp(target)
      ||      target->is_corpse()
      ||      target==me)
                return notify_fail("你想替谁拔子午流注？\n");
        if (!target->query_condition("ziwuliuzhu_poison"))
        return notify_fail("没中子午流注瞎搅和什么！\n");
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");

        if( (int)me->query("force") - (int)me->query("max_force") <  400 )
                return notify_fail("你的真气不够。\n");

    if ((int)me->query_skill("butian-force",1)<80)
                return notify_fail("你的内功修为不足以替人拔子午流注。\n");
        
      if (me->query("betrayer") || me->query("betray/count"))
           return notify_fail("三心二意者很难领悟散仙的精髓所在。\n");
      
      
        message_vision(
                HIM "$N运起真神，循入$n体内，搜寻那无迹无踪的子午流注。\n\n"NOR,me, target );
    if (random(me->query_skill("butian-force", 1)-40)>10){
                target->apply_condition("ziwuliuzhu_poison",0);
                message_vision(
                HIY "$n感觉一股暖流在体内缓缓流转，禁不住倦意朦胧入了睡乡。\n"NOR,me, target );
                target->command_function("sleep");
                }
        else {
                message_vision(
                HIR "$N心神不济，真神怕是要涣散，竟呕出一口血来……\n"NOR,me, target );
        }       
 
        target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
        me->add("force", -150);
        me->set("force_factor", 0);
        return 1;
}

