#include <ansi.h>
#include <condition.h>
#include "/daemon/skill/eff_msg.h";
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

      int damage, p;
      string msg;
      
      damage = me->query_condition("dashouyin")/5 +2;
      damage *= me->query_con();
      
      tell_object(me, "突然你感觉胸口疼痛异常，刚才被如来神掌拍中的肋骨处好象要裂开了似的，鲜血也从口中喷了出来！\n");
      tell_room(environment(me), HIR + me->name()+"突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,({ me }));
      me->receive_damage("kee", damage/2);
      me->receive_wound("kee", damage/2);
      p = (int)me->query("kee")*100/(int)me->query("max_kee");
      msg = "( $N"+eff_status_msg(p)+" )\n";
      if(living(me)) 
             message_vision(msg, me);
 //     me->set_temp("last_damage_from", "如来神掌劲力发作");
	  me->set_temp("death_msg","寒毒发作死了。\n");
      me->apply_condition("dashouyin", duration - 1);
	  if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}

