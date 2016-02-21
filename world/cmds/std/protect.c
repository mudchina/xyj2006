//Bula 3.18
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who,obj;


        if( !arg ) {
		if(me->query_temp("protect") ) {
			if( objectp(obj=find_living(me->query_temp("protect")) )){
				tell_object(me, "你现在正在保护"+obj->query("name")+"。\n");
				return 1;
			}
		}
		tell_object(me,"你要保护什么人？\n");
		return 1;
	}
	
	if( arg=="me" || arg==me->query("id") )  
                return notify_fail("你要保护什么人？\n");

        if( arg=="none") {
		if( !me->query_temp("protect") ){
			tell_object(me, "你并没有保护任何人。\n");
			return 1;
		}
                if( objectp(obj=find_living(me->query_temp("protect")) )) {
                        tell_object(obj, me->query("name")+"放弃保护你了。\n");
			tell_object(me, "你放弃保护"+obj->query("name")+"。\n");
			me->delete_temp("protect");
			return 1;
		}
		tell_object(me, "你放弃保护别人。\n");                
		me->delete_temp("protect");                
		return 1;
        }

	if( !objectp(who=present(arg, environment(me))))
		return notify_fail("你要保护什么人？\n");

	if( !living(who) )
		return notify_fail("你不能保护"+who->query("name")+"。\n");

	if( me->query_temp("protect") == who->query("id") )
		return notify_fail("你已经在保护这个人了。\n");

        if( time()-30 <= (int)me->query_temp("protect_time") )
                return notify_fail("你保护太多人了。\n");

	if((int)me->query_condition("no_pk_time") > 480 )
		return notify_fail("你最近杀人太多。。。\n");

	if( me->query_temp("protect") ) {
                if( objectp(obj=find_living(me->query_temp("protect")) )) {
                        tell_object(obj, me->query("name")+"放弃保护你了。\n");
			tell_object(me, "你放弃保护"+obj->query("name")+"。\n");
		}
        }

	message_vision(HIC"$N开始保护$n。\n"NOR, me, who);

	who->set_temp("protected", 1);
	who->set_temp("protect_ob", me->query("id"));
	me->set_temp("protect", who->query("id"));
	me->set_temp("protect_time", time());
	return 1;

}

int help(object me)
{
   write( @HELP
指令格式: protect [<人物>|<NPC>|none]

开始保护／放弃保护某人。
HELP
   );
   return 1;
}
