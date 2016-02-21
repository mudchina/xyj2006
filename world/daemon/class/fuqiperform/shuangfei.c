#include <ansi.h>
inherit F_DBASE;
inherit SSERVER;
int perform(object me, object target)
{
 object weapon, victim = offensive_target(me);
 string msg;
        int ap,ap2,dp,damage;
object weapon2;

        if (!me->query("married"))
            return 0;
 if (!victim) return notify_fail("你想对谁进行「比翼双飞」？\n");
 if( !target )
  return notify_fail("你想与谁进行「比翼双飞」？\n");
 if( target->query("id") == me->query("id") )
  return notify_fail("你想与自己进行「比翼双飞」？\n");
 if( victim->query("id") == target->query("id") )
  return notify_fail("不能与你的对手进行「比翼双飞」。\n");

if( me->query("gender") != "男性" )
 {
  msg = "丈夫";
  //如果不是自己的丈夫的话
  if( target->query("name") != me->query("husband/name")&& target->query("id") != me->query("couple/id") )
         return notify_fail("你只能与丈夫进行「比翼双飞」。\n");
 }
 else
 {
  msg = "妻子";
  //如果不是自己的丈夫的话
  if( target->query("name") != me->query("wife/name")&& target->query("id") != me->query("couple/id") )
         return notify_fail("你只能与妻子进行「比翼双飞」。\n");
 }
 if( !victim->is_character() || !me->is_fighting(victim) )
  return notify_fail("只能对你正在战斗中的对手使用「比翼双飞」。\n");
 if( !target->is_fighting(victim) )
  return notify_fail("你的"+msg+"不在与对手战斗中。\n");

if( !objectp(weapon = me->query_temp("weapon")) ||!objectp(weapon2 = target->query_temp("weapon")) )
            return notify_fail("你们空手怎么「比翼双飞」啊？\n");
 if( (int)target->query_temp("xingyue") )
  return notify_fail("你的搭档已经在使用「比翼双飞」了。\n");
 if( (int)me->query_temp("xingyue") )
  return notify_fail("你已经在使用「比翼双飞」了。\n");
 if((int)me->query("force") < 25+(int)me->query("force_factor") )
  return notify_fail("你的内力不够！\n");
 if((int)me->query("kee") < 100 )
  return notify_fail("你的气血不足，没法子施用外功！\n");
if((int)target->query("force") < 25+(int)target->query("force_factor") )
return notify_fail("你的"+msg+"内力不够！\n");
 if((int)target->query("kee") < 100 )
  return notify_fail("你的"+msg+"气血不足，没法子施用外功！\n");
 if( !(int)target->query_temp("xingyue_request") ) {
me->set_temp("xingyue_request", 1);
  tell_object(target, me->query("name")+"向你发出「比翼双飞」请求。\n");
tell_object(me,"你向"+target->query("name")+"发出「比翼双飞」请求。\n");
  return 1;
 }
 target->delete_temp("xingyue_request");
 me->add("force", -25-(int)me->query("force_factor"));
 target->add("force", -25-(int)me->query("force_factor"));
 me->receive_damage("kee", 100);
 target->receive_damage("kee", 100);
msg = HIY "$N与$n相对一笑，万般柔情尽在心头。二人心意相通，$N双足轻点，\n如
彩蝶般飞上$n肩头，二人兵器遥指"+ victim->query("name") + "，"+victim->query("name") +"感到眼前光影闪烁，\n
什么都看不清！$N和$n同时轻喝，身形向敌人投去，如一对蝴蝶般翩翩起舞。\n" NOR;
 if(me->query("gender") == "女性")
{
msg = replace_string(msg,"$N",me->query("name"));
msg = replace_string(msg,"$n",target->query("name"));
}
        else
{
msg = replace_string(msg,"$n",me->query("name"));
msg = replace_string(msg,"$N",target->query("name"));
}
tell_room(environment(me),msg);
ap = me->query_skill(weapon->query("skill_type"));
ap2 = target->query_skill(weapon2->query("skill_type"));
ap=ap*ap*ap/1000*me->query("kee");
ap += (int)me->query("combat_exp");
ap2 = ap2*ap2*ap2/1000*target->query("kee");
ap2 += (int)target->query("combat_exp");
ap = ap+ap2;
dp = victim->query("combat_exp");
        if( random(ap + dp) > dp ) {
damage=(int)me->query("max_force")/10+random((int)me->query("eff_kee")/5);
damage+=(int)target->query("max_force")/10+random((int)target->query("eff_kee")/5);
damage-=(int)victim->query("max_force")/10+random((int)victim->query("eff_kee")/5);
damage-=random((int)victim->query("force_factor"));
damage+=(int)me->query("force_factor")+(int)target->query("force_factor");
//here we can see if 2 players are at same status, the attacker has higher chance.
msg = "";
                if( damage > 0 ) {
msg += HIC "结果"+victim->query("name")+"没有躲开，被$N和$n透体而过！\n" NOR;
                        victim->receive_damage("kee", damage, me);
victim->receive_wound("kee", damage/3, me);
                }
     else {
msg += HIC "结果"+victim->query("name")+"看穿了这招，脚步一滑，$N和$n反而自己
撞在一起！\n" NOR;
          me->receive_damage("kee", me->query("kee")/4, victim);
me->receive_wound("kee",me->query("max_kee")/4, victim);
                        target->receive_damage("kee", target->query("kee")/4, victim);
target->receive_wound("kee", target->query("max_kee")/4, victim);

     }
             }
 else
msg = "但是被"+victim->query("name")+"躲开了。\n";
msg =  replace_string(msg,"$N",me->query("name"));
msg = replace_string(msg,"$n",target->query("name")); 
tell_room(environment(me),msg);
        me->start_busy(2);
        target->start_busy(random(5));
 return 1;
}

