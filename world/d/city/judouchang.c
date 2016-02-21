#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",HIR "决斗场" NOR);
        set("long", @LONG
决斗场是专为解决大唐争斗而设立的。在这里决斗，生死自负,不用担心
PK后果。墙上贴着个贴子(tiezi),好象是公告。
LONG );
        set("no_steal",1);
        set("no_beg",1);
        set("item_desc", ([
            "tiezi" : @TEXT

----------------------------------------------------------------------
决斗场启者：

决斗双放使用 juedou 命令征求对方意见，当双放同意后既开始决斗。
决斗后胜利者可用 xiaochu 命令消除PK记录，败者后果自负。
                                            大唐巫师小组
----------------------------------------------------------------------

TEXT
        ]) );
        set("exits", ([
"down" : "/d/city/wuguan",
        ]));
        setup();
}
void init()
{
	add_action("do_kill","juedou");
	add_action("do_xiaochu","xiaochu");
}
int do_kill(string arg)
{
	object obj, old_target;
	object me;
	me = this_player();
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");
	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");
	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");
	if( !living(obj) )
		return notify_fail(obj->name() + "已经无法战斗了。\n"); 
	if(obj==me)	return notify_fail("你不能攻击自己。\n");
	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		message_vision("\n$N对著$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，今日与"
			+ RANK_D->query_respect(obj) + "决一生死！\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你决斗的念头。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "如果你愿意和对方进行决斗，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 juedou 指令。\n" NOR);
		write(YEL "你必须等对方同意才能进行决斗。\n" NOR);
		return 1;
	}
	if( obj->query("can_speak") ) {
		message_vision("\n$N对著$n说道：" 
                        + RANK_D->query_self(me) 
                        + me->name() + "，今日与"
                        + RANK_D->query_respect(obj) + "决一生死！\n\n", me, obj);
		notify_fail("看起来" + obj->name() + "并不想跟你决斗。\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;
		me->kill_ob(obj);
		me->set_temp("juedou/pks", me->query("PKS"));
		me->set_temp("juedou/number", 1);
		obj->kill_ob(me);
		obj->set_temp("juedou/pks", me->query("PKS"));
		obj->set_temp("juedou/number", 1);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->kill_ob(obj);
		me->set_temp("juedou/pks", me->query("PKS"));
		me->set_temp("juedou/number", 1);
		obj->kill_ob(me);
		obj->set_temp("juedou/pks", me->query("PKS"));
		obj->set_temp("juedou/number", 1);
	}
        write_file("/log/static/ATTEMP_KILL",sprintf("%s   试图与   %s 决斗 on %s\n",
        me->name(1),obj->name(1), ctime(time()) ));
	return 1;
}

int do_xiaochu()
{
	object me;
	me = this_player();
	if( me->query_temp("juedou/number") == 1)
{
		if ( me->query_temp("juedou/pks")+1 == me->query("PKS")) //验证PK记录
{
		tell_object(me,"你的PK记录消除了。\n");
		me->add("PKS", -1);
		me->delete_temp("juedou");
		return 1;
}
	        tell_object(me,"决斗没有分出胜负吧！\n");
	        return 1;
}
	tell_object(me,"你瞎折腾什么。\n");
                return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("juedou");
        return ::valid_leave(me, dir);
}
