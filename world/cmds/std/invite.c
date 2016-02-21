// invite.c
// mon 3/8/97

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *killer, callname, id, *host;

	if( !arg )
		return notify_fail("你想邀请谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("你想邀请谁？\n");

	message_vision("$N对$n说道：欢迎"+RANK_D->query_respect(obj)
               +"有空儿到我家来玩儿！ \n", me, obj);
        host=obj->query_temp("invited");
        id=me->query("id");
        if(host) {
          if(member_array(id,host)>-1) return 1;
          host=host+({id});
        } else {
          host=({id});
        }
        obj->set_temp("invited",host);

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : invite|yaoqing <人物>
 
邀请别人到你家里作客。

 
HELP
    );
    return 1;
}
 
