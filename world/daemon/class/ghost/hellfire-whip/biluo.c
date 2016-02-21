// 碧落黄泉
// yangwl 1/31/2001
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"+HIG"「碧落黄泉」"+NOR"？\n");

        if((int)me->query("force") < 150+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");
// if (me->query_temp("hell_pfm_busy")) return notify_fail("你刚用过碧落黄泉。\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("hellfire-whip", 1) <120)
                return notify_fail("你的烈火鞭级别还不够！\n");
        
        if(me->query("family/family_name") != "阎罗地府")
                return notify_fail(HIG"「碧落黄泉」"+NOR"是冥界不传之密！\n");



        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);

        if( random(me->query("max_force")) < 50 ) {
                write("糟糕，没成功！\n");
                return 1;
        }


        COMBAT_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
                (int)me->query_skill("hellfire-whip", 1), 
                        //level of skill used
                150, 
                        //success adjustment
                100, 
                        //damage adjustment
                "qi", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                MAG "$N惨号一声，一口鲜血喷向半空，吃这主人心血一逼，手中长鞭啸声大作，
夹着阵阵鬼哭闪电般飞袭$n的胸口七处大穴！\n" NOR,
                        //initial message
                MAG "结果长鞭在$n胸口三进三出，带出一地鲜血！\n" NOR, 
                        //success message
                MAG "但是$n一声轻笑，身形摇晃，避了开去。\n" NOR, 
                        //fail message
                MAG "但是被$n以内力一逼，长鞭掉转头来，反噬其主！\n" NOR, 
                        //backfire initial message
                MAG "结果只听“噗嗤”一声，$n反被长鞭透胸而过！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(random(2));
//       me->set_temp("hell_pfm_busy",1);
// me->set_temp("no_move",1);
// call_out("remove_no_move",3,me);
//  call_out("remove_effect",5+random(3),me);
        return 1;
}
/*
void remove_effect(object me) {
if (!me) return;
  me->delete_temp("fc_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
*/
