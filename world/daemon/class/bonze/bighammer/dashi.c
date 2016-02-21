#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mydh, hisdh,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("bighammer",1) ;
        if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("你并非出家和尚不能用大势锤！\n");
	if ( extra < 100) return notify_fail("你的[大势锤]还不够纯熟！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［大势将至］只能对战斗中的对手使用。\n");
 if (!((string)me->query("bonze/class") =="bonze" )) {
                return notify_fail("[大势将至]只有出家人才能使用。\n");
        if((int)me->query("force") < 500 ) return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 200 ) return notify_fail("你无法集中精力！\n");
               me->add("force", -200);
             me->receive_damage("sen", 100);
             me->receive_damage("kee", 100+random(200));
	weapon = target->query_temp("weapon");
	mydh = (int)me->query("daoxing")*(int)me->query("max_mana");
	hisdh= random((int)target->query("daoxing")*((int)target->query("max_mana")+1));
	if(hisdh < mydh*4/5 )	
{
message_vision(HIR "\n$N身形立定口诵佛号，$n只觉得一种巨大的压力扑面而来！\n" NOR,me,target);
 if (hisdh<mydh/4)
{
message_vision(HIR "\n$n不堪重压，身子象要爆开一般，奇痛无比！波的喷出一口鲜血！\n " NOR,me,target);
          damage=random((int)me->query("max_mana"));
         	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
           else if (hisdh<mydh/2)
{
message_vision(HIR "\n$n暗运内力向抗，但还是喷出一口鲜血！\n " NOR,me,target);
          damage=random((int)me->query("max_mana")/2);
         	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
           if (weapon)
{
message_vision(HIR "\n$n眼见大势已去，放下手中兵器" NOR, me,target);
     weapon->unequip();
	if( weapon->unequip()) weapon->move(environment(target));
}
message_vision(
HIR "\n$n被$N的佛法感化，跪倒在地已经忘记了自己还在战斗之中！\n\n" NOR, me,target);
            damage=3+extra/20;
            if (damage>15) damage=15;
            target->start_busy(damage);
}
else {
message_vision(
HIB "\n$n暗运内力，逼回了这股劲风！\n" NOR, me, target);
}

}
 me->start_busy(2);

        me->improve_skill("bighammer", 1, 1);
	return 1;
}
