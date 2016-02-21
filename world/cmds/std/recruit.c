// recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int i;

	if( !arg ) return notify_fail("指令格式：recruit [cancel]|<对象>\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("你现在并没有收录任何人为弟子的意思。\n");
		write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
		tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
		me->delete_temp("pending/recruit");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("你想收谁作弟子？\n");

	if( ob==me ) return notify_fail("收自己为弟子？好主意．．．不过没有用。\n");

	if( ob->is_apprentice_of(me) ) {
		message_vision("$N拍拍$n的头，说道：「好徒儿！」\n", me, ob);
		return 1;
	}

	if( !me->query("family") )
		return notify_fail("你并不属于任何门派，你必须先加入一个门派，或自己创一个才能收徒。\n");

	if (!me->query("family/generation"))
		return notify_fail("你乃弃徒，先求哪一位本门师父将你重列门墙再说吧。\n");
	if ( (ob->query("family")) && (me->query("family/family_name") != ob->query("family/family_name")) )
		return notify_fail(ob->name()+"乃"+ob->query("family/family_name") +"弟子，未经其师尊同意就挖人家墙角不太好吧。\n\n");
	if (me->query("family/master_id") == ob->query("id"))
		return notify_fail("开什么玩笑？人家是你师父，还有什么要从你这里学的？\n");

        if ( userp(me) && userp(ob) && (wizardp(me) != wizardp(ob)) ) 
                return notify_fail("巫师玩家之间不能有师徒关系。\n");
/*
	if( ob->query("family")){
	if ((int)me->query("family/generation") >= (int)ob->query("family/generation"))
		return notify_fail("你只能收辈份比你低的同门派弟子为徒。\n");
	}
*/
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N决定收$n为弟子。\n\n"
				"不过看样子$n显然没有办法行拜师之礼。\n\n",
				me, ob);
			return 1;
		}
	// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		if((ob->query("family")) && ( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) ) {
			message_vision(
				"$N决定投入$n门下！！\n\n"
				"$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n\n",
				ob, me);
			ob->set("score", 0);
			ob->add("betrayer", 1);
		} else
			message_vision(
				"$N决定收$n为弟子。\n\n"
				"$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」\n",
				me, ob);

		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");

		write("恭喜你新收了一名弟子！\n");
		family = ob->query("family");
		tell_object( ob, sprintf("恭喜您成为%s的第%s代弟子。\n", family["family_name"],
			chinese_number(family["generation"]) ));

		return 1;
	

	} else {

		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("你想收" + ob->name() + "为弟子，但是对方还没有答应。\n");
		else if( objectp(old_rec) ) {
			write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
			tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$N想要收$n为弟子。\n", me, ob);
		tell_object(ob, YEL "如果你愿意拜" + me->name() + "为师父，用 apprentice 指令。\n" NOR);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
指令格式 : recruit [cancel]|<对象>
 
这个指令能让你收某人为弟子, 如果对方也答应要拜你为师的话.
 
HELP
        );
        return 1;
}
