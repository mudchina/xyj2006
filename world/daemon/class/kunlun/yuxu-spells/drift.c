// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用金光纵地法！\n");
        if( me->query("mana") < 800 )
                return notify_fail("你的法力不够！\n");
        if( me->query("sen") <= 500 )
                return notify_fail("你的精神太差！\n");
        if( time()-(int)me->query_temp("xiao_end") < 30 )
          return notify_fail("纵地金光法不能连续使用！\n");
        if( me->query("faith")<100)
                return notify_fail("以你在昆仑山玉虚洞的名望，还不会使用金光纵地法。\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用金光纵地法！\n"); 	
        if(me->query("family/family_name") != "昆仑山玉虚洞" )
                return notify_fail("你与昆仑无缘,领悟不到玉虚仙法的精髓!!\n");
	if( target )
		return notify_fail("金光纵地法只能对自己使用！\n");
	write("你要移动到哪一个人身边？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("中止施法。\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)) {
		write("你无法感受到这个人的灵力 ....\n");
		write("你要移动到哪一个人身边？");
//		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("战斗中无法使用金光纵地法！\n");
		return;
	} else if( me->query("mana") < 800 ) {
		write("你的法力不够！\n");
		return;
	}

	me->add("mana", -75);
	me->receive_damage("sen", 30);
	
        message_vision( HIY "$N低头闭目，开始施展金光纵地术 ....\n" NOR, me);
  	me->set_temp("xiao_end",time());
        if( random(ob->query("max_mana")) < (int)me->query("mana") / 5 ) {
		write("你感受到对方的灵力，但是不够强烈。\n");
		return;
	}
	if( random(me->query_skill("spells")) < (int)ob->query("mana") / 50 ) {
		write("你因为不够熟练而失败了。\n");
		return;
	}
        if( random(50) > 
	(int)(me->query_skill("yuxu-spells",1))){
                write("你因为不够熟练而失败了。\n");
                return;
        }
        message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
                + "，一道金光钻入地下，光芒和人一齐消失得无影无踪！\n\n", environment(me), ({ me }) );
	me->move(environment(ob));
        me->start_busy(5);
	message( "vision", HIY "\n你的眼前突然出现一团耀眼的光芒，光芒中浮现出一个人影！\n\n" NOR,
		environment(ob), ({ me }) );
}


