#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        
	object *inv, obj, obj1;
   int damage,jiali;
	int i, mypot,tapot;
	string str;

        object weapon;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「灵犀指」？\n");

        if(!me->is_fighting())
                return notify_fail("「灵犀指」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");
      if(me->query("family/family_name") != "南海普陀山" )
                return notify_fail("你是哪儿偷学来的武功！\n");

        if((int)me->query("force") < 600 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

	i=(int)me->query_skill("jienan-zhi",1);

        if( i < 150)
                return notify_fail("你的劫难指级别还不够，使用这一招会有困难！\n");
jiali = me->query("force_factor")+1;
damage = me->query_skill("jienan-zhi", 1)/40 * jiali;
if(damage > 500) damage = 500;

        if( time()-(int)me->query_temp("lingxi_end") < 10 )
                return notify_fail("你现在内息不顺！\n");
	message_vision(HIY"\n$N心悟佛法，灵犀所至，缓缓伸出右手食指向$n凌空一点，一股阳和的气流向$n直逼过去。\n\n"NOR,me,target);
        	
	mypot=(int)me->query_skill("unarmed");
	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
	tapot=tapot+(int)target->query_skill("dodge")/10;
	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/2 || !living(target) ) 
{       
	
	 message_vision(HIR"只听见「嗤」的一声轻响，$N右手食指已经在$n身上戳出一个血窟窿。\n\n"NOR,me, target);	
//         COMBAT_D->do_attack_damage(me, target);
//         target->receive_wound("kee",random(me->query_skill("unarmed")));
         target->receive_wound("kee",damage);
         target->receive_wound("sen",damage);
	 COMBAT_D->report_status(target);
		
	 if (target->query("eff_kee")<0 || !living(target))  
         {str=target->name()+HIM"被"+me->name()+"的"+NOR+HIY"灵犀指力"+NOR+HIM"打中死穴，登时七孔流血而死。";
    message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
//         me->delete_temp("last_channel_msg");
}
        else {if ( random(3)>1 )
              message_vision(HIY"$N的指力正正打在$n的穴道上，$n登时浑身酸麻动弹不得。\n"NOR,me,target);
              target->start_busy(4+random(3));
             }
          
}	 
     
	 else  {message_vision(HIC"$N识得厉害，连忙使一个鹞子翻身躲开了！\n"NOR, target);
	        me->start_busy(2);
	       }
	       
        me->add("force", -50);
	me->receive_damage("sen", 50);
	me->set_temp("lingxi_end",time());
        return 1;
}




