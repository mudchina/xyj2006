// make by take for cs system. edit 1-31-02 13:20
inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIC"五"+HIG"色"+HIY"妖"+HIR"火"NOR, ({"ling huo","huo","fire"}));
	set("unit", "团" );
	set_weight(1000000000);
        set("long",@long
这是火灵符被邪恶的咒语催动生成的五色火焰，要想扑灭(pu fire)它只怕要花点时间。如果想中断可用(halt) 。
long );
	set("no_clean_up", 1);
	set("no_get",1);
	set("no_sell",1);
	set("no_put",1);
	setup();

}

void init()
{
	add_action("do_pu","pu");
	add_action("do_halt","halt");
	call_out("wait_TWin",130+random(30));
}

int do_pu()
{
	object ob,me;
	me = this_player();
	ob = this_object();
	if (me->is_busy())
	return notify_fail("你还是先救救自己吧。\n");
	if (me->query_temp("pkgame") != "ct")
	return notify_fail("这里太危险，你还是不要多管闲事了。\n");
	if (me->query("env/invisibility"))
	return notify_fail("念动咒语的时候不能隐身。\n");
	me->set_temp("waitwin",1);
	me->start_busy(9);
	message_vision (HIC"\n$N面对着充满妖气的火焰慢慢闭上眼睛，默念咒语。。。。。。\n"NOR, me );
	call_out("wait_CtWin",10,me,ob);
	return 1;
}

int do_halt()
{
	object me;
	me = this_player();
	if (!me->query_temp("waitwin")) return 0;
	remove_call_out("wait_CtWin");
	me->start_busy(1);
	me->delete_temp("waitwin");
    	message_vision (HIC"\n$N机警地睁开了双眼，恢复了战斗状态。\n"NOR, me );
    	return 1;
}

void wait_CtWin(object me,object ob)
{
   	if (!me || !ob || !me->query_temp("waitwin")) return;
   	remove_call_out("wait_CtWin");
	remove_call_out("wait_TWin");
     	message_vision (HIC"\n五色妖火被$N法力压制，渐渐失去灵气无声无息地熄灭了！\n"NOR, me );
   	message( "rumor", HIM"\n\n【长安夜话】某人：五色妖火竟然被"HIW+me->query("family/family_name")+HIY""+me->query("name")+HIM"施法扑灭了。\n\n"NOR, users() );
     	me->delete_temp("waitwin");
     	me->add_temp("pgwin",2);
	message( "system", BLINK HIR"\n【 CS 大赛】： 本局结束，此局比赛"+HIY"大侠"+BLINK HIR"组获胜,请各位准备5秒钟后开始下一局比赛。。。。。。\n" NOR, users() );
       	"/cmds/usr/pkgame"->over();
     	"/cmds/usr/pkgame"->query_Win("ct");
        destruct (ob);
}

void wait_TWin()
{
	object ob,who;
	ob = this_object();
	if ( !ob ) return;
	remove_call_out("wait_CtWin");
	remove_call_out("wait_TWin");
  message( "chat", HIY"\n\n【太平盛世】千里眼(Qianli yan)：五色妖火重现人间，下界一片火海，生灵涂炭。。。。。。\n\n"NOR, users() );
	message( "system", BLINK HIR"\n【 CS 大赛】： 本局结束，此局比赛"+HIY"纵火犯"+BLINK HIR"组获胜,请各位准备5秒钟后开始下一局比赛。。。。。。\n" NOR, users() );
 	if ( ob->query_temp("fire_id") )
 	{
 		who = ob->query_temp("fire_id");
 	  if ( who )
 	  who->add_temp("pgwin",1);
 	}
 	"/cmds/usr/pkgame"->over();
	"/cmds/usr/pkgame"->query_Win("t");
  destruct (ob);
}


	
