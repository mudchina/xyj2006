//Cracked by Roath
// bang.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *t;
	string ss,st,t1,t2,s1,s2;

	if (!arg) return notify_fail("用法不对!\n");

	ss=me->query("marks/帮派");
	if (ss!=0)
	{
		t1="marks/"+ss;
		st=me->query(t1);
	}
	if( arg=="dismiss" ) {
		if( ss==0 )
			return notify_fail("你现在并没有参加任何帮会。\n");
		write("你脱离了"+ss+"。\n");
		me->delete("marks/帮派");
		me->delete(t1);
		me->set("title","普通百姓");
		return 1;
	}
	if( sscanf(arg, "with %s", arg)==1 ) {
		object ob;
		if( !(ob = present(arg, environment(me)))
		|| 	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("你想和谁成为同帮的伙伴？\n");

		s1=ob->query("marks/帮派");
		if (s1!=0)
		{
			t2="marks/"+s1;
			s2=ob->query(t2);
		}
	       	if( me==(object)ob->query_temp("pending/bang") ) 
		{
			if ((ss!=0)&&(s1!=0))
			{
				ob->dellete_temp("pending/bang");
				return notify_fail("双方都加入帮会。\n");
			}
		}		
		if( (ss==0) || (st=="舵主" )) {
		       if( me==(object)ob->query_temp("pending/bang") ) {
				if( ss==0 ) {
					me->set("marks/帮派",s1);
					me->set(t2,"帮众");
					message_vision("$N决定加入$n的"+s1+"。\n", me, ob);
				} else {
					ob->set("marks/帮派",ss);
					ob->set(t1,"帮众");
					message_vision("$N决定让$n加入"+ss+"。\n", me, ob);
				}
				ob->dellete_temp("pending/bang");
				return 1;
			} else {
				if (st=="舵主")
				{
					message_vision("$N邀请$n加入"+ss+"。\n", me, ob);
					tell_object(ob, YEL "如果你愿意加入，请用 bang with " + me->query("id") + "。\n" NOR);
				} else {
					if (s2=="舵主")
					{
						message_vision("$N申请加入$n的"+s1+"。\n", me, ob);
						tell_object(ob, YEL "如果你同意加入，请用 bang with " + me->query("id") + "。\n" NOR);
					} else {
						return notify_fail("只能向舵主申请加入帮会。\n");
					}
				}
				me->set_temp("pending/bang", ob);
				return 1;
			}
		} else
			return notify_fail("只有舵主可以邀请别人加入。\n");
	}
}

int help(object me)
{
	write(@HELP
帮会指令使用方法:

bang with <某人> - 跟某人同帮. 必须要双方都同意加入且其中一人是舵主才会生效。
bang dismiss     - 离开帮会. 
HELP
	);
	return 1;
}
