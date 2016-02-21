//Cracked by Roath
// gouhun.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

        success_adj = 150;
        damage_adj = 160;

        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n"); 
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要勾自己的魂？\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够了！\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("现在你自己就魂不守舍！\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("这次是鬼见鬼了！\n");
                return 1;
        }

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "$N对$n阴阴地笑着：阎王叫你三更死，不敢留你到五更。。。\n" NOR,
			//initial message
		HIC "$n受到$N影响，显然有点魂不守舍了！\n" NOR, 
			//success message
		HIC "但是$n神情专注，对$N理都不理。\n" NOR, 
			//fail message
		HIC "但是$n眼一瞪：光天化日之下，岂由恶鬼横行！\n" NOR, 
			//backfire initial message
		HIC "结果$n反而有点魂不守舍了！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);

}

