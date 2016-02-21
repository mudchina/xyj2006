// kunxian suo
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit WHIP;
//inherit ITEM;

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
//      set("no_drop","这么好的宝物，扔了多可惜呀！\n");
//      set("no_give","这么好的宝物，留着自己用吧！\n");
      set("no_sell", 1);
  }
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ap,dp,ratio,mykar=me->query_kar(), attackfactor, dingtime;
    int myspells, myexp, victimspells, victimexp, mana_cost, sen_cost;
    string msg, objname=this_object()->name(), obj;
    
    if (this_object()->query("in_use")) return notify_fail("蛟龙已经离索而去，现在的"+objname+"不过是一条普通的绳索罢了。\n");
    if (!target) return notify_fail("你想用对谁用"+objname+"？\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim)) return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting()) return notify_fail("只有战斗中才能祭"+objname+"。\n");  
    if(victim->query("no_move")) return notify_fail("对方已经无暇自顾了，有必要用"+objname+"么？\n");
    //    if (member_array( victim, query_enemy()) != -1 )
    //         return notify_fail("人家又没惹你！\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("你的精神无法集中！\n");
    msg="$N从背后抽出一条"+objname+"，向空抛起，口中念念有词，\n";
    msg+="红光一闪，神索中飞出一条蛟龙，向$n扑去。\n";
    myspells=me->query_skill("spells")/10;
    myexp=me->query("combat_exp")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimexp=victim->query("combat_exp")/1000;
    ap=(myexp+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;
    attackfactor=random(ap+dp);
    if (wizardp(me) && me->query("env/combat")=="verbose")
	tell_object(me, GRN "进攻="+ap+", 防守="+dp+", 比例="+attackfactor+"。\n" NOR);
    if(attackfactor>dp/3)
    {
	msg+=HIR"$n被蛟龙盘个正着，顿时手忙脚乱，不知所措。\n" NOR;
	msg+=CYN"$n被"+objname+CYN"的法力定住了！\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random(mykar)/2+10;
	if (dingtime < 1) dingtime=1;
	if(dingtime>30) dingtime=30;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"被定住了"+chinese_number(dingtime)+"秒。\n" NOR);
	set("in_use", 1);
	set("suo_victim",victim);
	call_out("remove_ding", dingtime, victim);
    }
    else if(attackfactor>dp/6)
	msg+=HIB"$n伸手一指，大喝一声“落！”只见蛟龙变回红索，落回$N手中。\n"NOR;
    else if(attackfactor>dp/9)
    {
	msg+=HIB"$n伸手一指，大喝一声“回！”只见蛟龙反将$N缠住了！\n"NOR;
	dingtime=random(victim->query_kar())/2+10;
	if (dingtime<1) dingtime=1;
	me->set_temp("no_move");
	set("in_use",1);
	set("suo_victim",me);
	call_out("remove_ding", dingtime, me);
    }
    else
    {
	msg+=HIB"$n伸手一指，大喝一声“收！”只见蛟龙变回红索，落入$n手中。\n"NOR;
	this_object()->move(victim);
    }
    message_vision(msg,me,victim);
    mana_cost=me->query("max_mana")/4;
    if(mana_cost<250) mana_cost=250;
    if(mana_cost>me->query("mana")) mana_cost=me->query("mana");
    sen_cost=me->query("max_sen")/4;
    if(sen_cost<50) sen_cost=50;
    if(sen_cost>me->query("sen")-10) sen_cost=me->query("sen")-10;
    me->add("mana", -mana_cost);
    me->add("sen", -sen_cost);
    return 1;
}

void remove_ding(object victim)
{
    message_vision(CYN"只见蛟龙腾空而起，附回了"+RED+"捆仙索"+CYN"。$N又恢复了自由。\n" NOR, victim);
    victim->delete_temp("no_move");
    this_object()->delete("in_use");
    return;
}

// remove_ding when suo is destructed.
void remove()
{
    object victim;
    if(query("in_use") && (victim=query("suo_victim")))
	remove_ding(victim);
       ::remove();
}
