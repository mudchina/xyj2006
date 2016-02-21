//yanluo歌舞阎罗
//2001 lestat for zhuihun-sword

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「歌舞阎罗」只能对战斗中的对手使用。\n");
		if(me->query("family/family_name") != "阎罗地府")
                return notify_fail("「歌舞阎罗」是地府不传之密！\n");

        if( me->query_temp("yunwu") )
                return notify_fail("你已经使出「歌舞阎罗」了！\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何能施展「歌舞阎罗」？\n");

        if( me->query_skill("dodge") < 100 )
                return notify_fail("你的轻功修为未到，难以施展「歌舞阎罗」的变幻之处！\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("你在剑法上的造诣不足以使出「歌舞阎罗」！\n");

        if( me->query("force") <= 200 )
                return notify_fail("你的内力不够施展「歌舞阎罗」！\n");

        skill = me->query_skill("sword");

	if(random(target->query_skill("parry"))>skill) {
        message_vision(HIW "\n$N意欲使出"+HIR"「歌舞阎罗」"+HIW"，但是$n严加戒备，全身门户，无不守备綦谨，难以奏效！\n" NOR, me, target);
	me->start_busy(2);
	}
	else{
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIC "\n但见寒光陡闪，$N手中"+weapon->query("name")+HIC"越使越快，如梦如幻，正是追魂剑绝技"+HIR"「歌舞阎罗」"NOR+HIC"！\n" NOR, me, target);

        me->set_temp("yunwu", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/2);
	}
        me->add("force", -200);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
	weapon = me->query_temp("weapon");

        if ( me->query_temp("yunwu")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n你手中没有持剑，「歌舞阎罗」的攻势便即瓦解！\n" NOR);
		me->delete_temp("yunwu");
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「歌舞阎罗」的攻势！\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( (int)me->query("force") < 400  ) {
                tell_object(me, "\n你的内力后继不足，难以持续「歌舞阎罗」的威力，只好收缓剑招。\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "zhuihun-sword" ) {
                tell_object(me, "\n你转而施展其他剑法，无法再以「歌舞阎罗」攻敌！\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，当下收回了「歌舞阎罗」的攻势。\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  

void remove_effect(object me, int amount)
{

        if ( me->query_temp("yunwu") ) {
                message_vision(HIW"\n$N剑招渐缓，已将一套「歌舞阎罗」使完！\n" NOR, me);
        me->delete_temp("yunwu");
        }
}

