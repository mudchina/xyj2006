// modify by fly
// 200_12_8
//lestat 2001 modi for fangcun


#include <ansi.h>
inherit SSERVER;

#include "/daemon/skill/eff_msg.h";
int def;
int perform(object me, object target)
{       
        object weapon1;
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「神猴狂舞」只能在战斗中使用。\n");
        if(me->query("family/family_name") != "方寸山三星洞")
                return notify_fail("[神猴狂舞]是斜月三星洞不传之密！\n");
       if( !(weapon1 = me->query_temp("weapon"))
        ||      (string)weapon1->query("skill_type") != "stick" )
                return notify_fail("你以为你是谁？没棒也发神猴狂舞！\n"); 
        if( (int)me->query_skill("stick", 1) < 100 ||
           (int)me->query_skill("qianjun-bang", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用「神猴狂舞」。\n");
        if((int)me->query_skill("dodge", 1) <120)
return notify_fail("以你现在的轻功修为如何「神猴狂舞」。\n");
        if((int)me->query_skill("force", 1) <100)
return notify_fail("以你现在的内功修为还使不出「神猴狂舞」。\n");
        if( (int)me->query("max_force") < 1200 )
return notify_fail("以你现在的内功修为还使不出「神猴狂舞」。\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
        msg = HIY "\n$N使出方寸山绝技「神猴狂舞」，身法陡然加快！\n" NOR;
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3))
        {
                me->start_busy(2);
                target->start_busy(1);
msg += YEL "\n$N忽然猛一吸气，抡棒回舞，向$n轻轻地劈出。"NOR;
if ((int)me->query_skill("force", 1)> random((int)me->query_skill("force", 1)/4))
                   {
        msg += HIC "\n但见$n大喝一声，愈以内力克制,结果$n只挡住开始两招，就无法再维持澎湃的乱舞。\n" NOR;
                damage = (int)me->query_skill("qianjun-bang", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage,me);
                me->add("force", -(damage/10));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
               target->set_temp("last_damage_from", me);
                if(me->query_skill("stick", 1) > 119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                    } else 
                {
        msg += HIC "\n初时似乎出手不重，但其波浪状的棍影后浪击前浪，一浪高过一浪，连绵不尽！\n"NOR;
        message_vision(msg, me, target);
for (p=1;p<3+random(3);p++)
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                if(random(me->query_skill("qianjun-bang", 1))> 119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                 }
        } else 
        {       me->start_busy(2);
                me->add("force", -100);                
                msg += HIG"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
   if(me->query_skill("qianjun-bang",1)>119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                 }
        message_vision(msg, me, target);
        }
        return 1;
}

// 第二击

int perform2(object me, object target)
{
  int damage, p,skill;
object weapon1;
        string msg,weapon,force_skill,force_skill_name;
if(!target||!living(target)) return notify_fail("对手已经不能再战斗了。\n");
    weapon = me->query_temp("weapon");  
if( !(weapon1 = me->query_temp("weapon"))
 ||      (string)weapon1->query("skill_type") != "stick" )
        return notify_fail("你以为你是谁？没棒也发神猴狂舞！\n");
                force_skill = target->query_skill_mapped("force");
                if( !force_skill ) force_skill_name = "基本内功";
else                if( force_skill=="huntian-qigong" ) force_skill_name = "混天气功";
else                if( force_skill=="lengquan-force" ) force_skill_name = "冷泉神功";
else                if( force_skill=="lotusforce" ) force_skill_name = "莲花心法";
else                if( force_skill=="moonforce" ) force_skill_name = "月宫心法";
else                if( force_skill=="ningxie-force" ) force_skill_name = "凝血神功";
else                if( force_skill=="wuxiangforce" ) force_skill_name = "小无相功";
else                if( force_skill=="dragonforce" ) force_skill_name = "龙神心法";
else                if( force_skill=="tonsillit" ) force_skill_name = "摄气诀";
else                if( force_skill=="xuanhu-xinfa" ) force_skill_name = "玄狐心法";
else                if( force_skill=="jiuyin-xinjing" ) force_skill_name = "九阴心经";
else                if( force_skill=="zhenyuan-force" ) force_skill_name = "镇元神功";
else                if( force_skill=="shushan-force" ) force_skill_name = "蜀山心法";
else                if( force_skill=="butian-force" ) force_skill_name = "补天心法";
else                if( force_skill=="xuanzong-force" ) force_skill_name = "玉虚心法";
else                if( force_skill=="huomo-force" ) force_skill_name = "火魔心法";
else                force_skill_name = "无名内功";
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「神猴狂舞现在没对手了呀。\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
if (random(5)>2)
       msg = HIC"\n但见$N倒拖兵器,突然一个仰身,大喝一声,募的绕身回劈,$n眼前一黑!!\n"NOR;
else
        msg = HIG"\n但见$N倒拖兵器,突然狂啸一声,抡棍横扫,声势刚烈,$n早已吓慌了手脚!!\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
        {
       msg = CYN "$n惊骇之下，"NOR+HIR+force_skill_name+NOR+CYN"顿时破绽百出，$n根本无从招架！\n" NOR;
                me->start_busy(2);
                target->start_busy(2);
                damage = (int)me->query_skill("qianjun-bang", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
              if(me->query_skill("qianjun-bang", 1) > 149)
                {
             remove_call_out("perform3");
                call_out("perform3", 0, me, target);    
                 }
        } else 
        {       me->start_busy(2);
//                me->add("force", -200);                
                msg = WHT"可是$p料敌之先,抢攻几招，反逼$N连连后退。\n"NOR;
                if(me->query_skill("qianjun-bang", 1) > 149
                && me->query_skill("stick", 1) > 149)
                {
             remove_call_out("perform3");
                call_out("perform3", 0, me, target);    
                 }
        }
        message_vision(msg, me, target);
        return 1;
}


int perform3(object me, object target)
{
  int damage, p,skill;
   object weapon1;
        string msg,weapon,force_skill,force_skill_name,*limbs;
if(!target||!living(target)) return notify_fail("对手已经不能再战斗了。\n");
    weapon = me->query_temp("weapon");  
  if( !(weapon1 = me->query_temp("weapon"))
             ||      (string)weapon1->query("skill_type") != "stick" )
     return notify_fail("你以为你是谁？没棒也发神猴狂舞！\n"); 
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「神猴狂舞现在没对手了呀。\n");
                force_skill = target->query_skill_mapped("force");
                if( !force_skill ) force_skill_name = "基本内功";
else                if( force_skill=="huntian-qigong" ) force_skill_name = "混天气功";
else                if( force_skill=="lengquan-force" ) force_skill_name = "冷泉神功";
else                if( force_skill=="lotusforce" ) force_skill_name = "莲花心法";
else                if( force_skill=="xuanhu-xinfa" ) force_skill_name = "玄狐心法";
else                if( force_skill=="moonforce" ) force_skill_name = "月宫心法";
else                if( force_skill=="ningxie-force" ) force_skill_name = "凝血神功";
else                if( force_skill=="jiuyin-xinjing" ) force_skill_name = "九阴心经";
else                if( force_skill=="wuxiangforce" ) force_skill_name = "小无相功";
else                if( force_skill=="dragonforce" ) force_skill_name = "龙神心法";
else                if( force_skill=="tonsillit" ) force_skill_name = "摄气诀";
else                if( force_skill=="shushan-force" ) force_skill_name = "蜀山心法";
else                if( force_skill=="butian-force" ) force_skill_name = "补天心法";
else                if( force_skill=="xuanzong-force" ) force_skill_name = "玉虚心法";
else                if( force_skill=="zhenyuan-force" ) force_skill_name = "镇元神功";
else                if( force_skill=="huomo-force" ) force_skill_name = "火魔心法";
else                force_skill_name = "无名内功";
        if( (int)me->query("force", 1) < 800 )
                return notify_fail("你待要再出第四击，却发现自己的内力不够了！\n");     
if (random(5)>2)
    {
        msg = HIC"\n$N一声咆哮，兵器竟然脱手飞出，如游龙般翱翔青宇，破空射向$n的左肩！\n"NOR;
       msg += HIC "$n大吃一惊，但见$N空手猱身而上，双手擒拿点拍，攻势凌厉之极!\n" NOR;
     }
else 
        msg = HIG"\n$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道棍影，弥漫天际！\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/8))
        {
       msg = CYN "$n慌乱中已经来不及运起"NOR+HIR+force_skill_name+NOR+CYN",$N抡起就是一棒\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
               //damage = damage*(1+random(3))/2+random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);
                me->add("force", -100);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "砸伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
           limbs = target->query("limbs");
           msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
           msg = replace_string(msg, "$w", weapon->name());    
        message_vision(msg, me, target);
               target->set_temp("last_damage_from", me);
                me->start_busy(2);
        } else 
        {       
              me->start_busy(1+random(2));
//                me->add("force", -200);                
                msg = HIC"可是$p一个反身,轻轻躲过$N凌厉的进攻。\n"NOR;
        message_vision(msg, me, target);
        }
//                me->add("force",-500);                
        return 1;
}

