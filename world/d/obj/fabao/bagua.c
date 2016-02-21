// bagua.c 铁八卦
// 9-26-97 pickle

/************************************************************/
#include <ansi.h>

inherit ITEM;

int ji(string arg);
int determine_success(object me, object victim);

/************************************************************/

void create()
{
    set_name(BLU "铁八卦" NOR,({"tie bagua", "bagua", "tie", "tiebagua", }));
    set_weight(15000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","块");
	set("value",10000);
	set("is_monitored", 1);
	set("no_busy", 1);
	set("long","一块八角形的生铁，上面刻着八卦图形，中间刻着些歪歪扭扭的符号，不知什么意思。\n");
	set("material", "iron");
    }
    setup();
}

/************************************************************/

int ji(string target)
{
    object me=this_player(),victim;
    int condition;
    string msg, objname=this_object()->name();
    
    if (!target) victim=me;
    else if(!victim=present(target,environment(me)))
	return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim))
	return notify_fail("你的目标不是活物！\n");
    if(!victim->is_fighting())
	return notify_fail("只有战斗中才能祭"+objname+"。\n");  
    if( (int)me->query("mana") < 100)
	return notify_fail("你的法力不够了！\n");
    msg=BLU+me->name()+"于百忙之中从怀中掏出一块"+objname+BLU"，念了几句咒语，";
    if (victim != me) msg+="指着$N";
    msg+="大喝一声「去！」\n";
    condition=determine_success(me,victim);
    switch(condition)
    {
      case 1:
	msg+=BLU"只见"+objname+BLU"化作一股黑烟，向$N"
		"裹去。待黑烟散尽时，$N已经不见了。\n"NOR;
	message_vision(msg, victim);
	if (userp(victim)) victim->move(victim->query("startroom"));
	else victim->move("/d/city/kezhan");
	tell_room(environment(victim), victim->name()+"的身影突然出现在一阵烟雾中。\n");
	me->start_busy(5);
	break;
      case 0:
	msg+=MAG"但"+objname+MAG"化作一阵青烟散去了。\n"NOR;
	message_vision(msg, victim);
	break;
    }
    me->set("mana", 0);
    me->set("sen",10); 
    destruct(this_object());
    return 1;
}
/************************************************************/
int determine_success(object me, object victim)
{
    int myspells, victimdx, condition;

    myspells=me->query_skill("spells");
    victimdx=victim->query("daoxing");
    if (!victim->is_busy())
	victimdx=victimdx/4;
    else victimdx=victimdx/2;

    myspells=(myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    myspells=myspells*victim->query_kar();

    if (random(myspells)>victimdx) condition=1;
    else condition=0;
    return condition;
}
/************************************************************/
