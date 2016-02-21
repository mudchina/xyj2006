// kunxian suo
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit WHIP;
//inherit ITEM;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
void remove_ding(object me, object victim);

void create()
{
    set_name(RED "捆仙索" NOR,({"kunxian suo", "suo", "rope", "kunxiansuo", "kunxian", "fabao"}));
    set_weight(5000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","条");
	set("value",0);
	set("is_monitored", 1);
	set("replace_file", "/d/qujing/wudidong/npc/obj/kunxian-fake");
	set("long","一条暗红色的绳子，也不知道是什么做的。\n");
    }
    init_whip(20);
    setup();
}

void init()
{
  ::init();
  if (!wizardp(this_player()))
  {
      set("no_drop","这么好的宝物，扔了多可惜呀！\n");
      set("no_give","这么好的宝物，留着自己用吧！\n");
      set("no_sell", 1);
  }
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    
    if (this_object()->query("in_use"))
	return notify_fail("蛟龙已经离索而去，现在的"+objname+"不过是一条普通的绳索罢了。\n");
    if (!target)
	return notify_fail("你想用对谁用"+objname+"？\n");
    
    if(!objectp(victim=present(target,environment(me))))
	return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim))
	return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting())
	return notify_fail("只有战斗中才能祭"+objname+"。\n");  
    if(victim->query("no_move"))
	return notify_fail("对方已经无暇自顾了，有必要用"+objname+"么？\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("你的精神无法集中！\n");
    msg="$N从背后抽出一条"+objname+"，向空抛起，口中念念有词，\n";
    msg+="红光一闪，神索中飞出一条蛟龙，向$n扑去。\n";
    condition=determine_success(me, victim);
    switch(condition)
    {
      case 1:
	msg+=HIR"$n被蛟龙盘个正着，顿时手忙脚乱，不知所措。\n" NOR;
	msg+=CYN"$n被"+objname+CYN"的法力定住了！\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random(mykar);
	if (dingtime < 1) dingtime=1;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"被定住了"+chinese_number(dingtime)+"秒。\n" NOR);
	this_object()->set("in_use", 1);
	call_out("remove_ding", dingtime, me, victim);
	break;
      case 0:
	msg+=HIB"$n伸手一指，大喝一声“落！”只见蛟龙变回红索，落回$N手中。\n"NOR;
	break;
      case -1:
	msg+=HIB"$n伸手一指，大喝一声“回！”只见蛟龙反将$N缠住了！\n"NOR;
	dingtime=random(victim->query_kar());
	if (dingtime<1) dingtime=1;
	me->set_temp("no_move");
	this_object()->set("in_use");
	call_out("remove_ding", dingtime, victim, me);
	break;
      case -2:
	msg+=HIB"$n伸手一指，大喝一声“收！”只见蛟龙变回红索，落入$n手中。\n"NOR;
	this_object()->move(victim);
	break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}
int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    cost=me->query(variable)/4;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

void remove_ding(object me, object victim)
{
    string msg=CYN"只见蛟龙腾空而起，附回了"+query("name")+CYN"。\n"NOR;
    this_object()->delete("in_use");
    
    if(!victim) return;

    if (living(victim))
	msg += CYN"$n又恢复了自由。\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}
int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;

    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;

    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;

    attackfactor=random(ap+dp);

    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}
