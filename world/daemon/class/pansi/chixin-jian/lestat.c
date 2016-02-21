//lestat for moon
//2001 三无三不手
 
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「红颜白发」?\n");
        if(me->query_temp("BAIFA_perform")) 
                return notify_fail("你已经使出「红颜白发」了！\n");
        if( time()-(int)me->query_temp("BAIFA_end") < 10 )
                return notify_fail("绝招用多就不灵了！\n");
        if (!present("wuxian qin", me))
                return notify_fail("你手中无琴如何弹奏?\n");
        if(!me->is_fighting(target) )
                return notify_fail("红颜白发只能在战斗中使用!!\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") <500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("chixin-jian",1) <100)
                return notify_fail("你的痴心剑级别还不够施展这一招红颜白发!!\n");
        if((int)me->query_skill("yueying-wubu",1) <100)
                return notify_fail("你的月影舞步等级不够!!\n");
        if((int)me->query_skill("qin",1) <100)
                return notify_fail("你的琴艺等级不够!!\n");
        if ( me->query_skill_mapped("parry") != "chixin-jian" )
                return notify_fail("你无法使用红颜白发!!\n");
        if (!present("wuxian qin", me))
                return notify_fail("「红颜白发」必须有七弦琴配合才能使用。\n");
        if(me->query("family/family_name") != "盘丝洞" )
                return notify_fail("你不是盘丝洞门人,琴艺早已生疏!!\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
        weapon=me->query_temp("weapon");
     msg = HIM  "$N跳出站圈，取琴一张，盘膝坐在地上，将琴放在膝上，十捐尖尖拨动琴弦，竟是［痴心情长剑法］的精髓－－
	\n"HIR"             『红颜"HIW"白发』
	\n"MAG"－－只见$N"HIW"白发"NOR+MAG"飘飘，双指轮弹，漫天"HIW"白发"NOR+MAG"氤氲般卷向$n！\n\n" NOR;
    message_vision(msg, me, target);
        skill = me->query_skill("whip");
        me->set_temp("BAIFA_perform", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/2);
        me->add("force", -200);
        return 1;
}
void checking(object me, object target)
{

	object weapon;
	weapon = me->query_temp("weapon");

        if ( me->query_temp("BAIFA_perform")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n你无法使用痴心情长剑，「红颜白发」的攻势便即瓦解！\n" NOR);
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if (!present("wuxian qin", me)) {
                tell_object(me, "\n你手中无琴如何弹奏?\n\n" NOR);
                me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「红颜白发」的攻势！\n\n" );
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if ( (int)me->query("force") < 1000  ) {
                tell_object(me, "\n你的内力后继不足，难以持续「红颜白发」的威力。\n\n" );
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if ( (int)me->query("sen") < 200  ) {
                tell_object(me, "\n你的精神太差，只好收起「红颜白发」。\n\n" );
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if ( me->query_skill_mapped("sword") != "chixin-jian" ) {
                tell_object(me, "\n你转而施展其他鞭法，无法再以「红颜白发」攻敌！\n\n" );
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if ( me->query_skill_mapped("parry") != "chixin-jian" ) {
                tell_object(me, "\n你转而施展其他剑法，无法再以「红颜白发」攻敌！\n\n" );
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，当下收回了「红颜白发」的攻势。\n\n" );
		me->delete_temp("BAIFA_perform");
		me->set_temp("BAIFA_end",time());
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  



void remove_effect(object me, int amount)
{       
	if ( me->query_temp("BAIFA_perform") ) {
        message_vision(HIM"$N心头一酸,轻声叹道:弹指红颜老,刹那芳华。\n"NOR, me);
        me->delete_temp("BAIFA_perform");
        me->set_temp("BAIFA_end",time());
         }
}
