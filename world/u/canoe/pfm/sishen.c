// 由Canoe 修改 05-13-2001
// 个人认为攻击力偏大，

#include <ansi.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;

string *xue_name = ({ 
HIR"劳宫穴"NOR,HIR"膻中穴"NOR,HIR"曲池穴"NOR,
HIG"关元穴"NOR,HIG"曲骨穴"NOR,HIG"中极穴"NOR,
HIY"承浆穴"NOR,HIY"天突穴"NOR,HIY"百会穴"NOR,
HIM"幽门穴"NOR,HIM"章门穴"NOR,HIM"大横穴"NOR,
HIW"紫宫穴"NOR,HIW"冷渊穴"NOR,HIW"天井穴"NOR,
HIC"极泉穴"NOR,HIC"清灵穴"NOR,HIC"至阳穴"NOR,}); 
string *weapon1_name = ({ HIR"剑气"NOR,HIR"左手剑"NOR,HIG"快剑"NOR}); 
string *weapon2_name = ({ HIW"半轮剑弧"NOR,HIB"一道闪光"NOR,HIR"无形剑气"NOR}); 
string *weapon3_name = ({ HBRED"末日之刑"NOR,HBGRN"幽灵之光"NOR,HBBLU"死神之剑"NOR}); 

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill,*limbs;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("["+HIR"血魔死神"NOR+"]只能对战斗中的对手使用。\n");
        if(!wizardp(me)&&me->query("family/family_name")!="陷空山无底洞") return notify_fail("你认识死神?\n");
        if( (int)me->query_skill("qixiu-jian", 1) < 120 )
                return notify_fail("你的七修剑法还不够熟练，不能使用"+HIR"血魔死神"NOR+"对敌！\n");
        if( (int)me->query_skill("sword", 1) < 120 )
                return notify_fail("你的剑法不够娴熟，使不出"+HIR"血魔死神"NOR+"！\n");
        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("你的内功不够娴熟，使不出"+HIR"血魔死神"NOR+"！\n");
        if( (int)me->query_skill("parry", 1) < 120 )
                return notify_fail("你的招架不够娴熟，使不出"+HIR"血魔死神"NOR+"！\n");
        if(! me->query_temp("weapon") )
                return notify_fail("你必须用剑才能使用「"+HIR"血魔死神"NOR+"」！\n");
        if( (int)me->query("max_force") < 1500 )
                return notify_fail("你现在内力修为不足，使不出"+HIR"血魔死神"NOR+"！\n");     
        if( (int)me->query("force") < 1000 )
                return notify_fail("你现在内力不足，使不出"+HIR"血魔死神"NOR+"！\n");     
        if( me->query_temp("qxj_jianmang"))
                 return notify_fail("你刚使完「"+HIR"血魔死神"NOR+"」，目前气血翻涌，无法再次运用！\n");
        message_vision(HIB "\n$N阴阴一笑:死了可由不得我!手中长剑斜指向天,划出道道幽蓝光芒,似乎要召唤什么!\n\n"NOR, me, target); 
        msg = HIG"突然之间，$N剑拉弧形，寒光一闪，带起阵阵寒风直逼向$n的"NOR+xue_name[random(sizeof(xue_name))]+"。\n"NOR;
        me->set_temp("qxj_jianmang", 1);
        remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
        if (random(me->query_skill("force")) > random(target->query_skill("force") /4)&&
            random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){                     
                me->start_busy(1);
                target->start_busy(1); 
                msg += CYN"$n大吃一惊，变招不及，$w已在他的"NOR+xue_name[random(sizeof(xue_name))]+CYN"对穿而出，真气不由一散。\n"NOR;
                damage = (int)me->query_skill("sword", 1);       
                damage = damage + random(damage/2);
                if(damage>300) damage=300;
                if(me->query_skill("huntian-qigong",1) > target->query_skill("force",1)
                && me->query("force") > random(target->query("force"))  ) 
                               damage += random(damage)/2;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");

                msg += "( $n"+eff_status_msg(p)+" )\n";
                msg = replace_string(msg, "$w", weapon1_name[random(sizeof(weapon1_name))]);   
                message_vision(msg, me, target);
               target->set_temp("last_damage_from", me);
                me->add("force", -(int)me->query_skill("sword", 1)/2);
                remove_call_out("perform2");
                call_out("perform2", 1, me, target);  

              } 
        else {
                me->start_busy(2+random(2));
                msg += HIY"\n$n却识得那道剑光的厉害,早已远远避在一边.\n" NOR;
                message_vision(msg, me, target);
             }

        return 1;
}

int perform2(object me, object target)
{
        int damage,p;
        string msg, dodge_skill,*limbs,force_skill,force_skill_name,wep;
        if (!me) return 1;
        if(!target) return 1;
        remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
        if(!living(target)) return notify_fail("对手已经不能再战斗了。\n");
       if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){
           if(!wep)msg = HIY"$N手中武器既失，积蓄的气势随之消散，$n不禁松了口气．\n"NOR;
           else  msg = HIY"$N亮出"+wep->name()+HIY"而停止追击，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
           message_vision(msg, me, target);
           if(target->is_busy()) target->start_busy(1);
           me->start_busy(1);
           return 1;
           } 
       if (userp(me) && (me->query_skill_mapped("sword") != "qixiu-jian" || me->query_skill_mapped("parry") != "qixiu-jian")){
           message_vision(HIY"$N突然变招，剑光再闪，使出和七修剑法完全不同的招数来！\n"NOR,me);
           if(target->is_busy()) target->start_busy(1);
         me->start_busy(1);
             return 1;
              }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           if(!living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+wep->name()+HIY"一向后摆，撤回了散开的剑幕．\n"NOR;
           else msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，停止了攻击．\n"NOR;
           if(target->is_busy()) target->start_busy(1);
           message_vision(msg, me, target);
           return 1;
           }           
        if( (int)me->query("force", 1) < 1000 )
           {message_vision(HIY"$N剑招渐见涩滞，刚才一剑刺出竟然软弱无力，原来是真气不足了！\n"NOR,me);
         if(target->is_busy()) target->start_busy(1);
           me->start_busy(1);
           return 1;
          }
        force_skill = target->query_skill_mapped("force");
        if( !force_skill ) force_skill_name = "基本内功";
        else    if( force_skill=="huntian-qigong" ) force_skill_name = "混天气功";
        else    if( force_skill=="lengquan-force" ) force_skill_name = "冷泉神功";
        else    if( force_skill=="lotusforce" ) force_skill_name = "莲花心法";
        else    if( force_skill=="moonforce" ) force_skill_name = "月宫心法";
        else    if( force_skill=="ningxie-force" ) force_skill_name = "凝血神功";
        else    if( force_skill=="wuxiangforce" ) force_skill_name = "小无相功";
        else    if( force_skill=="dragonforce" ) force_skill_name = "龙神心法";
        else    if( force_skill=="tonsillit" ) force_skill_name = "摄气绝";
        else    if( force_skill=="huntian-qigong" ) force_skill_name = "镇元神功";
        else    force_skill_name = "内功";    
        msg = HIG "\n跟着，$N随式一转，剑势再变,似是千变万化，剑气万重,大地开始震动。\n"NOR;        
        if (random(me->query_skill("force")) > random(target->query_skill("force") /3)&&
            random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){            
                me->start_busy(1);
                target->start_busy(1);
                msg += CYN"只听$n一声惨嚎,剑光从"NOR+xue_name[random(sizeof(xue_name))]+CYN"掠过，$n连运"NOR+HIR+force_skill_name+NOR+CYN"，气血依然无法凝聚。\n"NOR;
                msg+=HIY"\n狂风开始怒号,天上似乎下起了些微的"+HIR+"血雨!!!\n"NOR;
                damage = (int)me->query_skill("sword", 1);       
                damage = random(damage);
                if(damage>500) damage=500;
                if(me->query_skill("huntian-qigong",1) > target->query_skill("force",1)
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
        if( (int)me->query_skill("parry", 1) > 199 &&
            (int)me->query_skill("force", 1) > 199 &&
            (int)me->query_skill("sword", 1) > 199 &&
            (int)me->query_skill("qixiu-jian", 1) > 199 &&
            (int)me->query_skill("force", 1) > 199 ) {
                remove_call_out("perform3");
                call_out("perform3", 1, me, target,force_skill_name); 
                }
        } 
        else 
        {
                me->start_busy(2+random(2));
                msg += HIY"\n$n顺势亦是一转，轻轻带过，竟然躲过这招"NOR+HIR"引出血雨的剑"NOR+HIY".\n" NOR;
                me->add("force", -(int)me->query_skill("sword", 1)/2);    
                message_vision(msg, me, target);    
        }

        return 1;
}
int perform3(object me, object target,string force_skill_name)
{
        int damage , p;
        string msg, weapon,dodge_skill,*limbs,force_skill;
        if (!me) return 1;
        if(!target) return 1;
        remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
        if(!living(target)) return notify_fail("对手已经不能再战斗了。\n");
       if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"){
           if(!weapon)msg = HIY"$N手中武器既失，圆转的三连击也随之消散，$n不禁松了口气．\n"NOR;
           else  msg = HIY"$N亮出"+weapon->name()+HIY"而停止追击，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
           message_vision(msg, me, target);
           if(target->is_busy()) target->start_busy(1);
           me->start_busy(1);
           remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
           return 1;
           } 
       if (userp(me) && (me->query_skill_mapped("sword") != "qixiu-jian" || me->query_skill_mapped("parry") != "qixiu-jian")){
           message_vision(HIY"$N突然变招，划破剑幕，使出和七修剑法完全不同的招数来！\n"NOR,me);
           if(target->is_busy()) target->start_busy(1);
         me->start_busy(1);
          remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
              return 1;
              }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           if(!living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+weapon->name()+HIY"一向后摆，撤回了散开的剑幕．\n"NOR;
           else msg = HIY"$N将手中"+weapon->name()+HIY"向后一摆，抱圆守一，停止了攻击．\n"NOR;
           if(target->is_busy()) target->start_busy(1);
           remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
           message_vision(msg, me, target);
           return 1;
           }           
        if( (int)me->query("force", 1) < 1000 ){
           message_vision(HIY"$N剑招渐见涩滞，刚才一剑刺出竟然软弱无力，原来是真气不足了！\n"NOR,me);
         if(target->is_busy()) target->start_busy(1);
           me->start_busy(1);
           remove_call_out("remove_effect");
                call_out("remove_effect", 10, me);
           return 1;
          }
        weapon = me->query_temp("weapon");  
        msg = HIW "\n突然,$N手中的"+ weapon->query("name")+ HIW"在吸了血后不听使唤，化做一条血龙，腾空而起.\n"NOR;  
        msg+=HIR"\n天地为之动容,风云为之变色,恐怖的死神重又降临人世,世界成了炼狱.\n"NOR; 
            if (random(me->query_skill("force")) > random(target->query_skill("force") /2)&&
            random(me->query("combat_exp")) > random(target->query("combat_exp") /3) ){   
                me->start_busy(1+random(2));
                target->start_busy(1+random(3));
                msg += weapon3_name[random(sizeof(weapon3_name))]+WHT"刺穿$n的"NOR+HIR+force_skill_name+NOR+WHT",喀嚓一声$n的"NOR+HIM"手臂"NOR+WHT"已然绞断，"NOR+xue_name[random(sizeof(xue_name))]+WHT"被对穿而出。\n"NOR;
                damage = (int)me->query_skill("sword", 1);       
                damage = damage + random(damage*2);
                if(damage>1000) damage=1000;
                if(me->query_skill("huntian-qigong",1) > target->query_skill("huntian-qigong",1)
                && me->query("force") > random(target->query("force"))  ) 
                damage = damage + random(damage*3/2);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
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
                me->start_busy(2+random(3));
                target->start_busy(1);
                msg += HIY"\n$n却识得那条血龙的厉害,闪身躲过,却也惊出一身冷汗。\n" NOR;
                me->add("force", -(int)me->query_skill("sword", 1)/2);
        }
       message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("qxj_jianmang");
        tell_object(me, GRN"\n你经过一段时间调气养息，又可以使用"NOR+HIR"血魔死神"NOR+"了。\n"NOR); 
}


