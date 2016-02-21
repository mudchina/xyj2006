#include <ansi.h>

inherit SSERVER;
int check_damage(object me, object target, int time);
int generate_msg(object me);

int cast(object me, object target)
{
	int time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展太极图？\n");
//      if(!me->query("taijitu_known"))
//            return notify_fail("你还没学会使用太极图。。。\n");
        if(me->query("family/family_name") != "昆仑山玉虚洞" )
                return notify_fail("你非玉虚门下,不会使用太极图!!\n");
        if((int)me->query_skill("spells") < 100)
            return notify_fail("你还不能自由运用太极图！\n");
        if( me->query_temp("cast_taiji"))
                return notify_fail("你已经在使用太极图！\n");        
        if((int)me->query("mana") < 1000 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你无法集中精力！\n");
 if((int)me->query("faith") < 500 )
                return notify_fail("你的门忠还不够呢！\n");
      me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 300);
        if( random(me->query("max_mana")) < 500 ) {
                write("你失败了！\n");
                return 1;
                     }
        me->set_temp("cast_taiji",1);
        message_vision(HIR "\n$N口中念了句咒文，大喝一声：呔！。。。【太极无形】。。。\n空中金云陡起，迅速弥漫开来，将$N的身形隐去,周围顿时杀机四伏。\n"
        NOR,me,target);
        me->set("env/invisibility", 1);
	time=me->query_skill("spells",1)/5 ;
	if(time>60)time=60;
	check_damage(me, target, time);
	me->start_busy(2);
        return 10+random(5);

}

int check_damage(object me, object target, int time)
{
	int ap,dp,damage,success;

        if( !target
	|| !me 
       || environment(me) != environment(target)) {
                remove_call_out("check_damage");
                me->delete_temp("cast_taiji");
                me->set("env/invisibility", 0);
                return 1;
        }

	ap= (int)me->query_skill("spells");
	ap= ap*ap*ap/10;
	ap= ap+(int)me->query("daoxing");

	dp= (int)target->query_skill("spells");
	dp= dp*dp*dp/10;
	dp= dp+(int)target->query("daoxing");
	damage=(int)me->query("max_mana")/10 - random((int)target->query("max_mana")/10);
	success=1;
	if( damage < 0 ) success = 0;
	if( random(ap+dp) < dp ) success = 0;
	if( (int)me->query("mana") < 30 ) success = 0;
	if( (int)me->query("kee")  < 30 ) success = 0;
	if( environment(me)->query("no_fight")
	|| environment(me)->query("no_magic") ) success = 0;

	if( success ){
            if(random(2)){
                message_vision(HIC"\n云层中跳出个五大三粗的光膀子仙将，举起大锤朝$n砸来。\n"NOR,me,target);
                message_vision(HIR"\n$n被仙将的大锤砸得七晕八素，差点摔倒在地！\n"NOR, me, target);
		target->receive_damage("kee", random(damage)*2);
                 target->receive_wound("kee", damage/2);
		COMBAT_D->report_status(target);
		me->receive_damage("sen", 25);
		me->add("mana", -25);
	        if(!me->is_busy()) me->start_busy(2); 
	             } 
	    else {
		message_vision(HIC"\n雷公电母双双跳出，霎时间飞沙走石。\n"NOR, me, target);
                message_vision(HIR"\n$n被雷声惊得差点站立不稳，神智不清了！\n"NOR, me, target);
	        target->receive_damage("sen", random(damage)*2);
             target->receive_wound("sen", damage/2);
                   COMBAT_D->report_sen_status(target);
		me->receive_damage("sen", 25);
		me->add("mana", -25);
	        if(!me->is_busy()) me->start_busy(2);      
	             }
	    }
	   time--;
	  if( time ) {
		call_out("generate_msg", 4, me);
		call_out("check_damage", 8, me, target, time);
	              }
	  else {
	       me->delete_temp("cast_taiji");
                me->set("env/invisibility", 0);
                return 1;
	        }
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                                 }
                me->kill_ob(target);
                  }
	return 1;
}

int generate_msg(object me)
{
	string *msgs=({
		HIR"\n四周人影重重，无数仙将蠢蠢欲动。\n"NOR,
		HIY"\n天空中飘荡着大旗，遮天蔽日……\n"NOR,
		HIB"\n天地混沌中，阴阳二气四处弥漫。\n"NOR,
		MAG"\n周围无数人影，你已经看不清楚方向……\n"NOR,
	});
	if( !me ) return 1;
	tell_room( environment(me), msgs[random(sizeof(msgs))]);
	return 1;
}
