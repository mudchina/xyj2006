//handudao-blue.c
//this blade has ice_poison with it...weiqi, 970926.
//add duandao断刀射人...weiqi, 980203.

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIB "冰刀" NOR, ({"ice blade", "blade", "dao"}));
	set_weight(5000);
	set("unit", "把");
	set("long", "一把淡蓝色，晶莹透明的弯刀，以大雪山中千年不化的寒冰制成。\n");
	set("value", 8000);
	set("material", "ice");
	set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中，眼中射出一道寒意！\n");
	set("unwield_msg",
"$N将手中的$n插入腰间，嘴里轻轻地舒了口气。\n");

	init_blade(20);

	if( clonep(this_object()) ) {
		set_default_object(__FILE__);
	}
	setup();
}

void init()
{
	add_action("do_duandao", "duandao");

	remove_call_out("do_melt");
	call_out("do_melt", 1);
}

void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
	object env;

        if(!this_object()) return;

	env=environment(this_object());

	if( env->is_character() )
	{//a player or a NPC.
                if( (int)env->query_skill("force", 1) < 60 )
		{
			message_vision("$N觉得身上凉凉的，湿湿的，原来是冰刀化了。\n", env);
			env->apply_condition("ice_poison", 10);
			//note, 中毒了。
			destruct(this_object());
			return;
		}
	}

	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "xueshan" )
		{
			tell_object(env,"冰刀终于化成了一滩水，流得到处都是。\n");
			destruct(this_object());
			return;
		}
	}

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int diff;

	if( damage_bonus < 0 ) return 0;
	diff = random((int)me->query("force_factor")+1) - random((int)victim->query("force_factor")/2+1);
	//here we let force_factor determine who hurts who:)
	//the attacker has more chance of course.

	if(diff > 0)
	{
		victim->apply_condition("ice_poison", diff + (int)victim->query_condition("ice_poison") );
		message_vision("$N身子一颤，中了刀上的寒毒！\n", victim);
	}
	else if(diff < -3)
	{//for very weak ppl or npc, also possible to "force back", this
	 //is to ensure it'll not happen.
		me->apply_condition("ice_poison", -diff + me->query_condition("ice_poison") );
		message_vision("$N身子一颤，原来是刀上寒毒被$n逼了回来，伤人不成反害己！\n", me, victim);
	}
	else 
		message_vision("$N觉得一阵寒意袭来，差点中了刀上的寒毒！\n", victim);
}

int do_duandao(string arg)
{
	string msg;
	int success, ap, dp;
	object me, target;

	me = this_player();
	
	if( this_player()->is_busy() )
		return notify_fail("你正忙着呢，哪有空运力断刀。\n");

	if( me->query("force") < 300 ) return notify_fail("这要靠内力而不是蛮劲。\n");

	if( ! arg )
	{
		message_vision(HIW "$N运力一震，只见冰花四溅！一把冰刀顿时化为无数碎片。\n" NOR, me);
		me->start_busy(3);

		me->add("force", -100);
		destruct(this_object()); //let this ice blade disappear.
		return 1;
	}

	//now find the target...
	if( !objectp( target = present(arg, environment(me)) ) )
		return notify_fail("你想用冰刀射谁？\n");

	if( !target->is_character() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if( !living(target) )
		return notify_fail(target->name() + "已无还手之力，一刀砍下去即可，何必炫耀功夫。\n"); 

	if(target==me)     return notify_fail("想自杀？\n");

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("你不能在这里偷袭别人。\n");

          if ( ! target->query("env/pk") && userp(target) )
                      return notify_fail("笨蛋，这也能杀？\n");

	msg = HIW
"$N运力一震，只见冰花四溅！一把冰刀顿时化为无数碎片向$n激射而去！\n" NOR;
	//produce kill here...
	target->kill_ob(me);

	success = 1;
	ap = me->query_skill("throwing");
	ap = ap * ap * ap /10 ; //usually no throwing skill, so not useful...
	ap += (int)me->query("combat_exp");
	ap = 2*ap; //make it easier.
	
	dp = target->query_skill("dodge");
	dp = dp * dp * dp /10 ; //dodge is useful here.
	dp += target->query("combat_exp");
	if( random(ap + dp) < dp ) success = 0;
	//here we compared exp and throwing, dodge levels. 

	//now check if the target is busy or no_move...
	//if so, we set success = 1.
	if(success == 0)
	{//here only check this if previously failed.
		if( target->is_busy() || target->query_temp("no_move") ) 
		//target can not move at all...
		{
			if( target->query("force")/40 > (10+me->query("force_factor")) )
			//btw, target still have chance...
			{		
				msg +=  HIW "结果$n虽然动弹不得，运功硬挡之下，倒也无甚大害。\n" NOR;
				message_vision(msg, me, target);	
				me->start_busy(3);

				me->add("force", -200);
				destruct(this_object()); //let this ice blade disappear.
				return 1;	
			}
			else success = 1; 
		}
	}//end of check 动弹不得。

	if(success == 1 )
	{
		msg +=  HIW "结果千万片冰块没体而入，$n顿时发出一声惨叫！\n" NOR;
		message_vision(msg, me, target);

		//here also apply poison..
		target->apply_condition("ice_poison",  5 + (int)me->query("force_factor")/5 + (int)target->query_condition("ice_poison") );

		target->receive_wound("kee", random(3*me->query("force_factor"))+50, me);
		COMBAT_D->report_status(target);
	}    
	else
	 {
		msg +=  HIW "结果$n轻轻一跳，躲了开去。\n" NOR;
		message_vision(msg, me, target);		
	}
	
	me->start_busy(3);

	me->add("force", -200);
	destruct(this_object()); //let this ice blade disappear.
	return 1;	
}

