// check somebody's position

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob;
	int mana_cost;
	int sen_cost;
	string msg;

	if(!arg) 
		return notify_fail("你想打听谁的状态？\n");
	if((int)me->query("combat_exp")<5000)
		return notify_fail("你的道行不够，用不了地耳灵。\n");
	if((int)me->query("mana")<60) 
		return notify_fail("你的法力不够，用不了地耳灵。\n");
	if((int)me->query("sen")<=50)
		return notify_fail("你现在太累了，休息休息吧！\n");
	mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
	mana_cost=mana_cost+10;
	if(mana_cost > -50) mana_cost=-50;
	me->add("mana", mana_cost);
	sen_cost=50;
	message_vision(HIY "$N口中念了几句咒文，眼中突然精光一闪，大喝一声“顺风耳何在！”\n只听嘿嘿几声奸笑，不知从哪里钻出来一个肥头大耳的家伙，在$N耳边低声说了几句话。\n" NOR, me);
	ob = find_player(arg);
	if(!ob) {
	    ob=present(arg,environment(this_player()));
	    if(ob && !living(ob)) ob=0;
	}
	if( !ob ) ob = find_living(arg);
	if(!ob || (ob->query("env/invisibility") && wizardp(ob) ))
		return notify_fail("顺风耳告诉你：奇怪，找不到这个人．．．\n");
	
        write("顺风耳告诉你："+ob->query("name")+"的道行已达"+RANK_D->describe_dx((int)ob->query("daoxing"))+"的境界。\n");  
	write("顺风耳告诉你："+ob->query("name")+"的武功已达"+RANK_D->describe_exp((int)ob->query("combat_exp"))+"的境界。\n");
	write("顺风耳告诉你："+ob->query("name")+"的法力修为已达"+RANK_D->describe_fali((int)ob->query("max_mana"))+"的境界。\n");	
	write("顺风耳告诉你："+ob->query("name")+"的内力修为已有"+RANK_D->describe_neili((int)ob->query("max_force"))+"的火候。\n");	


        message_vision("$N忽然莫名其妙地哆嗦了一下。\n",ob); 
	msg="你急忙掐指一算，";
        if(ob->query("combat_exp")>me->query("combat_exp")/5)
	  msg+="原来是"+me->name()+"("+me->query("id")+")"+
	       "正在打听你的道行。\n";
        else
	  msg+="心中却只是一片茫然。\n";
        tell_object(ob, msg);

	return 1;
}

int help(object me)
{
	string desc_dx, desc_fali, desc_exp;

	write(@HELP
指令格式 : check|cha [<某人>]

地耳灵: 打听别人现在的道行,法力及武功级别。

HELP
    );

	write("道行境界：\n\n");
	write(RANK_D->query_description(0));
	write("\n武学境界：\n\n");
	write(RANK_D->query_description(1));
	write("\n法力修为：\n\n");
	write(RANK_D->query_description(2));
	write("\n\n");	
		
    return 1;
}

