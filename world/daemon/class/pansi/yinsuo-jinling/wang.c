// chan.c 银索金铃「天罗地网」

#include <ansi.h>
inherit SSERVER;
int checking(object me, object target, object weapon);

string *number_msg = ({"一","二","三","四","五","六","七","八","九","十","十数","千百","无数"});
string *whip_msg = ({"反撩","斜刺","轻挥","轻抖","漫舞","直劈","后拉","前推"});

string *chan_msg = ({
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，其千变万化，无穷无尽，要去包裹缠住$n！\n" NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，前后排列，要将$n包裹起来！\n" NOR,
CYN"$N心中不存半点渣滓，以意御鞭，$W"CYN"每发一招，便似放出一条"RED"细丝"CYN"，要去缠住$n！\n"NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，正反相交，要将$n缠在正中！\n" NOR,
CYN"$N手中$W"CYN"挥动，驱银索金铃散发出根根"RED"细丝"CYN"，要将$n裹起来！\n"NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，上下包容，要将$n包裹起来！\n" NOR,
CYN"$N的一柄$W"CYN"舞着一个个"RED"圆圈"CYN"，每一招均是以弧形刺出，以弧形收回，缠住$n！\n"NOR,
CYN"$N以意御鞭，$S舞出$R个"RED"圆圈"CYN"，左右兼顾，要将$n缠在正中！\n" NOR,
});

string *dodged = ({
HIY"可是$n已然看穿了$P的招数，孤注一掷直入圈心，破了$N的绵绵鞭意！\n\n" NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力中宫疾进，从银丝圈中冲了出去！\n\n"NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力飞跃后退，远离了鞭网！\n\n"NOR,
HIY"$n看得真切，回招挡格了$N中宫一剑，接着纵身一跃，已逃出圈外。\n\n"NOR,
});

string *chaned = ({
HIW"结果$n的招数渐见涩滞，偶尔发出一招，真气运得不足，便被$W"HIW"带着连转几个圈子。\n"NOR,
HIW"结果银索金铃散发出的细丝越积越多，似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"结果，银索金铃似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"$n越斗越是害怕，一个疏忽，被银索金铃紧紧裹了起来！\n"NOR,
});

int perform(object me, object target)
{
//		string msg;
        object weapon = me->query_temp("weapon");
        int cost = me->query_skill("yinsuo-jinling", 1)/2;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if(!living(target))
                return notify_fail("这人本来就不能动,还布的什么天罗地网？\n");
        if(!weapon || weapon->query("skill_type") != "whip" )
                return notify_fail("你手中无鞭，如何使得「天罗地网」？\n");
		if(me->query("family/family_name")!="盘丝洞")
return notify_fail("“天罗地网”只有盘丝洞门人才可以用！\n");
        if(me->query_temp("YSJL/chan"))
                return notify_fail("你正在使用「天罗地网」。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        if( (int)me->query_skill("yinsuo-jinling", 1) < 100 )
                return notify_fail("你的银索金铃极不够娴熟，不要丢人现眼了。\n");
        if( me->query("force") <= 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("max_force") <= 700 )
                return notify_fail("你的内力修为不够！\n");
        if(me->query_temp("combat_wield"))
                return notify_fail("你不出鞭，何以织出「天罗地网」？\n");
        if (me->query_skill_mapped("whip") != "yinsuo-jinling")
                 return notify_fail("你现在无法使用「天罗地网」。\n");
        if(userp(me)){
    
            if( (int)me->query_skill("pansi-dafa", 1) < 100 )
                return notify_fail("你的盘丝大法修为不够，不能把手中兵器化作「天罗地网」。\n");
            if( me->query_skill_mapped("force") != "jiuyin-xinjing")
                return notify_fail("你所用的内功与银索金铃意气相悖！\n");
            }
        me->add("force", -cost);
        me->add("mana", -10);

        message_vision(HIW"\n$N默运盘丝大法,但见手中一根根银丝从"+weapon->name()+HIW"慢慢飘起,在空中着一圈圈卷着，
绵绵不绝，便如撒出了一张大网，逐步向$n收紧！\n\n"NOR, me, target);
	if( ((random(me->query("combat_exp")) + (me->query("combat_exp")/2) > (int)target->query("combat_exp")*1/2 ))) {
		message_vision(HIW"$n一不留神被网个正着,脱身不的。\n"NOR,me, target);
		target->start_busy(3);
//		me->start_busy(random(2));
	} else {
		message_vision(HIY"可是$p看破了$P的企图，并没有上当。\n" NOR, me, target);
                me->start_busy(random(2));
	}
//	message_vision(msg, me, target);
//        target->start_busy(3);
//        me->start_busy(1);
        me->set_temp("YSJL/chan", 1);
        call_out("check_fight", 2, me, target, weapon);
    	me->start_perform(1, "缠");
        return 1;
}

int check_fight(object me, object target, object weapon)
{
        string msg;
        object wep;

        if (!me) return 1;
        if(!me->query_temp("YSJL/chan")) return 1;

        if(!living(me) || !target){
           me->delete_temp("YSJL/chan");
           return 1;
        }
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "whip"){
           if(!wep)msg = HIY"$N手中武器既失，圆转的绵绵银丝也随之消散，$n不禁松了口气．\n"NOR;
           else  msg = HIY"$N亮出"+wep->name()+HIY"而撤回手中兵器，$n身边密布的丝网也随之消散，压力骤然减轻！\n"NOR;
           if(target->is_busy()) target->start_busy(2);
           me->start_busy(1);
           me->delete_temp("YSJL/chan");
           message_vision(msg, me, target);
           return 1;
           } 
        if(environment(me) != environment(target)){
        	msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的"+HIW"「天罗地网」"+HIW"．\n"NOR;
                me->delete_temp("YSJL/chan");
                message_vision(msg, me, target);
                return 1;
                }
        if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
           if(!living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+wep->name()+HIY"一向后摆，撤回了散开的"+HIW"「天罗地网」"+HIW"．\n"NOR;
           else msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的"+HIW"「天罗地网」"+HIW"．\n"NOR;
           if(target->is_busy()) target->start_busy(2);
           me->delete_temp("YSJL/chan");
           message_vision(msg, me, target);
           return 1;
           }           

        if(wep != weapon){
           message_vision(HIY"$N撤后换了兵器，鞭势顿时无法圆转如意，$n身边的"+HIW"「天罗地网」"+HIY"威力骤减，使$n有了喘息之机会！\n"NOR,me, target);
           me->start_busy(1);
           if(target->is_busy() 
              && random(me->query_skill("yinsuo-jinling", 1)) < (int)target->query_skill("dodge", 1)/2){
              target->start_busy(2);
              me->delete_temp("YSJL/chan");
              return 1;
              }
           else {
		call_out("checking", 1, me, target, wep);
		me->start_perform(1, "缠");
	   }
          }
       if (userp(me) && (me->query_skill_mapped("whip") != "yinsuo-jinling" || me->query_skill_mapped("parry") != "yinsuo-jinling")){
           message_vision(HIY"$N突然变招，划破"+HIW"「天罗地网」"+HIY"，使出和银索金铃完全不同的招数来！\n"NOR,me);
           if(target->is_busy()) target->start_busy(3);
           me->start_busy(1);
           me->delete_temp("YSJL/chan");
           return 1;
           }   
       if( me->query("force") <= me->query_skill("yinsuo-jinling", 1)/2 ){
           message_vision(HIY"$N招式渐渐涩滞，偶尔一鞭舞出竟然软弱无力，原来是真气不足了！\n"NOR,me);
           if(target->is_busy()) target->start_busy(2);
           me->start_busy(1);
           me->delete_temp("YSJL/chan");
           return 1;
           }           
       if(!target->is_busy() && !me->is_busy() && random(4)==1 && living(target)){
          msg = chan_msg[random(sizeof(chan_msg))];
          msg = replace_string(msg, "$S", whip_msg[random(sizeof(whip_msg))]);
          msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
          msg = replace_string(msg, "$W", wep->name());
          message_vision(msg, me, target);
          checking(me, target, wep);
          }
       else {
	call_out("check_fight", 1, me, target, wep);
	me->start_perform(1, "缠");
       }
       return 1;
}       


int checking(object me, object target, object weapon)
{
        string msg;
        int busy_time, ap, dp, cost;
        cost = 20 * target->query_temp("YSJL/chan"+me->query("id")) + me->query_skill("yinsuo-jinling", 1)/2;
        busy_time = (int)me->query_skill("yinsuo-jinling", 1)/20;
        ap = me->query("combat_exp")/1000 * me->query_skill("yinsuo-jinling",1) * me->query_int();
        dp = target->query("combat_exp")/1000 * target->query_skill("dodge",1) * target->query_int();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("force", -cost);
        me->add("mana", -100);
        if(random(ap) > dp/2){          
          target->start_busy(3+random(busy_time));
          msg = chaned[random(sizeof(chaned))];
          msg = replace_string(msg, "$W", weapon->name());
          message_vision(msg, me, target);
          call_out("check_fight", 1, me, target, weapon);
	  me->start_perform(1, "缠");
          }
        else{
          me->start_busy(3);
          me->delete_temp("YSJL/chan");
          msg = dodged[random(sizeof(dodged))];
          msg = replace_string(msg, "$W", weapon->name());
          message_vision(msg, me, target);
          }
       return 1;
}       


