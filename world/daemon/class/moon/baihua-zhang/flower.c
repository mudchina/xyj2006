//天女散花 
// lestat 2001


#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg,str;

        int damage, ap, dp, s_num, chance;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天女散花」？\n");
		if(me->query("family/family_name") != "月宫")
                return notify_fail("[天女散花]是月宫不传之密！\n");

        if((int)me->query("force") < 25+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 500 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        if((int)me->query_skill("baihua-zhang", 1) <80)
                return notify_fail("你的百花掌级别还不够！\n");
        if( time()-(int)me->query_temp("xiao_end") < 4 )
          return notify_fail("绝招用多就不灵了！\n");
        me->add("force", -125-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        msg = MAG
"\n$N微微一笑，身子凌空而起，洒下漫天花雨，一时花香缭绕\n"+
"$n只觉周身都被花影罩住了，一时竟然不知如何招架，更不用说躲闪了！\n\n" NOR;
   s_num = (int)(random(me->query_skill("unarmed")/10)) + (int)(me->query_skill("baihua-zhang")/10)+ 1;
   ap = me->query_skill("unarmed");
   ap =  ap * ap * ap / 100;
   dp = target->query("combat_exp")* 4 /5;
   if (dp < 100000) {
   	chance = 100;
   	       }
   else {
   chance = (int)(random(ap + dp) * 100 / dp);
   }
   if( chance > 66 ) 
   {
        damage = s_num * 10 ;
        damage +=(int)me->query("force_factor")-random((int)target->query("force_factor"));
if ( damage > 800 ) damage=800;
        msg += HIM "这些花瓣看似柔弱无力，却如疾风骤雨般射向$n,"+HIW+chinese_number(s_num)+HIM"片花瓣深深的嵌入$n肉里！\n\n" NOR;
        target->receive_wound("kee", damage);
        me->improve_skill("unarmed", s_num, 1);
     }
     else if ( chance > 33 ) 
     {
        damage = s_num * 8 ;        
if ( damage > 800 ) damage=800;
        msg += HIC "这些花瓣看似柔弱无力，却如疾风骤雨般射向$n,$n躲闪不及被"+HIW+chinese_number(s_num)+HIM"片花瓣擦伤！！\n\n" NOR;
        target->receive_wound("kee", damage);
        me->improve_skill("unarmed", s_num, 1);
     } 
   else
     msg += "谁知$n竟险中求胜，长袖一摆，已将所有花瓣打落！\n";

   message_vision(msg, me, target);
   if( damage > 0 ) COMBAT_D->report_status(target);
   else if( damage < 0 ) COMBAT_D->report_status(me);
       if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"被"+me->name()+"用广寒宫秘传"NOR+HIC"「天女散花」"+HIM"打死了，据说尸体上竟然嵌入无数花瓣！";
	                 message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	               }
    me->set_temp("xiao_end",time());
    return 1;
}
