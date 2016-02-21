// perform.c
#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object weapon, target;
        mapping smap, pmap, prepare;
        string martial, skill, perf;
string action,file,target_ob;
        seteuid(getuid());
        smap = me->query_skill_map();
        pmap = me->query_skill_prepare();
        if( me->is_busy() )
                return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

        if( !arg ) return notify_fail("你要用外功做什么？\n");
        if ( !wizardp(me) && environment(me)->query("no_fight")) 
                return notify_fail("这里不能施用外功。\n");
	//if( me->query("anger")< 30 )
//		return notify_fail("你怒气不足以使出特殊攻击!\n");
        if( sscanf(arg, "%s on %s", perf, arg)==2 ) {
                target = present(arg, environment(me));
                if( !target ) target = present(arg, me);
                if( !target ) return notify_fail("这里没有 " + arg + "。\n");

                if(!valid_kill(me,target)) return 0;

                if( userp(me) && userp(target) && 
                    target->query_temp("netdead") )
                   return notify_fail("对方正在断线中，不能对其施用外功。\n");

                arg=perf+" "+arg;
        } else if(sscanf(arg, "%s %s", perf, arg)==2 ) {
          //so can't use: perform vision id
          //but have to use: perform vision on id
          arg=perf;
        }
        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else if( weapon = me->query_temp("secondary_weapon") )
                       martial = weapon->query("skill_type");
                else if ( sizeof(pmap) == 0) martial = "unarmed";
                else if ( sizeof(pmap) == 1) martial = (keys(pmap))[0];
                else if ( sizeof(pmap) == 2) martial = (keys(pmap))[me->query_temp("action_flag")];
//else
  //                      martial = "unarmed";
        }
 else{
 if( martial == "axe" ||
     martial == "blade" ||
            martial == "dagger" ||
            martial == "fork" ||
            martial == "hammer" ||
            martial == "parry" ||
            martial == "unarmed" ||
            martial == "staff" ||
            martial == "sword" ||
            martial == "throwing" ||
            martial == "spear" ||
            martial == "whip" )
   return notify_fail("这种外功不需指定武功种类！\n");
 }
  //      if( weapon = me->query_temp("weapon") )
    //        martial = weapon->query("skill_type");
    //    else
      //      martial = "unarmed";


        if( stringp(skill = me->query_skill_mapped(martial)) ) {
notify_fail("你所使用的外功中没有这种功能。\n");
                if( SKILL_D(skill)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(skill) )
                                me->improve_skill(skill, 1, 1);
                        return 1;
                } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                        if( random(120) < (int)me->query_skill(martial, 1) )
                                me->improve_skill(martial, 1, 1);
                        return 1;
                }
else {
if( sscanf(arg, "%s %s", action, target_ob)==2 )
                            {
target = present(target_ob, environment(me));
if( !target )
                                  return notify_fail("这里没有 " + target_ob + "。\n");
                            }
                            else
                            {
                                action = arg;
                            }

file = CLASS_D("fuqiperform/")+action;
if( !stringp(file) || file_size(file + ".c") <= 0 )
                            return 0;

return (int)call_other( file, "perform", me, target);
                       }
return 0;
        }
        return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。


换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}

