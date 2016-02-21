// jinguzhou.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg, name;
        int damage, ap, dp, howlong=0;
	object ob;

        if( !target ) target = offensive_target(me);

        if( !(ob = present("jingu zhou", me))) 
                return notify_fail("你身上没有紧箍咒、金箍咒或禁箍咒，无法施用咒语！\n");
	name="“"+ob->query("name")+"”";

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁念"+name+"？\n");
		if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("不是佛门弟子不能用「金箍咒」！\n");

        if((int)me->query_skill("spells") < 100)
                return notify_fail("你还没学会念"+name+"。\n");

	if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你无法集中精力，别施用到自己头上！\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIC
"$N默默地将那"+name+"念了几遍。\n" NOR;
 
        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 +
random((int)target->query("eff_sen") / 5);         
                damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
                msg += HIC "把个$n痛得竖蜻蜓，翻筋斗，耳红面赤，眼胀身麻，不由得抓破了自己的头！\n" NOR;
//finally damage also depends on enabled spells level.
                damage +=random((damage*(int)me->query_skill("spells"))/80);
		if (name != "“紧箍咒”") damage /= 2;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
			target->set_temp("no_move", 1);
                        me->improve_skill("buddhism", 1, 1);
                howlong = 15 + random((me->query_skill("spells") -100));
                if(howlong>60) howlong=60;
		if (name != "“紧箍咒”") howlong /= 2;
//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.

                }
		else msg += "但是什么也没发生。\n";
             } 
        else
                msg += "但是什么也没发生。\n";

        message_vision(msg, me, target);

        if( damage > 0 ) {
		destruct(ob);
		COMBAT_D->report_status(target);
		call_out("free", howlong, target);
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->fight_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

void free(object target)
{
        if(target) target->delete_temp("no_move");      
        return;
}


