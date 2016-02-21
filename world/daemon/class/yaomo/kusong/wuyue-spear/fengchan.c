// /daemon/class/yaomo/kusong/wuyue-spear/fengchan  五岳封禅
// writted by jie 2001-2-8
// 连击技 五岳封禅取义上古人帝对五岳封禅
// 最厉害连续发5招：正气岱宗 平冲中庸 文章衡峰 忠勇西岳 恒岭儒雅
// 与l=(int)me->query_skill("literate",1)有关
// 基本开始连续发3招 正气岱宗 忠勇西岳 恒岭儒雅
// 不可能发出的必杀技 五岳归来不看山
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	object weapon;
	int myskill, k, l;
	int ap, ap2, dp, dp2, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［五岳封禅］只能对战斗中的对手使用。\n");
	    if(me->query("family/family_name")!="火云洞")
           return notify_fail("“五岳封禅”只有火云洞门人才可以用！\n");

	myskill=(int)me->query_skill("wuyue-spear",1);
	if(myskill<100) 
		return notify_fail("你的［五岳神枪］还不够纯熟！\n");
	myskill=(int)me->query_skill("pingtian-dafa",1);
	
        if( time()-(int)me->query_temp("fengchan_end") < 8 )
                return notify_fail("绝招用多就不灵了！\n");
	
	if(myskill<100) 
		return notify_fail("你的平天大法等级不够，不能使用这一招！\n");
	
	k=(int)me->query_skill("spear");
        if(k<140)        
                return notify_fail("你的枪法级别还不够，使用这一招会有困难！\n");
        l=(int)me->query_skill("literate",1);        		
	if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内功太差。\n");
	
	if((int)me->query("force")<500) 
		return notify_fail("你的内力不够了。\n");

	me->set_temp("fengchan_end",time());
	
	msg = HIC "$N神功妙悟，"+ weapon->query("name")+ HIC"砸出一式\n\n";
	msg +=HIC "┏━━━━┓\n";
	msg +=HIC "┃正气岱宗┃\n";
	msg +=HIC "┗━━━━┛\n一股浩然正气已笼罩$n全身！\n";
	mycor=me->query_cor();
	youcps=target->query_cps();
	ob=target->query_temp("weapon");
	str="右臂";
	if(objectp(ob)) str="手中的"+ob->query("name");
	ap = k;
	ap = (ap /12) * ap * ap;
	ap += (int)me->query("combat_exp");
	dp = target->query("combat_exp");
	ap2=COMBAT_D->skill_power(me, "spear", SKILL_USAGE_ATTACK);
	dp2=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp2/=2;	
	pp=COMBAT_D->skill_power(target,"parry", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=target->query_str();
	damage_bonus = k;
	damage_bonus=mystr*(damage_bonus+100+me->query("force_factor"))/100;

	if( random(youcps) < 15 || random(ap+dp+ap2+dp2)>(dp+dp2)) {
		msg += "$n举起"+str+HIC"一架，不料枪风正气凛冽，微一迟疑。\n";
		msg += "$N枪势斗转，"+ weapon->query("name")+ HIC"发出摄人心魄的呼啸向$n刺去！\n\n" NOR;
		msg += HIB "瞬间锋锐的枪尖已到了$n的咽喉，\n";
		if(random(ap2+pp)>pp) {
			msg +=HIB "   ┏━━━━┓\n";
			msg +=HIB "   ┃忠勇西岳┃\n";
			msg +=HIB "   ┗━━━━┛\n这式犹如华山一条道直取$n要害！\n";
			damage=calculate_damage(me, target, 10, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound/2, me);
				msg+=HIB"结果$n咽喉一麻，差点喘不过气来。\n" NOR;
			}
		}
		else msg+="结果被$n灵巧挡开了。\n" NOR;
		msg += HIW "\n紧跟着$N到转"+ weapon->query("name")+ HIW"尾刺向$n的大腿，\n";
		msg += "同时长啸高吟“恒溪风流禅月明”——";
		if(random(ap2+pp)>pp) {
			msg += "$n紧闭双眼，胡乱拆招。\n" NOR;
			damage=calculate_damage(me, target, 40, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound/2, me);
				msg +=HIW "      ┏━━━━┓\n";
				msg +=HIW "      ┃恒岭儒雅┃\n";
				msg +=HIW "      ┗━━━━┛\n";
				msg +=HIW"这式俊秀倜傥，结果$n的腿部被划开深深的一道口子。\n" NOR;
			}
		}
		else msg+="$n看准来势，挫身闪开了。\n" NOR;
		msg += HIM "\n$N接着顺势连人带"+ weapon->query("name")+ HIM"撞向$n，仿佛如椽巨笔饱墨临纸，";
		if(random(ap2+pp)>pp && k>170 && l>100) {
                        msg += "令$n肝胆俱裂！\n" NOR;
                        msg +=HIM "         ┏━━━━┓\n";
			msg +=HIM "         ┃文章衡峰┃\n";
			msg +=HIM "         ┗━━━━┛\n";
			msg +=HIM"这式深得“如椽健笔意纵横”的神髓！\n" NOR;
                        damage=calculate_damage(me, target, 60, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound/2, me);
                                msg+=HIM"结果$n神智迷糊，差点晕倒。\n" NOR;
                        }
                }
                else msg+="结果$n一个踉跄，却没摔倒。\n" NOR;
                if(random(ap2+pp)>pp && k>240 && l>140) {
                	msg += HIY "\n$N枪意绵绵，"+ weapon->query("name")+ HIY"平平正正，直取中路刺向$n，";
                        msg += "$n不晓这招厉害，居然不知如何应付！\n" NOR;
                        msg +=HIY "            ┏━━━━┓\n";
			msg +=HIY "            ┃平冲中庸┃\n";
			msg +=HIY "            ┗━━━━┛\n";
			msg +=HIY"这式登堂入室，把基本枪法的“中平”一式发挥到妙到毫巅！\n" NOR;
                        damage=calculate_damage(me, target, 80, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound/2, me);
                                msg+=HIR"结果“噗！”的一声，$n胸口被搠出个大窟窿！\n" NOR;
                        }
                }
                message_vision(msg, me, target);
// 此招一出，必死
// ap2+pp>pp
// 有效等级大于300，读书识字大于180
// 300随机值大于297
// 随机福缘大于25
// 同时满足，概率极其微小
                if(random(ap2+pp)>pp && k>300 && l>180 && random(300)>297 && random(me->query("kar"))>25) {
                	
                	msg = HIG "\n$N脸上露出恐惧之色，"+ weapon->query("name")+ HIG"竟然不听使唤，";
                        msg += "犹如妖魔控制一般，\n在枪意已尽，劲势已灭之际，又生新力，又续杀机，死神般活跃！\n" NOR;
                        msg +=HIG "┏━━━━━━━┓\n";
			msg +=HIG "┃五岳归来不看山┃\n";
			msg +=HIG "┗━━━━━━━┛\n";
			msg +=HIG"这式受天上地下十万神魔诅咒过的一招，真是鬼泣神啼，天地顿时失色！\n" NOR;
			me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(2)+4);
			message_vision(msg, me, target);
                        
                
	}	
		msg+=COMBAT_D->report_status(target, "刺伤");
	} else {
		msg += "可是$p看破了$P的企图，向后越开。\n" NOR;
		message_vision(msg, me, target);
	}
    delay = random(2)+1;
	me->start_busy(delay);
	me->add("force", -300);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

	return damage;
}

void kill_him(object me, object target)
{
	string msg;
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target))
	{
		msg =HIR"\n$n只觉得眼前一花，咽喉已被对穿而过！！！\n\n一股血箭喷涌而出．．$n的眼睛死鱼般的突了出来．．\n" NOR;
                target->receive_damage("sen",target->query("max_sen")+1,me);
                target->receive_wound("sen", (int)target->query("max_sen")+1, me);
                target->receive_damage("kee",target->query("max_kee")+1,me);
                target->receive_wound("kee", (int)target->query("max_kee")+1, me);
                msg+=HIR"\n$N看着$n的尸体，冷汗直冒．．\n" NOR;
                COMBAT_D->report_status(target);
  			
		message_vision(msg, me, target);
		target->heart_beat();
	}
	return ;
}
