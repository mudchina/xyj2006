// throw.c  by bbs May 27, 1998
// modified by vikee 2000.10
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "valid_kill.h";


inherit F_DBASE;

int main(object me, string arg)
{
	string item, targ;
	object ob, victim ;
	int success, found, ap, dp, level, damage,damage_bonus, wound, lucky;
	mixed foo;
	string msg;

	if(environment(me)->query("no_fight") || 
           environment(me)->query("no_magic") )
              return notify_fail("安全区内发射暗器可是会引起公愤的噢！\n");

    	if( this_player()->is_busy() )
		return notify_fail("你现在正忙着呢。\n");

	if( !arg || sscanf(arg, "%s on %s", item, targ)!=2 )
		return notify_fail("指令格式：throw <某物> on <某人>\n");

	if(targ == me->query("id"))
                return notify_fail("想自杀应该用suicide吧？\n");

	if( !objectp(ob = present(item, me)))
		return notify_fail("你身上没有 "+item+"\n");
	if(ob->query("skill_type")!="throwing")
		return notify_fail(ob->query("name")+"不是暗器！\n");

	if( !objectp(victim = present(targ, environment(me))) )
		return notify_fail("你想向谁投掷暗器？\n");

	if(victim->query("mudage")<16 && userp(victim))
		return notify_fail("连小孩子都杀，你太没人性了!\n");
	// forbid to kill a player whose mudage <16 .here is added by vikee :P
	if(me->query("combat_exp")<50000 && userp(victim))
		return notify_fail("自己功夫没练好，就想杀人？\n"); //here is modified by vikee
   
	if(me->query("daoxing")<10000 && userp(victim))
  		return notify_fail("自己功夫没练好，就想杀人？\n");
	
	if( !living(victim)) 
		return notify_fail("什么你都想杀？\n");

	if(!valid_kill(me,victim,0)) return 0;

	success=0;
	found=0;
	damage=0;
	wound=0;
	lucky=0;
	ap=COMBAT_D->skill_power(me, "throwing", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	dp/=2;			// 暗器之暗
	if(random(ap+dp) > dp) {
		success=1;
		if(ap<dp) lucky=1;
	}
	ap=me->query("combat_exp")*me->query_kar();
	dp=victim->query("combat_exp")*victim->query_kar();
	if(random(ap+dp) < dp) found=1;

	tell_object(me, "你伸手从怀里掏出一"+ob->query("base_unit")+ob->query("name")+"，向"+victim->query("name")+"射了过去。\n");
	msg="只见一道寒光飞向$n的面门，";

	if(success) {
		msg+=victim->query("name")+"想躲却没躲开。\n";
		damage=ob->query("weapon_prop/damage");
		damage+=random(damage);
		damage_bonus=me->query_str();
		foo=ob->hit_ob(me, victim, damage);
		if(stringp(foo)) msg+=foo;
		else if(intp(foo)) damage_bonus+=foo;
		wound=random(damage-(int)victim->query_temp("apply/armor"));
		damage+=(damage_bonus+random(damage_bonus))/2;
		ap=me->query("force");
		dp=victim->query("force");
		while(random(dp)>ap) {
			damage-=damage/3;
			dp/=2;
		}
		if (wizardp(me) && me->query("env/combat")=="verbose")
	                tell_object(me, sprintf(GRN "damage: %d, wound: %d\n" NOR, damage, wound));
		if(damage>0) {
			victim->receive_damage("kee", damage, me);
			if(wound >0) victim->receive_wound("kee", wound, me);
			msg+=COMBAT_D->damage_msg(damage,"伤害");
		}
		if(random(me->query("sen")*100/me->query("max_sen") + me->query_int()*me->query_cps()) > 150) {
			me->improve_skill("throwing", 1);
			if(lucky) {
				me->set("combat_exp",me->query("combat_exp")+1);
				if(me->query("potential")-me->query("learned_points")<100)
					me->set("potential",me->query("potential")+1);
			}
		}
	}
	else 
		msg+="但是被$n躲开了。\n";

	if((int)ob->query_amount()==1) {
		if(stringp(ob->query("equipped"))) ob->unequip();
		tell_object(me, "你的" + ob->query("name") + "用完了！\n");
	}
	ob->add_amount(-1);

	message_vision(msg, me, victim);
	if(damage > 0) 
		COMBAT_D->report_status(victim);

	if(found) {
		if(living(victim)) {
			msg="$n怒视$N，大声喝道：小兔崽子敢使暗器！\n";
			message_vision(msg, me, victim);
			if(userp(victim)) victim->fight_ob(me);
			else victim->kill_ob(me);
			me->kill_ob(victim);
		}
	}
	else {
		msg="$n一脸茫然，嘴里嘟囔道：是谁？是谁？\n";
		message_vision(msg, me, victim);
	}

	me->start_busy(1+random(2));
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: throw <something> on <someone>

这一指令让你可以向某人发射暗器。
HELP
   );
   return 1;
}
