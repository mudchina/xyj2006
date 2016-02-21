//bawang-qiang, perform meihua
// /daemon/class/fighter/bawang-qiang/meihua
//梅花六出 要求霸王枪法70级，110级以后出6招
//writted by jie 2001-2-10
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「梅花六出」？\n");

        if(!me->is_fighting())
                return notify_fail("「梅花六出」只能在战斗中使用！\n");
                
        if(me->query("family/family_name") != "将军府" )
                return notify_fail("你是哪儿偷学来的武功，也想用「梅花六出」?\n");
	
//	if( me->query("pfm_meihua_on") != 1 )
//		return notify_fail("你还不会「梅花六出」。\n");                
                
        if (me->query_temp("bawang"))
           return notify_fail("你正在施用霸字诀，没有余力出「梅花六出」！\n");
        
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="spear")
                return notify_fail("「梅花六出」要用枪才能发挥威力。\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 300 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("你的精神不足，没法子施展梅花六出！\n");

        if(myskill < 40)
                return notify_fail("你的霸王枪法级别还不够。\n");
        else 
            if(myskill <70){
                times = 3;        
                number = "三";}
            else
                if (myskill <90){
                    times = 4;
                    number = "四";}
                else
                    if(myskill <110 ){
                           times = 5;
                           number = "五";}
                     else{ 
                           times = 6;
                           number = "六";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");
	damage = me->query_str() + random(me->query_skill("spear"));

message_vision(HIC"\n$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"枪，枪枪要命！\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20);
me->add("force", -(times*40+50));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && times>5)
	{
                target->receive_damage("kee",damage,me);
                target->receive_wound("kee", random(damage)/3, me);
                  			
		message_vision(HIR"\n$n只觉得眼前一花，胸口已被$N的"+ weapon->query("name")+ HIR"搠出一朵灿烂的六出梅花！！！\n\n六个窟窿鲜血喷涌而出．．$n已经气息奄奄．．\n" NOR,me,target);
		COMBAT_D->report_status(target, 0);
	}
        me->start_busy(1+random(2));
        return 1;
}

