#include <ansi.h>

inherit SSERVER;
mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
        "enter":        "里",
]);



int cast(object me, object target)
{
        string msg;
        int damage, ap, dp, success, n, i;
	object env, obj;
	string *dirs, target_dir, dest;
	mapping exit;
	
	seteuid(getuid());

        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="火云洞")
return notify_fail("只有火云洞门人才可以用！\n");
        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("你要现真身去撞谁？\n");

        if((int)me->query_skill("pingtian-dafa", 1) < 30 )
                return notify_fail("你的平天大法火候不够，哪里施展的出！\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够，恐怕没有什么用！\n");

        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不够。\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你现在神智不清，别把自己撞伤了！\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->add("force", -30);
        me->receive_damage("sen", 10);

	success=0;

	
        msg = HIC "\n\n$N猛然退后两步，一低头，呼地就向$n撞去！\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp) > dp ) 
        {
                damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
                damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
		damage += random( (int)me->query("force_factor") );
                //here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) 
                {
                        //finally damage also depends on enabled spells level.
                        damage +=random((damage*(int)me->query_skill("spells"))/100);
			
                        msg += HIC "结果$n躲闪不及，被撞的" NOR;

			env=environment(me);
			exit=env->query("exits");

			if( mapp(exit)) {
				dirs=keys(exit);
				n=sizeof(exit);
				i=random(n);
				dest=exit[dirs[i]];
				if(!undefinedp(default_dirs[dirs[i]]))
					target_dir=default_dirs[dirs[i]];
				else
					target_dir=dirs[i]; 

				if( obj=load_object(dest)) {
					success=1;
					msg+= HIC "向" +target_dir+ NOR;
				}

			}


			msg += HIC "飞了出去！\n\n" NOR;

			if( success == 1){
				if( target->move(obj) ) {

tell_room(environment(target),	HIR"\n只见"+target->name()+"象捆稻草般的飞了过来！\n" NOR, ({target,
target}));
				}
			}
                        target->receive_damage("kee", damage, me);
                }
                else 
                {
                        //here, cast failed and the target's mana_factor will be added to the previous 
                        //damage to hurt yourself:(...note, damage<0.
                        msg += HIC "结果被$n以法力一逼，$N没撞上去，自己反而受了内伤！\n" NOR;
                        damage -= (int)target->query("mana_factor");
                        damage -= random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("kee", -damage/2, target);
                }
        } 
        else
                msg += "但是被$n躲开了。\n";

        message_vision(msg, me, target);

        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
        //damage=0 corresponding to "但是被$n躲开了。\n"--no report.

        if( !target->is_fighting(me)) 
        {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        return 3;
}

