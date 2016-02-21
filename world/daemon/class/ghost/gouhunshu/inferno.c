//Cracked by Roath
#include <ansi.h>

inherit SSERVER;
int check_damage(object me, object target, int time);
int generate_msg(object me);

int cast(object me, object target)
{
	int time;

        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要引地狱火去烧谁？\n");

	if((int)me->query_skill("gouhunshu") < 30 )
		return notify_fail("你的勾魂术等级还不够。\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够了！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("现在你的精神不足！\n");

	if( (int)me->query("kee") < 100 )
		return notify_fail("你的气血不足。\n");

        if( random(me->query("max_mana")) < 50 ) {
                write("这次好象不大灵。\n");
                return 1;
        }

	time = 2 + (int)me->query_skill("gouhunshu",1) / 50;
	if ( time > 5 ) time=5;

	message_vision(HIB"$N双掌一搓，登时燃起一团蓝色的火焰，点点磷光飘向了$n！\n"NOR, me,
target);

	check_damage(me, target, time);

	return 3+random(5);

}

int check_damage(object me, object target, int time)
{
	int ap,dp,damage,success;

        if( !target
	|| !me 
       || environment(me) != environment(target)) {
                remove_call_out("check_damage");
                return 1;
        }

	ap= (int)me->query_skill("spells");
	ap= ap*ap*ap/10;
	ap= ap+(int)me->query("daoxing");

	dp= (int)target->query_skill("spells");
	dp= dp*dp*dp/10;
	dp= dp+(int)target->query("daoxing");

	damage=(int)me->query("max_mana")/10 - random((int)target->query("max_mana")/10);
	damage+=(int)me->query("mana_factor");
	success=1;

	if( damage < 0 ) success = 0;
	if( random(ap+dp) < dp ) success = 0;
	if( (int)me->query("mana") < 30 ) success = 0;
	if( (int)me->query("kee")  < 30 ) success = 0;
	if( environment(me)->query("no_fight")
	|| environment(me)->query("no_magic") ) success = 0;

	if( success ){

message_vision(HIB"\n「啪」地一团蓝色火焰在$N脚下燃起，如鬼魅缠身，将$N拢在中央。\n"NOR, target);
		target->receive_damage("kee", random(damage));
		target->receive_wound("kee", damage/3);
		COMBAT_D->report_status(target);
		me->receive_damage("kee", 25);
		me->add("mana", -25);
		me->start_busy(2);
	} else {
		tell_room(environment(target), "\n四周点点磷火飘荡着………\n");
	}

	time--;

	if( time ) {
		call_out("generate_msg", 4, me);
		call_out("check_damage", 8, me, target, time);
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
		"\n「啪」地一道蓝色火焰闪过。\n",
		"\n点点磷火在空气中飘荡着………\n",
		"\n一股蓝色火焰从地下冒了出来。\n",
		"\n火球「啪，啪」地爆燃着………\n",
	});
	if( !me ) return 1;
	tell_room( environment(me), msgs[random(sizeof(msgs))]);
}
