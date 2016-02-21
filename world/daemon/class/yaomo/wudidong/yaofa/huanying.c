// 妖法－－幻影

#include <ansi.h>
#include <command.h>

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
	object env, obj;
	int mymana=me->query("mana"), cost=100, i, n;
	int success, ap, dp;
	string msg;
	string *dirs, target_dir, dest;
	mapping exit;

	seteuid(getuid());

	if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="陷空山无底洞")
return notify_fail("无底洞弟子才可以用！\n");
	if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这个法术？\n");

	if( !me->is_fighting(target))
		return notify_fail(target->query("name")+"都没在与你战斗，需要用幻影术救命吗？\n");

	if(target->query_temp("no_move"))
		return notify_fail(target->query("name")+"已经动弹不得了！\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢，过会儿再念咒吧！\n");

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("yaofa", 1) < 50)
		return notify_fail("你还没学会幻影术。\n");

        if( mymana < cost )
                return notify_fail("你的法力不够。\n");

	if((int)me->query("sen") < 10 )
                return notify_fail("你的精神没有办法有效集中！\n");

	env = environment(me);
	exit = env->query("exits");

	if( !mapp(exit)) 
		return notify_fail("你想将"+target->query("name")+"引到那儿去？\n");

	dirs = keys(exit);
	n = sizeof(exit);
	i = random(n);
if (exit[dirs[i]])
	dest = exit[dirs[i]];

	if( !undefinedp(default_dirs[dirs[i]]) )
                target_dir = default_dirs[dirs[i]];
        else
                target_dir = dirs[i];

	if(!(obj = load_object(dest)) )
		return notify_fail("无法走！\n");

	me->add("mana", -cost);
	me->receive_damage("sen", 10);

	msg = HIC "$N口中念了句咒文，张口喷出一股青烟。\n" NOR;
	msg += HIC "烟雾中只见一条人影向" + target_dir + "逃去。\n" NOR;

	success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;

	// mon 1/21/99
	message_vision(msg, me, target);
	if(success==1 && !GO_CMD->main(target, dirs[i], 0)) {
	    success=0; // failed to go.
	}

	if(success == 1) {
		msg = HIR +target->name()+
		    "向" + target_dir + "追去。\n" NOR;
	}
	else {
		msg = HIR "$n不为所动，幻影术失败了。\n" NOR;
	}

	message_vision(msg, me, target);

	if(success == 1) {
		msg = HIR "只见"+target->name()+
		    "跑了进来，四处张望，却什么都没发现。\n" NOR;
               	message( "vision", msg, environment(target), ({target}));
		tell_object(target,
			"你急急忙忙跑了过来，四处张望，却什么都没发现。\n");
               	return 5;
	} else {
		me->start_busy(1+random(2));
		return 3;
	}
}


