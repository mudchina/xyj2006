//气剑指(qijian)--大雅古剑法
//lestat /6/5/2001改编自六脉神箭

#include <ansi.h>
inherit SSERVER;

#include "/daemon/class/xuanyuan/daya-jian/eff_msg.h";
#include "/daemon/class/xuanyuan/daya-jian/qijian_msg.h";
int check_fight(object me, int amount, object weapon);
int check_qijian(object me, object target);
private int remove_effect(object me, int amount);
int perform(object me, object target)
{       
        string msg;
        int damage, p, skill;
		object weapon = me->query_temp("weapon");  
        if(!me->query_skill("daya-jian", 1)) return 0;  
        
        if(((int)me->query_skill("daya-jian", 1) < 300 ||
            (int)me->query_skill("sword", 1) < 300) && 
            !me->query_skill("force"))
                return notify_fail("你的剑术基本功夫还不够娴熟，就想乱用「气剑指」？\n");

//        if(!me->query_skill("beiming-shengong", 1))
//           if(me->query_skill("kurong-changong", 1) <100)
//                return notify_fail("以你现在的内功修为还使不出「六脉神剑」来。\n");        
         
//        if (me->query_skill_mapped("force") != "beiming-shengong" )
//           if (me->query_skill_mapped("force") != "kurong-changong")
//                return notify_fail("你所使用的内功不对。\n"); 
      
        if( (int)me->query("max_force") < 2500 )
                return notify_fail("你的内力修为太弱，根本使不出「气剑指」来！\n");
        if( (int)me->query("force") < 1000 )
                return notify_fail("你的真气不够！\n");
      if( me->query_temp("zxzx") ) 
        return notify_fail("你正在运功,不能分心他用！\n");
        if(me->query_temp("start_qijian")) return notify_fail("你已经在运用气剑指的无形剑气了！\n");

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「气剑指」只能在战斗中使用。\n");

//        tell_object(me, HIW"\n你先行存念，手中长剑脱手飞起,然后鼓气出指，内劲真气勃发，开始运用气剑指！\n"NOR);
        msg = HIW"\n$N先行存念，手中$w"+NOR+HIW"脱手飞起，绕周身盘旋飞舞，然后鼓气出指，内劲真气勃发，开始运用气剑指！\n" NOR;
		msg=replace_string(msg,"$w",weapon->query("name"));
		message_vision(msg, me, target);
		me->set_temp("start_qijian", 1);
		skill = me->query_skill("daya-jian");
	me->add_temp("apply/dodge",  skill*2);    
    me->add_temp("apply/parry",  skill*2);
    me->add_temp("apply/attack",  skill/2);
		check_fight(me, skill, weapon);
//        remove_call_out("check_qijian");        
//        remove_call_out("checking");
//        call_out("check_qijian", 2, me, target);
//        call_out("checking", me->query_skill("daya-jian", 1), me);
		check_qijian(me,target);
        return 1;
}
/*
int checking(object me)
{
        if(me->query_temp("start_qijian")){
              me->delete_temp("start_qijian");
              tell_object(me, HIW"\n你内劲运行一周天，将气剑指的招数用了一遍！\n"NOR);
              }
        return 1;
}
*/
int check_qijian(object me, object target)
{
        string msg, *limbs, dodge_skill, str, limb;
        int lv, i, force, ap, dp, damage, p, j;
        mapping act, *action;
        object wep;
		object weapon = me->query_temp("weapon"); 
        lv = (int)me->query_skill("daya-jian", 1);

       
 action = ({
([      "action" : qijian_msg[random(3)],
        "t_msg" : target_msg[random(2)],
        "damage" : 5,
        "lvl" : 0,
        "skill_name" : "盘庚剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[3+random(2)],
        "t_msg" : target_msg[2+random(2)],
        "damage" : 6,
        "lvl" : 30,
        "skill_name" : "毕命剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[5+random(4)],
        "t_msg" : target_msg[4+random(2)],
        "damage" : 6,
        "lvl" : 60,
        "skill_name" : "罔命剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[9+random(3)],
        "t_msg" : target_msg[6+random(2)],
        "damage" : 4,
        "lvl" : 90,
        "skill_name" : "至诚剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[12+random(4)],
        "t_msg" : target_msg[8+random(2)],
        "damage" : 3,
        "lvl" : 120,
        "skill_name" : "瞽蒙剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[16+random(3)],
        "t_msg" : target_msg[10+random(2)],
        "damage" : 7,
        "lvl" : 150,
        "skill_name" : "止戢剑",
        "damage_type" : "刺伤"
]),
([      "action" : qijian_msg[random(sizeof(qijian_msg))],
        "t_msg" : target_msg[random(sizeof(target_msg))],
        "damage" : 2+random(8),
        "lvl" : 200,
        "skill_name" : "大雅剑",
        "damage_type" : "刺伤"
]),
});

        if (lv >= 200) j = 6;
        else if (lv >= 150) j = 5;
        else if (lv >= 120) j = 4;
        else if (lv >= 90) j = 3;
        else if (lv >= 60) j = 2;
        else if (lv >= 30) j = 1;
        else j = 0;
        act = action[random(j)];
        damage = act["damage"];
        msg = act["action"];
        force = (int)me->query("force");        

        if(!living(target) || !target || !me->is_fighting() || environment(me) != environment(target)){
                me->delete_temp("start_qijian");
                return 1;
                }
       if(!me->query_skill("daya-jian", 1) || !me->query_temp("start_qijian")){
                me->delete_temp("start_qijian");
                return 1;
                } 
/*        
        if(!living(me) || me->is_ghost()){
                me->delete_temp("start_qijian");
                return 1;
                }
//        if (me->query_skill_mapped("force") != "beiming-shengong" )
//           if (me->query_skill_mapped("force") != "kurong-changong"){
//                tell_object(me,"你变换了内功，无法再使用「六脉神剑」进行攻击了。\n"); 
//                me->delete_temp("start_qijian");
//                return 1;
//                }   */
        if(force < 2500){
                tell_object(me,"你发现自己现在的真气太弱，已经不够使出「气剑指」了。\n");           
                me->delete_temp("start_qijian");
                return 1;
                }      
        if(me->is_busy()){
                call_out("check_qijian", 2+random(8-j), me, target);
                return 1;
                }

        ap = me->query_skill("force") + me->query_skill("daya-jian", 1) + me->query_int();
        dp = target->query_skill("force", 1) + target->query_skill("dodge") + target->query_int();
        ap *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
        
        limbs = target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg, "$l", limb);
if (me->query_temp("weapon"))
		msg=replace_string(msg,"$w",weapon->query("name"));
        message_vision(msg, me, target);
        tell_object(target, HIR+act["t_msg"]+NOR); 
        wep = target->query_temp("weapon");

        if( random(ap+dp) > dp/2 ){
             me->add("force", -damage*25);
             damage *= lv/2;
             damage -= target->query_temp("apply/armor")/2;
             damage += me->query("force_factor")*4;
             if(force > target->query("force")*2) damage = damage*2;          
             if(damage > 2500) damage = 2500;

//the target has a weapon in hand
             if(objectp(wep) && random(2) == 1){   
//			 if(objectp(wep)){
                   if(me->query("force") < target->query("force")/2){
                        me->start_busy(1);
                        msg = HIY"结果只听哐的一声，$n"HIY"用手中$W"HIY"竟然接下了那$w！\n" NOR;                        
                        }
                   else if(me->query("force") >= target->query("force")*2){
                         if(wep->query("rigidity") >= 3){
                               me->start_busy(1);
                               wep->move(environment(target));
                               target->receive_damage("kee", 50);  
                               target->receive_wound("kee", 25);      
                               msg = HIW"结果只听啪的一声，$n"HIW"拿捏不住$W"HIW"被脱手震飞，虎口也在猛烈撞击下震裂！\n" NOR;
                               target->reset_action();
                               }
                         else{
                                me->start_busy(1);
                                msg = HIW"结果只听拍的一声响，$n手中$W"HIW"为$N的$w"HIW"所断，化为寸许的二三十截，飞上半空，闪出点点白光！\n" NOR;
                                msg = replace_string(msg, "$W", wep->name());
                                wep->unequip();
                                wep->move(environment(target));
                                wep->set("name", wep->query("name")+"碎片");
                                wep->set("value", 0);
                                wep->set("unit", "些");
                                wep->delete("long");
                                wep->set("weapon_prop", 0);
                                target->reset_action();
                                }
                        }       
                   else {       
                         if(wep->query("rigidity") >= 8){
                                me->start_busy(1);
                                msg = HIY"结果只听一声大响，$W"HIY"在$w"HIW"的冲击下不住颤抖，飞花四溅！\n" NOR;
                                }
                         else{
                                me->start_busy(1);
                                wep->move(environment(target));  
                                msg = HIW"$n慌忙举$W"HIW"一挡，当的一声后，那"+wep->query("unit")+"$W"HIW"又被震飞！\n" NOR;
                                target->reset_action();
                                }
                         }
                   msg = replace_string(msg, "$W", wep->name());
                   msg = replace_string(msg, "$w", "无形剑气");          
                   message_vision(msg, me, target);
                   call_out("check_qijian", 2+random(8-j), me, target);
                   }
             else{
                   target->receive_damage("kee", damage);
                   target->receive_wound("kee", damage/(2+random(4)));          
                   p = (int)target->query("kee")*100/(int)target->query("eff_kee");
                   msg = damage_msg(damage, act["damage_type"]);
                   msg += "( $n"+eff_status_msg(p)+" )\n";
                   msg = replace_string(msg, "$l", limb);
                   msg = replace_string(msg, "$w", "无形剑气");          
                   message_vision(msg, me, target);
                   if(wizardp(me)) tell_object(me, "qijian_damage: "+damage+" \n");
				   msg=HIB"\n但见空中蓝光闪烁，$w"HIB"在空中盘旋,时而飞回$N手中。\n"NOR;
if (me->query_temp("weapon"))
				   msg=replace_string(msg,"$w",weapon->query("name"));
				   message_vision(msg, me, target);
                   call_out("check_qijian", 2+random(8-j), me, target);                   
                   }
            }
        else{
             me->start_busy(1);
//             HIY"$N全力向后一纵一闪，凶险万分地避开了那急速而来的无形剑气！\n"NOR, target);
             dodge_skill = target->query_skill_mapped("dodge");
	     if( !dodge_skill ) dodge_skill = "dodge";
             message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
             call_out("check_qijian", random(8-j), me, target);    
             } 
//		call_out("check_qijian", 1, me, target);  
/*       if(target->query("kee")*2 <= target->query("max_kee")
           && !target->is_killing(me->query("id"))
           && !me->is_killing(target->query("id"))){
             me->remove_enemy(target);
             target->remove_enemy(me);
             if (me->query("race") == "人类") {
				if (!me->query("mute") && target->query("mute"))
					message_vision( winner_msg[random(sizeof(winner_msg)/2)], me, target);
					if (me->query("mute") && !target->query("mute"))
						message_vision(winner_msg[sizeof(winner_msg)/2 + random(sizeof(winner_msg)/2)], me, target);
					if (!me->query("mute") && !target->query("mute"))
						message_vision( winner_msg[random(sizeof(winner_msg))], me, target);
			} else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, target);
	     }
*/
       return 1;
}       

int check_fight(object me, int amount, object weapon)
{  
    object wep;    
    if(!me) return 0;
    wep = me->query_temp("weapon");  
    if(!me->is_fighting() || !living(me) || me->is_ghost() || !wep || weapon != wep )
        remove_effect(me, amount);

    else {
	call_out("check_fight", 1, me, amount, weapon);
	me->start_perform(1, "气剑指");
    }
    return 1;
}

private int remove_effect(object me, int amount)
{
	string msg;
	object weapon = me->query_temp("weapon"); 
	object target;
	me->add_temp("apply/dodge", -amount*2);
    me->add_temp("apply/parry", -amount*2);
    me->add_temp("apply/attack", -amount/2);
    me->delete_temp("start_qijian");
    if(living(me) && !me->is_ghost())
if (me->query("weapon"))
{
		msg=replace_string(msg,"$w",weapon->query("name"));
         msg = HIB"\n一道蓝光闪过，$w"HIB"飞回$N手中！\n" NOR;
		message_vision(msg, me, target);
//		msg=replace_string(msg,"$w",weapon->query("name"));
//      message_vision(HIB"一道蓝光闪过，$w飞回$N手中。\n"NOR, me);
}
    return 0;
}



