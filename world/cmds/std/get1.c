// get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob, object old_env);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2,old_env;
	int i, amount;
        mixed no_get;

	if( !arg ) return notify_fail("你要捡起什么东西？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
		if(living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
                if(env->query("disable_type") == "<睡梦中>")
	            	return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
	} else env = environment(me);


	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("这里没有这样东西。\n");
		no_get = obj->query("no_get");
		if( no_get 
		&& !(wizardp(me) && me->query("env/override")) ) {
			return notify_fail(stringp(no_get) ? 
				no_get : "这个东西拿不起来。\n");
		}
	
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开拿走。\n");
		if( amount < 1 )
			return notify_fail("东西的个数至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("这里没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj,0);
		} else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_get(me,obj2, environment(obj))) {
			    obj->set_amount( (int)obj->query_amount()-amount);
			    return 1;
			}
			return 0;
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	return notify_fail("你还在战斗中！只能一次拿一样。\n");
		if( !env->query_max_encumbrance() )	return notify_fail("那不是容器。\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("那里面没有任何东西。\n");

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->is_character() || inv[i]->query("no_get"))
				continue;
			do_get(me, inv[i],0);
		}
		write("Ok。\n");
		return 1;
	}

// added by mon to incorporate the "bian" function.
        if(!objectp(obj= present(arg, env)) || obj==this_player())
	   return notify_fail("你附近没有这样东西。\n");
        else {
         if((obj->query_temp("d_mana"))>0) {
	  if( obj->query_temp("is_living")==1 )
	    return notify_fail("你附近没有这样东西。\n");
	  else {
	    no_get = obj->query("no_get");
            if( no_get 
	    && !(wizardp(me) && me->query("env/override")))
                return notify_fail(stringp(no_get) ? no_get : "这个东西拿不起来。\n");
            old_env = environment(obj);
	    if( obj->move(me) ) {
                if( me->is_fighting() ) me->start_busy(1);
	    message_vision( sprintf("$N%s一%s$n。\n",
            old_env==environment(me)?  "捡起": (old_env->is_character() ?
            "从" + old_env->name() + "身上" + "搜出":
            "从" + old_env->name() + "中拿出"),
	    undefinedp(obj->query_temp("unit"))?
	    "个":obj->query_temp("unit")
	    ), me, obj);
	    return 1; 
	    } else return 0;
          }
        } else {
	  if( living(obj) )
		return notify_fail("你附近没有这样东西。\n");
        }
	}

        no_get = obj->query("no_get"); 
        if( no_get  
	&& !(wizardp(me) && me->query("env/override")))
                return notify_fail(stringp(no_get) ? no_get : "这个东西拿不起来。\n");

	return do_get(me, obj,0);
}
	
int do_get(object me, object obj, object old_env)
{
	object *enemy;
	int equipped;
	object* inv;
/*
	inv = all_inventory(me);
	if( sizeof(inv) > 30 )
	   return notify_fail("你身上再也装不下任何东西了。\n");
*/
	if( !obj ) return 0;
	if(!old_env) old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
		//	if( !userp(obj) && !obj->is_corpse() )
		//		return notify_fail("你只能背负其他玩家的身体。\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	if( obj->query("equipped") ) equipped = 1;
	if( obj->move(me) ) {
		if( me->is_fighting() ) me->start_busy(1);
		if( obj->is_character() )
		  message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
		else
		  message_vision( sprintf("$N%s一%s$n。\n", 
		  (!old_env || old_env==environment(me))? "捡起":
		  (old_env->is_character() ?
		  "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
		  "从" + old_env->name() + "中拿出"),
	          undefinedp(obj->query("unit"))?
	          "个":obj->query("unit")
		  ), me, obj );
		  if(obj->query("obj_owner")&&obj->query("obj_owner")!=me->query("id"))
		  { write("结果一不小心 ，"+obj->query("name")+"从你身上掉下来摔成了粉碎！\n");
		    destruct(obj);
		   }
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : get <物品名称> [from <容器名>]
 
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}
 
