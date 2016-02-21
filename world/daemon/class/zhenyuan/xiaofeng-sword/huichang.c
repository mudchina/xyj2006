//by fly 6-6-2000

#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

string *xue_name = ({ 
HIR"劳宫穴"NOR,HIR"膻中穴"NOR,HIR"曲池穴"NOR,
HIG"关元穴"NOR,HIG"曲骨穴"NOR,HIG"中极穴"NOR,
HIY"承浆穴"NOR,HIY"天突穴"NOR,HIY"百会穴"NOR,
HIM"幽门穴"NOR,HIM"章门穴"NOR,HIM"大横穴"NOR,
HIW"紫宫穴"NOR,HIW"冷渊穴"NOR,HIW"天井穴"NOR,
HIC"极泉穴"NOR,HIC"清灵穴"NOR,HIC"至阳穴"NOR,}); 
string *weapon1_name = ({ HIR"剑气"NOR,HIR"左手剑"NOR,HIG"快剑"NOR}); 
string *weapon2_name = ({ HIW"半轮剑弧"NOR,HIB"一道闪光"NOR,HIR"无形剑气"NOR}); 
string *weapon3_name = ({ HBRED"回旋剑气"NOR,HBGRN"一道闪光"NOR,HBBLU"无数剑气"NOR}); 

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill,*limbs;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("["+HIR"回肠剑气"NOR+"]只能对战斗中的对手使用。\n");
                if(me->query("family/family_name") != "五庄观")
                return notify_fail("「回肠剑气」是五庄观不传之密！\n");
if( time()-(int)me->query_temp("HUICHANG_end") < 7 )
return notify_fail("绝招用多就不灵了！\n");
        if( (int)me->query_skill("xiaofeng-sword", 1) < 100 )
                return notify_fail("你的晓风残月剑法还不够熟练，不能使用"+HIR"回肠剑气"NOR+"对敌！\n");
        if( (int)me->query_skill("sword", 1) < 100 )
                return notify_fail("你的剑法不够娴熟，使不出"+HIR"回肠剑气"NOR+"！\n");
        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("你的内功不够娴熟，使不出"+HIR"回肠剑气"NOR+"！\n");
        if( (int)me->query_skill("parry", 1) < 100 )
                return notify_fail("你的招架不够娴熟，使不出"+HIR"回肠剑气"NOR+"！\n");
        if(! me->query_temp("weapon") )
                return notify_fail("你必须用剑才能使用「"+HIR"回肠剑气"NOR+"」！\n");
       if (me->query_skill_mapped("sword") != "xiaofeng-sword" || me->query_skill_mapped("parry") != "xiaofeng-sword")
                return notify_fail("你的剑法招架激发不够准确,使不出"+HIR"回肠剑气"NOR+"！\n");
        if( (int)me->query("max_force") < 1500 )
                return notify_fail("你现在内力修为不足，使不出"+HIR"回肠剑气"NOR+"！\n");     
        if( (int)me->query("force") < 1000 )
                return notify_fail("你现在内力不足，使不出"+HIR"回肠剑气"NOR+"！\n");     
/*
         if( me->query_temp("sqj_jianmang"))
                  return notify_fail("你刚使完「"+HIR"剑芒三连击"NOR+"」，目前气血翻涌，无法再次运用！\n");
*/
        message_vision(HIR "\n$N一声朗笑,手中长剑斜指向天,剑尖吐出一团尺余的银芒,似有灵性般吞缩不定!\n"NOR, me, target); 
        msg = HIG"突然之间，$N剑交右手，寒光一闪，剑拉弧形，直逼向$n,"NOR+xue_name[random(sizeof(xue_name))]+HIG"阵阵森森寒气。\n"NOR;
        me->set_temp("sqj_jianmang", 1);
me->set_temp("HUICHANG_end",time());
        if (random(me->query_skill("force")) > random(target->query_skill("force") /4)&&
            random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){                     
                me->start_busy(1);
                target->start_busy(1); 
                msg += CYN"$n大吃一惊，变招不及，$w"+CYN"已在他的"NOR+xue_name[random(sizeof(xue_name))]+CYN"对穿而出，真气不由一散。\n"NOR;
                damage = (int)me->query_skill("sword", 1);       
                damage = damage + random(damage/2);
                if(damage>1100) damage=1100;
                if(me->query_skill("zhenyuan-force",1) > target->query_skill("zhenyuan-force",1)
                && me->query("force") > random(target->query("force"))  ) 
                               damage += random(damage*3/2);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");

                msg += "( $n"+eff_status_msg(p)+" )\n";
                msg = replace_string(msg, "$w", weapon1_name[random(sizeof(weapon1_name))]);   
                message_vision(msg, me, target);
               target->set_temp("last_damage_from", me);
                me->add("force", -(int)me->query_skill("sword", 1)/2);
                remove_call_out("perform2");
                call_out("perform2", 0, me, target);  

              } 
        else {
                me->start_busy(1+random(1));
                msg += HIY"\n$n却识得那团剑芒的厉害,早已远远避在一边.\n" NOR;
                message_vision(msg, me, target);
/*
                remove_call_out("remove_effect");
                call_out("remove_effect", 2, me);
*/
              }

        return 1;
}

int perform2(object me, object target)
{
        int damage,p;
        string msg, dodge_skill,*limbs,force_skill,force_skill_name,wep;
        if (!me) return 1;
       if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){
           if(!wep)msg = HIY"$N手中武器既失，回肠剑气也随之消散，$n不禁松了口气．\n"NOR;
           else  msg = HIY"$N亮出"+wep->name()+HIY"而停止追击，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
           message_vision(msg, me, target);
           if(target->is_busy()) target->start_busy(1);
me->start_busy(1+random(2));
           me->delete_temp("sqj_jianmang");
           return 1;
           } 
       if (userp(me) && (me->query_skill_mapped("sword") != "xiaofeng-sword" || me->query_skill_mapped("parry") != "xiaofeng-sword")){
           message_vision(HIY"$N突然变招，划破剑幕，使出和晓风残月剑法完全不同的招数来！\n"NOR,me);
    if(!living(target)) return 1;
           if(target->is_busy()) target->start_busy(1);
me->start_busy(1+random(2));
           me->delete_temp("sqj_jianmang");
              return 1;
              }
if ((!me)||(!target)) return 1;
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           if(!living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+wep->name()+HIY"一向后摆，撤回了散开的剑幕．\n"NOR;
           else msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，停止了攻击．\n"NOR;
           if(target->is_busy()) target->start_busy(1);
           me->delete_temp("sqj_jianmang");
           message_vision(msg, me, target);
           return 1;
           }           
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 1000 )
           {message_vision(HIY"$N剑招渐见涩滞，刚才一剑刺出竟然软弱无力，原来是真气不足了！\n"NOR,me);
         if(target->is_busy()) target->start_busy(1);
me->start_busy(1+random(2));
           me->delete_temp("sqj_jianmang");
           return 1;
          }
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
else                if( force_skill=="yuxu-force" ) force_skill_name = "玉虚心法";
else                if( force_skill=="huomo-force" ) force_skill_name = "火魔心法";
else                force_skill_name = "无名内功";   
        msg = HIG "\n跟着，$N随式一转，右跨一步，蓦地剑交左手,剑势似是千变万化，剑气万重。\n"NOR;        
        if (random(me->query_skill("force")) > random(target->query_skill("force") /3)&&
            random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){            
                me->start_busy(1);
                target->start_busy(1);
                msg += CYN"只听$n一声惨嚎,剑气从"NOR+xue_name[random(sizeof(xue_name))]+CYN"掠过，$n连运"NOR+HIR+force_skill_name+NOR+CYN"，气血依然无法凝聚。\n"NOR;
                damage = (int)me->query_skill("sword", 1);       
                damage = damage*3/2 + random(damage);
                if(damage>500) damage=500;
                if(me->query_skill("zhenyuan-force",1) > target->query_skill("zhenyuan-force",1)
                && me->query("force") > random(target->query("force"))  ) 
                damage = damage*3/2 + random(damage/2);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                msg = replace_string(msg, "$w", weapon2_name[random(sizeof(weapon2_name))]);
                me->add("force", -(int)me->query_skill("sword", 1)/2);   
               target->set_temp("last_damage_from", me);
                message_vision(msg, me, target);    
        if( (int)me->query_skill("parry", 1) > 150 &&
            (int)me->query_skill("force", 1) > 150 &&
            (int)me->query_skill("sword", 1) > 150 &&
            (int)me->query_skill("xiaofeng-sword", 1) > 150 &&
            (int)me->query_skill("force", 1) > 150 ) {
                remove_call_out("perform3");
                call_out("perform3", 0, me, target); 
                }
        } 
        else 
        {
                me->start_busy(1+random(1));
                msg += HIY"\n$n顺势亦是右转，轻轻一带，竟然躲过这招"NOR+HIR"左手剑"NOR+HIY".\n" NOR;
                me->add("force", -(int)me->query_skill("sword", 1)/2);     
                message_vision(msg, me, target);    
        }

        return 1;
}
int perform3(object me, object target)
{
        int damage , p;
        string msg, weapon,dodge_skill,*limbs,force_skill,force_skill_name;
        if (!me) return 1;
       if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"){
           if(!weapon)msg = HIY"$N手中武器既失，回肠剑气也随之消散，$n不禁松了口气．\n"NOR;
           else  msg = HIY"$N亮出"+weapon->name()+HIY"而停止追击，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
           message_vision(msg, me, target);
           if(target->is_busy()) target->start_busy(1);
me->start_busy(1+random(2));
           me->delete_temp("sqj_jianmang");
           return 1;
           } 
       if (userp(me) && (me->query_skill_mapped("sword") != "xiaofeng-sword" || me->query_skill_mapped("parry") != "xiaofeng-sword")){
           message_vision(HIY"$N突然变招，划破剑幕，使出和晓风残月剑法完全不同的招数来！\n"NOR,me);
           if(target->is_busy()) target->start_busy(1);
me->start_busy(1+random(2));
           me->delete_temp("sqj_jianmang");
              return 1;
              }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           if(!living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+weapon->name()+HIY"一向后摆，撤回了散开的剑幕．\n"NOR;
           else msg = HIY"$N将手中"+weapon->name()+HIY"向后一摆，抱圆守一，停止了攻击．\n"NOR;
           if(target->is_busy()) target->start_busy(1);
           me->delete_temp("sqj_jianmang");
           message_vision(msg, me, target);
           return 1;
           }           
        if( (int)me->query("force", 1) < 1000 ){
           message_vision(HIY"$N剑招渐见涩滞，刚才一剑刺出竟然软弱无力，原来是真气不足了！\n"NOR,me);
         if(target->is_busy()) target->start_busy(1);
           me->start_busy(1);
           me->delete_temp("sqj_jianmang");
           return 1;
          }
        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");
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
else                if( force_skill=="yuxu-force" ) force_skill_name = "玉虚心法";
else                if( force_skill=="huomo-force" ) force_skill_name = "火魔心法";
else                force_skill_name = "无名内功";   
        weapon = me->query_temp("weapon");  
        msg = HIW "\n紧接着，$N飞身向前，身剑合一，所幻的光圈一圈一圈，$n全身已被套其中\n"NOR;        
        if (random(me->query_skill("force")) > random(target->query_skill("force") /3)&&
            random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){   
                me->start_busy(1+random(2));
                target->start_busy(1+random(3));
                msg += weapon3_name[random(sizeof(weapon3_name))]+WHT"刺穿$n的"NOR+HIR+force_skill_name+NOR+WHT",喀嚓一声$n的"NOR+HIM"手臂"NOR+WHT"已然绞断，"NOR+xue_name[random(sizeof(xue_name))]+WHT"被对穿而出。\n"NOR;
                damage = (int)me->query_skill("sword", 1);       
                damage = damage*2 + random(damage*2);
                if(damage>600) damage=600;
                if(me->query_skill("wuxiangforce",1) > target->query_skill("wuxiangforce",1)
                && me->query("force") > random(target->query("force"))  ) 
                damage = damage*3/2 + random(damage*3/2);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                 msg += damage_msg(damage, "砸伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
                limbs = target->query("limbs");
                msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
                msg = replace_string(msg, "$w", weapon->name());   
               target->set_temp("last_damage_from", me);
                me->add("force", -(int)me->query_skill("sword", 1)/2);
        } else 
        {
                me->start_busy(1);
                target->start_busy(1);
                msg += HIY"\n$n却识得那团光圈的厉害,中宫直入，势如破竹。\n" NOR;
                me->add("force", -(int)me->query_skill("sword", 1)/2);
        }
        message_vision(msg, me, target); 
        return 1;
}
void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sqj_jianmang");
        tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用"NOR+HIR"回肠剑气"NOR+"了。\n"NOR); 
}



