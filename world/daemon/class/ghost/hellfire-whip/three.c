//edit by yesi
//lestat modi for hell
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
  object weapon;
  int damage,enhance;   
  string msg,str;        
  if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「神·人·鬼」？\n");
        if(me->query("family/family_name") != "阎罗地府")
                return notify_fail(HIG"「神·人·鬼」"+NOR"是冥界不传之密！\n");
        if(!me->is_fighting())
                return notify_fail("「神·人·鬼」只能在战斗中使用！\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");
//        if (me->query_temp("ldlh"))
//           return notify_fail("你正在施用布六道轮回迷阵，没有余力出「神·人·鬼」！\n");
        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        if( time()-(int)me->query_temp("three_end") < 5 )
          return notify_fail("绝招用多就不灵了！\n");
        if((int)me->query_skill("kusang-bang", 1) < 150)
                return notify_fail("你的苦丧棒级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("hellfire-whip", 1) < 150)
                return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("jinghun-zhang", 1) < 150)
                return notify_fail("你的惊魂掌级别还不够，使用这一招会有困难！\n");
        if (me->query_skill_mapped("unarmed")!="jinghun-zhang")
                return notify_fail("「神·人·鬼」必须配合惊魂掌才能使用。\n");
        if (me->query_skill_mapped("stick")!="kusang-bang")
                return notify_fail("「神·人·鬼」必须配合苦丧棒才能使用。\n");              

    weapon=me->query_temp("weapon");
//    target->start_busy(1);//定住对手防止丢失同时起到增加命中的作用.
    message_vision(HIW"\n$N双手划一大圆，猛然托天而举，伴着天上雷鸣电闪，祭出了「神·人·鬼」三招。\n"NOR,me,target);
//出鞭
    message_vision(HIB"\n四周磷光点点，$N舞动"+weapon->name()+NOR+HIB"，咯咯一笑，扑向$n。\n"NOR,me,target);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    seteuid(getuid());
//出掌
    me->set("actions", (: call_other, SKILL_D("jinghun-zhang"), "query_action" :) );
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("jinghun-zhang",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("tonsillit",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);    
    message_vision(HIB"\n但见幢幢鬼影四周飘浮，突然$N鬼唱一声，无数鬼手抓向$n。\n"NOR, me,target);    
    COMBAT_D->do_attack(me, target);
    me->add_temp("apply/attack",-enhance);
//出棍
    message_vision(HIB"\n$N双手一抖，手中"+weapon->name()+NOR+HIB"顿时变的笔直，如同一根铁棍。\n"NOR,me);
    seteuid(getuid());
    me->set("actions", (: call_other, SKILL_D("kusang-bang"), "query_action" :) );
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","stick");
    enhance=me->query_skill("kusang-bang",1);
    me->add_temp("apply/attack", enhance);  
    COMBAT_D->do_attack(me, target,weapon);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    me->reset_action();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
       {str=target->name()+HIM"被"+me->name()+"用幽冥绝学"NOR+HIB"「神·人·鬼」"+HIM"打死了，尸体面色狰狞可怖，似被恶鬼缠身！";
         message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	}
    me->add("force", -100);
/*        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }*/
  me->set_temp("three_end",time());
  return 1;
}

