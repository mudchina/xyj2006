//Cracked by Roath
// give.c

#include <ansi.h>
inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount, rev_val;
	mixed no_give;

    if(this_player()->is_busy())
	   return notify_fail("你正忙着呢．．．\n");
				 
	if(!arg) return notify_fail("你要给谁什么东西？\n");

       if (userp(me)&& !wizardp(me) ){
        if (uptime()- me->query_temp("last_give_time/give") < 3)
                  return notify_fail(WHT"你正忙着...... \n"NOR);
        me->set_temp("last_give_time/give",uptime());
             }
	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");


	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( me == who )  {
		write("Ok.\n");
		return 1;
	}


	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
    if( no_give=obj->query("no_give") )
           { if(userp(who)||!obj->query("canoe"))
			return notify_fail( stringp(no_give) ? no_give : "这样东西不能随意丢弃。\n");
         }
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			rev_val = do_give(me, obj2, who);
			if( rev_val )
			   obj->set_amount( (int)obj->query_amount() - amount );
		    else
			   destruct(obj2);
			return rev_val; 
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if (inv[i]->query("no_get")) continue;
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	if( no_give=obj->query("no_give") )
           { if(userp(who)||!obj->query("canoe"))
                        return notify_fail( stringp(no_give) ? no_give : "这样东西不能随意丢弃。\n");
         }
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	int   is_accept;
	object	*inv;
	mixed no_give;
    if(me->is_busy())
	   return notify_fail("你正忙着呢．．．\n");
    
    if(who->is_busy())
	   return notify_fail("对方正忙着呢，没时间理你．．．\n");

    if( no_give=obj->query("no_give") )
           { if(userp(who)||!obj->query("canoe"))
                        return notify_fail( stringp(no_give) ? no_give : "这样东西不能随意丢弃。\n");
         }
	if (QUEST->quest_give (me, who, obj)) {
		message_vision("$N给$n一"+obj->query("unit")+obj->name()+"。\n",me,who);
		if(userp(who)) {
		    if(who->query("env/no_accept") ||
			    !obj->move(who)) {
			message_vision("$N一不小心，$n掉到地上不见了。\n",
				who, obj);
			destruct(obj);
		    } else {
		        message_vision("$N由衷地向$n道谢。\n",who,me);
		    }
		} else {
		    message_vision("$N由衷地向$n道谢。\n",who,me);
		    destruct(obj);
		}
		return 1;
	} 

// no_accept should be in do_give Bula    
        if(who->query("env/no_accept"))
           return notify_fail("对方好象不愿意收下你的东西。\n");

        if( !interactive(who)) {
		if( !(is_accept=who->accept_object(me, obj)) )
			return notify_fail("对方不要你的东西。\n");
		if( is_accept == 2 )
			return 1;
	}

	if( !userp(who) && obj->value() ) { // give money to npc
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
	        string unit;
		if(obj->query_temp("d_mana")>0)
		  unit=obj->query_temp("unit");
                else
		  unit=obj->query("unit");
                if(strlen(unit)<2) unit="个";
		printf("你给%s一%s%s。\n", who->name(), unit,
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			unit, obj->name()), who );
		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			unit, obj->name()), environment(me), ({me, who}) );
        if (wizardp(me)&&!wizardp(who)&&me->query("id")!="take"){
message("channel:chat",HIG"【给予精灵】某人："+"据说"+me->query("name")+"给了玩家 "HIW+who->query("name")+HIG" 一"+obj->query("unit")+obj->name()+"。\n"NOR,users());
	        }	
		if(!userp(who) && !userp(obj)) destruct(obj); // mon 4/25/98
me->start_busy(1);
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.

不接受时 : set no_accept <任意值>
重新接受 : unset no_accept
HELP
    );
    return 1;
}
