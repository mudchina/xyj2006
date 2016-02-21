// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// preach.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) return notify_fail("cast peach on sb\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁布道？\n");

	if( me->query("family/family_name")!="方寸山三星洞")
	        return notify_fail("只有道学造诣极高的道家门下才能布道。\n");
	if( me->query_temp("preaching") )
		return notify_fail("你正在布道！\n");
	if( me->is_fighting() )
                return notify_fail("不可以一边打架一边布道！\n");
	if( target->is_fighting() ) 
                return notify_fail(target->name() + "正在打架，没空理你！\n");

        if((int)me->query("mana") < 70 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 70 )
                return notify_fail("你无法集中精力！\n");
        
        write("你要布道他身上的什么东西？");
        input_to( (: call_other, __FILE__, "select_object", me, target :));        
        return 1;
}

void select_object(object me, object target, string name)
{
	object ob;
	int sp,dp;
	
	if(!name||name==""){
		write("停止布道。\n");
		return;
	}        

	if( !ob = present(name, target) ) {
		object *inv;
		inv = all_inventory(target);
		if( !sizeof(inv) ){
			write( target->name() + "身上看起来没有什麽让你值得布道东西。\n");
			return;
		}
		ob = inv[random(sizeof(inv))];
	}

	if ( ob->query("no_drop") || ob->query("owner")){
		write(target->name()+"好象不会理会你似的。\n");
		return;
	}

	sp = (int)me->query_skill("dao",1) * (int)me->query_skill("dao",1) 
	 + (int)me->query_cps() * (int)me->query_cps() * (int)me->query_cps() ;
	if( sp < 5000 ){
	    write("你还没有到达布道的阶段。\n");
	    return;
	}
	dp = (int) target->query("faith")-(int)target->query("bellicosity") + 
	(int)target->query_cps() * (int)target->query_cps() * (int)target->query_cps() * (int)target->query_cps() +
	(int)target->query_int()*(int)target->query_int()*(int)target->query_int();
	tell_object(me, "你庄严地向" + target->name() + "诉说身揣"
			+ ob->query("unit") + ob->name() +"的种种坏处...\n\n");
	tell_object(target, me->name() + "满面庄严，向你耐心诉说道：这位" + RANK_D->query_respect(target) + "，人生如梦，放弃" 
			+ ob->query("unit") + ob->name() + "吧 ...！\n\n");
	message("vision", "只见" + me->name() + "满面庄严，神情严肃，\n向" 
		+ target->name() + "不厌其烦地布道着．．．",environment(me), ({ me, target }) );

	if( ob->query("equipped"))dp=dp*2;
	
	me->set_temp("preaching", 1);
        me->add("mana", -50);
        me->receive_damage("sen", 50);
	call_out( "compelete_preach",random(3)+1, me, target, ob, sp, dp);
}

private void compelete_preach(object me, object target, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	me->delete_temp("preaching");
        if(!target) {
                tell_object(me, "太可惜了，你给布道的人已经不见了。\n");
                return;
        }
	if( environment(target) != environment(me) ) {
		tell_object(me, "太可惜了，你给布道的人已经走了。\n");
		return;
	}

	if(!target->query("spi")) {
		tell_object(me,target->name()+"对你的布道无动于衷！\n");
		return;
	}
	if( living(target) && (random(sp+dp) > dp) && ob->move(environment(me))) 
	{
		message_vision("$N听着$n的布道，深有感触，一激动，将一" 
				+ ob->query("unit") + ob->name() + "丢在地下。\n",target,me);
		me->start_busy(1);
	} 
	else 
	{
		if( random(sp+dp) > dp/2 ) {
                message_vision("$N象一块顽石般，对$n的布道毫不理会。\n", target,me);
                me->start_busy(3);
			return;
		}
		else
		message_vision("$N狠狠地瞪了$n一眼，喝道：真讨厌！去死了吧！\n", target,me);
		if(!environment(target)->query("no_fight"))	
		target->fight_ob(me);
		me->start_busy(3);
	}
}

