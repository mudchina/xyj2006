
// 应dxh建议 改动 命中率和damage

#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「雷动九天」只能在战斗中使用。\n");
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用「雷动九天」！\n");
        if( (int)me->query_skill("dragonfight", 1) < 100 ||
           (int)me->query_skill("unarmed", 1) < 100 
                             )
                return notify_fail("你有的功夫还不够娴熟，不会使用「雷动九天」。\n");
        if(me->query_skill("force", 1) <100)
                return notify_fail("以你现在的内功修为还使不出「雷动九天」。\n");        
        if (me->query_skill_mapped("unarmed") != "dragonfight")
                return notify_fail("你现在无法使用「雷动九天」进行攻击。\n");                                                                                 
        if( (int)me->query("max_force") < 1200 )
                return notify_fail("你的内力修为太弱，不能使用「雷动九天」！\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
        if( time()-(int)me->query_temp("leidong_end") < 10 )
                return notify_fail("绝招用多就不灵了！\n");
                
        me->set_temp("leidong_end",time());
        msg = RED "\n 突然$N大喝一声:「雷动」,面色唰的变得通红,须发皆飞,浑身上下充满杀气,\n" NOR;
        message_vision(msg, me, target); 
       msg = YEL "\n        “嗡”的一声，一掌凌空击向$n的胸口！\n" NOR;
if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2))
         )
        {
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("dragonfight", 1);
                damage = damage + random(damage/2);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("dragonfight", 1) > 119)
                   call_out("perform2", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIY"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
        }

        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
        msg = MAG "\n只见$N衣袍鼓起，猎猎飞舞，身子凌空飞起，又是一声大吼「九天」，\n" NOR;
        message_vision(msg, me, target); 
       msg = CYN "\n       “哗”的挥出九个光圈，居高临下，直向$n逼来。\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("dragonfight", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("dragonforce", 1);
                damage = (damage + random(damage))/2;
                
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                me->add("force", -random(damage/10));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
