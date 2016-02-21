//lestat for moon
//2001 三无三不手
 
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;
//        int j;
       string msg;
//      int ap;
        if( !target ) target = offensive_target(me);
//         j = (int)me->query_skill("jueqingbian",1);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「三无三不手」?\n");
if( time()-(int)me->query_temp("wuxue_end") < 10 )
return notify_fail("绝招用多就不灵了！\n");

        if(!me->query("JQB_known"))
                return notify_fail("痴梦没有传你「三无三不手」。。。\n");
        if(me->query_temp("JQB_perform")) 
                return notify_fail("你已经使出「三无三不手」了！\n");

        if(!me->is_fighting(target) )
                return notify_fail("三无三不手只能在战斗中使用!!\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") <50 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("jueqingbian",1) <100)
                return notify_fail("你的绝情鞭级别还不够施展这一招三无三不手!!\n");
        if((int)me->query_skill("moondance",1) <100)
                return notify_fail("你的冷月凝香舞等级不够!!\n");
        if((int)me->query_skill("moonforce",1)<100)
                return notify_fail("你的圆月心法等级太低!!\n");
        if((int)me->query_skill("moonshentong",1) <100)
                return notify_fail("你的月宫仙法等级不够!!\n");
        if( (string)me->query("gender") !="女性")
                return notify_fail("你非为纯阴之身,怎能知哓女儿家的心思??\n");
        if(me->query("family/family_name") != "月宫" )
                return notify_fail("你与痴梦无缘,领悟不到鞭法的精髓!!\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

//        ap = 2 + random(1);
        weapon=me->query_temp("weapon");
     msg = HIC
"\n问世间情为何物?直叫人生死相许!$N心中一阵酸楚,鞭法忽然变得灵动异常!\n" NOR;
    message_vision(msg, me, target);

/*        if( (int)me->query_skill("jueqingbian",1) > 120)
{
        me->set_temp("JQB_perform", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("JQB_perform", 13);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("JQB_perform", 14);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->start_busy(ap);
       } else {
      if( (int)me->query_skill("jueqingbian",1) > 90)
{
      me->set_temp("JQB_perform", 12);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->set_temp("JQB_perform", 13);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->start_busy(2);
} else {
       me->set_temp("JQB_perform", 12);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
     me->start_busy(1);
}
}
        me->delete_temp("JQB_perform");
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        return 1;
}
*/
        skill = me->query_skill("whip");
        me->set_temp("JQB_perform",1);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/2);
        me->add("force", -200);
        return 1;
}
void checking(object me, object target)
{

	object weapon;
 if (!me) return 0;
  if ((me->query_temp("weapon"))&&(me)) weapon = me->query_temp("weapon");

        if ( me->query_temp("JQB_perform")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip") {
                tell_object(me, "\n你手中没有持鞭，「三无三不手」的攻势便即瓦解！\n" NOR);
		me->delete_temp("JQB_perform");
me->set_temp("wuxue_end",time());
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「三无三不手」的攻势！\n\n" NOR);
		me->delete_temp("JQB_perform");
me->set_temp("JQB_end",time());
                return;
           }
           else if ( (int)me->query("force") < 400  ) {
                tell_object(me, "\n你的内力后继不足，难以持续「三无三不手」的威力，只好收缓剑招。\n\n" NOR);
		me->delete_temp("JQB_perform");
me->set_temp("JQB_end",time());
                return;
           }
           else if ( me->query_skill_mapped("whip") != "jueqingbian" ) {
                tell_object(me, "\n你转而施展其他鞭法，无法再以「三无三不手」攻敌！\n\n" NOR);
		me->delete_temp("JQB_perform");
me->set_temp("JQB_end",time());
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，当下收回了「三无三不手」的攻势。\n\n" NOR);
		me->delete_temp("JQB_perform");
me->set_temp("JQB_end",time());
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  



void remove_effect(object me, int amount)
{       
	if ( me->query_temp("JQB_perform") ) {
        message_vision(HIM"$N心头一酸,一颗泪珠滴了下来。\n"NOR, me);
        me->delete_temp("JQB_perform");
me->set_temp("JQB_end",time());
         }
}
