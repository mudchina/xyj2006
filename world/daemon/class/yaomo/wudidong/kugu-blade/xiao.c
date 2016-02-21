//刀剑笑
//lestat for 枯骨刀 perform
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;
      string msg,str; 
      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if(me->query("family/family_name")!="陷空山无底洞")
          return notify_fail("“刀剑笑”只有无底洞门人才可以用！\n");
      if ( me->query_skill("moonforce",1)     
		|| me->query_skill("ningxie-force",1)
		|| me->query_skill("lengquan-force",1)
		|| me->query_skill("zixia-shengong",1)
		|| me->query_skill("zhenyuan-force",1)
		|| me->query_skill("tonsillit",1)
		|| me->query_skill("dragonforce",1)
		|| me->query_skill("huomoforce",1)
		|| me->query_skill("wuxiangforce",1)
		|| me->query_skill("lotusforce",1)
		|| me->query_skill("xuanzong-force",1)
		|| me->query_skill("butian-force",1)
		|| me->query_skill("jiuyin-xinjing",1))
          return notify_fail("你不先散了别派内功，怎能学刀剑笑？！\n");
      if( time()-(int)me->query_temp("xiao_end") < 5 )
          return notify_fail("绝招用多就不灵了！\n");
      if (!target->is_fighting(me))
          return notify_fail("你们没有在打架！\n");
      if (target->is_busy())
          return notify_fail("对方早就手忙脚乱了，放胆攻击吧！\n");
      if (me->query_skill("huntian-qigong",1)<100)
          return notify_fail("你的内功太差，还不会以剑法御刀。\n");
      if (me->query_skill("kugu-blade",1)<100) 
          return notify_fail("你还是先把精力集中在枯骨刀法上吧。\n");
      if (me->query_skill("yinfeng-zhua",1)<100) 
          return notify_fail("你的阴风爪太差，强运神功不是笑死人了。\n");
      if (me->query_skill("qixiu-jian",1)<100)
         return notify_fail("你的七修剑法那么烂，还好意思夹在刀法中现眼？\n");
      if (me->query_skill_mapped("force")!="huntian-qigong")
            return notify_fail("刀剑笑必须配合混天气功才能使用。\n");
      if (me->query_skill_mapped("unarmed")!="yinfeng-zhua")
            return notify_fail("刀剑笑必须配合阴风爪才能发挥威力。\n");
      if (me->query_skill_mapped("sword")!="qixiu-jian")
            return notify_fail("刀剑笑必须配合七修剑才能发挥威力。\n");
      if (me->query("force")<800)
           return notify_fail("你内力不继，难以出招。\n");

    me->add("force", -100);
    seteuid(getuid());
////出剑
//   target->start_busy(1);//定住对手防止丢失同时起到增加命中的作用.
    me->set("actions", (: call_other, SKILL_D("qixiu-jian"), "query_action" :) );   
    message_vision(HIB"$N默运混天气功，突然间使出七修剑法，手中"+weapon->name()+HIB"直取$n！\n"NOR,me,target);
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","sword");
    enhance=me->query_skill("qixiu-jian",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("kugu-blade",1);
    damage=(damage+random(damage))/5;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target, weapon);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
////出掌
    me->set("actions", (: call_other, SKILL_D("yinfeng-zhua"), "query_action" :) );   
    message_vision(HIC"\n$N不等招式用老，诡异一笑，立刻收刀出爪，一股阴风直扑$n！\n"NOR,me,target);
    //weapon->unequip();
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("yinfeng-zhua",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("huntian-qigong",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    //weapon->wield();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"被"+me->name()+"用陷空山绝学"NOR+HIC"「刀剑笑」"+HIM"打死了，据说"+target->name()+"到死脸上还挂着微笑！";
	                 message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	               }
    me->reset_action();
    me->set_temp("xiao_end",time());
//    me->start_busy(random(2)+1);
    return 1;
}

