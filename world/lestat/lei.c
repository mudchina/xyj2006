//jinglei-mace perform lei 雷殛怒火
// /daemon/class/fighter/jinglei-mace/lei
// writted by jie 2001-2-10
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("mace",1);
        myskill1= (int)me->query_skill("jinglei-mace",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="mace")
        return notify_fail("不拿锏怎使惊雷鞭法？");
        if ( myskill1 < 80) return notify_fail("你的惊雷鞭法还不够火候！\n");
        if(me->query("family/family_name") != "将军府" )
                return notify_fail("你是哪儿偷学来的武功，也想用『雷殛怒火』?\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『雷殛怒火』只能在战斗中使用。\n");
        if ((int)me->query("force")<300)
                return notify_fail("你的内力不够。\n");
		if( time()-(int)me->query_temp("lei_end") < 10 )
                return notify_fail("绝招用多就不灵了！\n");                       
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
     message_vision(HIC"$N招式一缓，手中"+weapon->name()+HIC"仿佛挽了千斤似的，使出了惊雷鞭法的绝学--『雷殛怒火』！\n\n" NOR,me,target);        
     message_vision(CYN"$N气运丹田，平平砸出一锏，慢，却嘶嘶作风雷之声。\n"NOR,me);
     message_vision(CYN"这一招『雷霆薄击』挟着内力，却象密云乍现，惊雷含劲欲发！\n\n"NOR,me);
     if (random(myexp)>(int)(texp/10) && random(myforce) > (int)(tforce/3)) 
        {
             msg = HIC"$n只觉得一股劲气象闪电一般，穿体而过！\n"
                                "“哇”的一声，$n喷出一大口鲜血，看来是受了内伤！\n\n"NOR;
//	damage= ((int)me->query("max_force")/2+random((int)(myskill1/2));
	damage=(int)(random((int)(myskill1/2))+me->query("max_force")*3/2);
 	if(damage<1)damage = 1;
// 	target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
// 	target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
	target->receive_damage("kee", damage/20, me);
 	target->receive_wound("kee", damage/10, me);
     	message_vision(msg, me, target);
     	COMBAT_D->report_status(target);
     	}
     else {
            msg = HIC"$n忙运功向抗，深厚的内力将$N的攻势都激散了。\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(CYN"$N由静转动，一动便急如风，脚踏奇门，锏走奇招，锏锏从$n意想不到的方位无声无息地砸出！\n" NOR,me,target);
     message_vision(CYN"这一招『天雷荡邪』好似天公作怒，要把天下妖孽尽数劈死，使得个痛快淋漓\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIC"$n马上手忙脚乱，不知该如何去招架这静若水、快如电的锏法！\n"
        "果不然，$N的"+weapon->name()+HIC"招招命中，$n浑身上下被砸的遍体鳞伤！\n\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
//     target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
//     target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
	 target->receive_damage("kee", damage, me);
	 target->receive_wound("kee", damage, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$n却心静如水，丝毫不显慌乱，见招拆招，瓦解了$N这无声的攻势。\n\n"NOR;
            message_vision(msg, me, target);
        }


          message_vision(CYN"$N突然收住身形，回步而立，撤锏于背后，无招胜有招，无形胜有形。\n"NOR,me);
          message_vision(CYN"这一招『雷殛怒火』把惊雷鞭法的精髓要旨发挥地酣畅爽快！\n\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIC"$n果然上当，以为$N露出破绽，大喜之下，急忙上前想抢攻。\n"
"$N微微一笑，待$n靠近，长袖一抖，袖尽锏出，直探$n的胸口。\n"
"$n连锏影还没看到，就差点儿被穿的透心凉！\n\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
//target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
//target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
target->receive_damage("kee", damage, me);
target->receive_wound("sen", damage, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIC"$n看破了这招的虚实，将计就计，假装冲上前，却在$N出锏的一瞬间腾空跃开，回手竟反攻一招！\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(2);
        me->set_temp("lei_end",time());
     
        return 1;
}









