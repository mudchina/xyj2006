//

#include <ansi.h>

inherit SSERVER;
void remove_effect(object target,object me);

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong,npc_chance;
        int xk;
        object weapon=me->query_temp("weapon");
        object qingwang;


        if (!weapon || weapon->query("skill_type")!="whip")
           return notify_fail("没有鞭子，你拿什么织情网啊？\n");
        if (me->query_skill_mapped("whip")!="jueqingbian")
           return notify_fail("你没在用绝情鞭，使不出情网。\n");

        if((int)me->query_skill("spells") < 150 || 
           (int)me->query_skill("moonshentong",1) < 100 ||
           (int)me->query_skill("jueqingbian",1)<100 ||
           (int)me->query_skill("whip")<150)
                return notify_fail("你还不会用情网。。。\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想对谁使用情网？\n");  

        if(me->query_temp("qingwang"))
          return notify_fail("你已经撒出一张网了！\n");  

        if((int)me->query("mana") < 200 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -200);
        me->receive_damage("sen", 10);

        message_vision(HIB"$N催动法力，将手中"+weapon->name()+"舞成一团，化做一张大网，向$n当头罩来。\n"NOR,me,target);

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /12 ;
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");

        ap2 = (int)me->query_skill("jueqingbian",1);
        dp2 = (int)target->query_skill("dodge",1);
        ap3 = (int)me->query("mana");
        dp3 = (int)target->query("mana");
        ap = ap + 2000*ap2+200*ap3;
        dp = dp+2000*dp2+200*dp3;

        xk=SPELL_D->check_xiangke(me, target);

	    if( random(ap+dp)<dp) success = 0;

		if(success == 1 ){
		message_vision(HIB"$N脑子里一片混乱，鬼使神差般突然发呆，甚至忘记了躲闪，被情网当头罩住。\n"NOR,target);
		howlong = random(me->query_skill("jueqingbian",1)+me->query_skill("moonshentong",1))/10+15;
		if(howlong>60) howlong=60;

      seteuid(getuid());
      qingwang=new("/d/obj/fabao/qingwang");
      qingwang->set("target",target);
      qingwang->set("owner",me);
      qingwang->set("weapon",weapon);
      me->set_temp("qingwang",qingwang);
      qingwang->set("time_expired",time()+howlong);
      if (!qingwang->move(environment(target))) {
         message_vision(HIY"$N身上发出一道护体金光，将情网击的粉碎。\n"NOR,target);
         destruct(qingwang);
      }
      if ((!userp(target)) && npc_chance=target->query("chat_chance_combat")) {
            target->set_temp("chat_chance_combat",npc_chance);
            target->delete("chat_chance_combat");
            call_out("remove_effect",howlong,target,me);
      }
    } else {
        message_vision(HIG"$N神智清醒，不为情所困，轻轻向旁一跃，躲过了情网的袭击。\n"NOR,target);
        me->start_busy(random(2));
        if( living(target) ) target->kill_ob(me);
        } 

    return 3+random(5);
}
	void remove_effect(object target,object me) {
   if (me->query_temp("qingwang")) destruct(me->query_temp("qingwang"));
	if (!target) return;
target->set("chat_chance_combat",target->query_temp("chat_chance_combat"));
}

