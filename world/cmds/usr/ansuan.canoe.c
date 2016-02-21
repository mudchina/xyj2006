// ansuan.c 暗算 
//by Yu Jue 98.09 
//modi lestat 2001 

#include <ansi.h> 

mapping default_where = ([ 
       "n":    "north", 
       "s":    "south", 
       "e":    "east", 
       "w":    "west", 
       "nu":   "northup", 
       "su":   "southup", 
       "eu":   "eastup", 
       "wu":   "westup", 
       "nd":   "northdown", 
       "sd":   "southdown", 
       "ed":   "eastdown", 
       "wd":   "westdown", 
       "ne":   "northeast", 
       "nw":   "northwest", 
       "se":   "southeast", 
       "sw":   "southwest", 
       "u":    "up", 
       "d":    "down", 
]); 

mapping default_dirs = ([ 
       "north":                "北面", 
       "south":                "南面", 
       "east":                 "东面", 
       "west":                 "西面", 
       "northup":              "北边", 
       "southup":              "南边", 
       "eastup":               "东边", 
       "westup":               "西边", 
       "northdown":            "北边", 
       "southdown":            "南边", 
       "eastdown":             "东边", 
       "westdown":             "西边", 
       "northeast":            "东北", 
       "northwest":            "西北", 
       "southeast":            "东南", 
       "southwest":            "西南", 
       "up":                   "上面", 
       "down":                 "下面", 
       "enter":                "里面", 
       "out":                  "外面", 
]); 

int main(object me, string arg) 
{ 
string who, where, dir, undir, where_temp, *name; 
object env, old_env; 
mapping exits; 
object target; 
string gen; 

if( !arg || sscanf(arg, "%s at %s", who, where_temp)!=2 ) 
return notify_fail("指令格式：ansuan <人物> at <方向>\n"); 

env = environment(me); 
if(!env) return notify_fail("你哪里也去不了。\n"); 
old_env = env; 

if( !undefinedp(default_where[where_temp]) ) 
where = default_where[where_temp]; 
else 
where = where_temp; 

if( !mapp(exits = env->query("exits")) || undefinedp(exits[where]) ) 
return notify_fail("没有这个方向。\n"); 

if( !objectp(env = find_object(exits[where])) ) { 
call_other(exits[where], "???"); 
env = find_object(exits[where]); 
} 

if (env == old_env) return notify_fail("直接下 kill 指令好了。\n"); 
   if( !old_env->valid_leave(me, where) ) { 
       write(query_notify_fail()); 
       return 1; 
       } 

if( env->query("no_fight") ) 
return notify_fail("那里禁止战斗。\n"); 

if( !objectp(target = present(who, env)) ) 
return notify_fail("这个方向没有此人。\n"); 

if (wiz_level(me) < wiz_level(target)) 
return notify_fail("你不能攻击巫师等级比你高的对手。\n"); 

if ( userp(me) && userp(target) && target->query("age") < 17 ) 
return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n"); 
if ( userp(me) && userp(target) && target->query("combat_exp") < 50000 ) 
return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n"); 

if( !target->is_character() || target->is_corpse() ) 
return notify_fail("看清楚一点，那并不是生物。\n"); 

if( me->is_busy() ) 
return notify_fail("你的动作还没有完成，不能暗算。\n"); 

if( me->is_fighting() ) 
return notify_fail("你正忙着战斗呢，还有心思暗算别人？\n"); 

if( !living(target) ) 
return notify_fail(target->name() + "都已经这样了，你还用得着暗算吗？\n"); 

if( (int)me->query("sen") < 100 ) 
return notify_fail("你无法集中精力，暗算不了别人。\n"); 

dir = env->query("short"); 
if( !undefinedp(default_dirs[where]) ) 
dir = default_dirs[where] + dir; 

undir = old_env->query("short"); 

if(me->query("gender") == "女性") 
gen = "倩影"; 
else 
gen = "人影"; 

write(CYN "你摒息静气，纵身而起，向" + dir + "的" + target->name() + "扑去！\n" NOR); 
tell_room(old_env, CYN "\n一条" + gen + "忽然向" + dir + "扑去！\n" NOR, ({me})); 
message_vision(CYN "\n一条" + gen + "忽然从" + undir + "向$N扑来！\n\n" NOR, target); 

name = me->query_temp("apply/name"); 
me->set_temp("apply/name", ({gen})); 

me->move(environment(target)); 

COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2); 

if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) { 
message_vision(CYN"$N一时没有防范，被$n攻了个措手不及！\n"NOR, target, me); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2); 
} else { 
message_vision(CYN"$N经验丰富，不及细看，立刻向$n反击！\n"NOR, target, me); 
COMBAT_D->do_attack(target, me, target->query_temp("weapon"), 1); 
} 

if( random(me->query("combat_exp")) < (int)target->query("combat_exp")/3 ) { 
me->set_temp("apply/name", name); 

tell_object(target, CYN"你一定神，原来是" + me->name() + "在暗算你！\n"NOR); 
write(CYN "不好，你被" + target->name() + "发觉了！\n"NOR); 
message_vision(CYN"$N喝道：$n！你敢暗算我，我跟你没完！\n"NOR, target, me); 
if (!userp(target)) target->kill_ob(me); 
else target->fight_ob(me); 
me->start_busy(3); 
} else { 
tell_room(env, CYN "\n" + gen + "转瞬不见！\n\n"NOR, ({me})); 
write(CYN"\n你立刻退回原处！\n\n"NOR); 

me->move(old_env); 
tell_room(old_env, CYN "\n转眼间" + gen + "又回到原处！\n\n"NOR, ({me})); 

me->set_temp("apply/name", name); 

tell_object(target, CYN"你一定神，可是什么都没看见。\n"NOR); 
tell_room(env, CYN + target->name() + "一脸惶恐，竟然不知道遭了谁的暗算！\n"NOR, 
({target})); 
write(CYN "哈哈，" + target->name() + "居然没看出来。\n"NOR); 
write(CYN "你干咳了两声，一脸无辜的样子。\n"NOR); 
} 

me->start_busy(2); 
me->receive_damage("sen", 50); 

return 1; 
} 

int help(object me) 
{ 
write(@HELP 
指令格式 : ansuan <人物> at <方向> 

这个指令让你暗算位于<方向>的<人物>。 
如果暗算成功，则敌人发现不了你。否则...:) 
HELP 
); 
return 1; 
} 

