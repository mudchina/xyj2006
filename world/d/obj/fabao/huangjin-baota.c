
// Rainy
// 07/09/98
// can use 3 times.
//
// chance :
// 1/2 chance to hit a 1000y player with 2000 mana
// 1/2 chance to hit a 10000y player after improve.
//
// improve :
// (int)fabao->query("spi"), range from 2000 to 400000,
// so basically 5 times the chance to hit one.
// improve from 2000 to 400000 need about 8000 seconds.
// after each use, ("spi") will back to 3/4.

//------------------------------------------------------------------
//modified by weiqi, 07/31/98...refine settings, add functions
//fabao's spi is from 100 to 10000 in general,
//to match players with 100 years to 10000 years dx and 100 to 10000 fali.

//time needed: get 1 spi need input 50 mana, and wait 2 seconds, 
//so to get 10000 spi, need input 500*1000 mana, 
//and wait 20000 seconds~about 6 hours in the best case.

//damge: 100 + my_spi/5 - random(vic_mana/10) - vic_enchant*2;
//to a 2000 max_fali target(100 enchant), best case is 100+2000-200 = 1900
//worst case is 100+2000-400-600 = 1100
//to a 5000 max_fali target(250 enchant), best case  is 100+2000-500 = 1600
//worst case is 100+2000-1000-500 = 600
//to a 10000 max_fali target(enchant 500), best case is 100+2000-1000 = 1100
//worst case is 0.

//use once, power decrease to 50%
//------------------------------------------------------------------


#include <skill.h>
#include <ansi.h>

#define MAX_SPI 10000 
//basically, this corresponding to 10000 fali and 10000 years of dx
//later on we will use it to determine hit or not
#define MIN_SPI 100

inherit ITEM;
inherit F_UNIQUE;

string show_status();

void create()
{
	set_name("如意黄金宝塔", ({"huangjin baota", "baota", "ta", "fabao"}));
	set_weight(8000);
	if(clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long", "一座三十三层玲珑透剔舍利子如意黄金宝塔。\n");
		set("unit", "座");
		set("value", 100000);
		set("no_put",1);
		set("no_sell",1);
		set("unique", 1);
		set("replace_file", "/obj/money/gold");
		set("time_available", 3);
		set("spi", MIN_SPI);
	}
	set("is_monitored", 1);
	setup();
}

void init()
{
	check_owner();
	add_action("do_improve", "improve");
	add_action("do_addspi", "addspi"); //for wiz's convinience.
}

int do_addspi(string arg)
{
	object fabao = this_object();
	object me= this_player();

	if( !wizardp(me) ) return notify_fail("你不能使用这个指令。\n");
	if( !this_object()->id(arg) ) return notify_fail("你想设置哪个法宝的灵力？\n");

	//add 1/10 MAX_SPI each time...
	if( (int)fabao->query("spi") >= MAX_SPI )
		return notify_fail("这件法宝的灵力已经锻炼到了极限！\n");

	fabao->add("spi", MAX_SPI/10);
	if( (int)query("spi") > MAX_SPI ) set("spi", MAX_SPI);  
	tell_object(me, show_status());
	return 1;
}

int do_improve(string arg)
{
	object me= this_player();
	object fabao= this_object();
	int cost = 100;//now fix cost as 100
	
	if( me->is_busy()
	|| me->is_fighting()
	|| me->query_temp("pending/exercising"))
		return notify_fail("你正忙着呢．．．\n");
        
	if( environment(me)->query("no_fight")
	|| environment(me)->query("no_magic") )
		return notify_fail("这里不能锻炼法宝。\n");

	if( !this_object()->id(arg) ) return notify_fail("你想提高什么法宝的灵力？\n");;

	if( (int)me->query("mana") < cost )
		return notify_fail("你的法力太低，不能锻炼法宝。\n");

	if( (int)fabao->query("spi") >= MAX_SPI )
		return notify_fail("这件法宝的灵力已经锻炼到了极限！\n");

	message_vision(HIC"$N双手紧握着$n，口中念念有词，将自己的法力一点点的送了过去。\n"NOR, me, fabao);
	
	me->add("mana", -cost);
	fabao->add("spi", cost/50); //so 100 mana can get 2 spi for the fabao
	if( (int)query("spi") > MAX_SPI ) set("spi", MAX_SPI);  
	me->start_busy(cost/25);
	call_out("improved", cost/25, me); //get 1 spi need wait 2 seconds.

	return 1;
}

int improved(object me)
{
	object fabao = this_object();
	message_vision(HIC"\n$N手中的$n突然发出一阵红光，层层现佛，艳艳光华。\n"NOR, me, fabao);
	message_vision(HIC"$N面露喜色，长吐一口气站了起来。\n"NOR, me);
	tell_object(me, show_status());
	me->start_busy(1);
	return 1;
}	

string show_status()
{
	int i, percent;
	string status = this_object()->query("name") + "：";

	percent = 1 + query("spi")*25/MAX_SPI;
	if ( percent > 25 ) percent = 25;
	
	for(i=1; i<=25; i++) //
	{
		if( i <= percent ) status = status + "■";
		else status = status + "□";
	}

	status = status + "\n";

	return status;	 
}

int ji_ob(object victim)
{
	object fabao=this_object();
	object me=this_player();
	object where=environment(me);

	int my_spi;
	//from MIN_SPI to MAX_SPI(usually from 100 to 10000)

	int vic_enchant, vic_dx, vic_mana;

	int damage;

	if( me->is_busy() )
		return notify_fail("你正忙着呢，无法祭出如意黄金宝塔。\n");
	if( !victim )
		return notify_fail("你想祭的人不在这里。\n");
	if( where->query("no_magic") )
		return notify_fail("这里不能祭如意黄金宝塔。\n");
	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能祭如意黄金宝塔。\n");
	if( (int)me->query("mana") < 1000 )
		return notify_fail("你的法力不能控制如意黄金宝塔。\n");
	if( (int)me->query("sen") < 200 )
		return notify_fail("你现在神智不清，很难驾驭如意黄金宝塔。\n");


	message_vision(HIC"\n$N大喊一声“看塔！”，手一挥，祭出了$n。。。\n"NOR, me, fabao);
	message_vision(HIC"$n「呼」地一下飞到半空，发出玲珑七彩之光，层层现佛，艳艳光明。\n突然间光华闪出，如泰山压顶般向$N砸去。\n"NOR, victim, fabao);

	if( !victim->is_fighting(me) ) 
	{
		if( living(victim) ) 
		{
			if( userp(victim) ) 
				victim->fight_ob(me);
			else
				victim->kill_ob(me);
		}
		me->kill_ob(victim);
	}

	me->add("mana", -500);
	me->receive_damage("sen", 100);
	me->start_busy(1+random(3));

	my_spi = query("spi");
//   if (userp(me)) fabao->add("time_available",-1);
 fabao->add("time_available",-1);
	fabao->set("spi", my_spi/2);


//1st, compare dx, if victim dx enough, 躲闪
//2nd, compare fali, if victim fali enough, can 接收
//if no 躲闪 and 接收, a successful hit happens, consider damage now, 
//damage is determined by victim's enchant and current fali and fabao's spi
//...weiqi
	vic_mana = (int)victim->query("mana");
	vic_dx = (int)victim->query("daoxing");
	vic_enchant = (int)victim->query("mana_factor");

	if( random(vic_dx/1000) > my_spi ) // /1000 is to convert vic_dx to years
	{
		message_vision(HIC"\n$N猛地退了几退，$n顿时砸了个空。\n"NOR, victim, fabao);
	}
	else
	{//now 躲闪 does not happen, try 接收?
		if( random(vic_mana) > my_spi )
		{
			message_vision(HIC"\n$N大喝一声“收！”，只见$n光华大盛！但一闪再闪之下终于乖乖地飞到了$N手中。\n"NOR, victim, fabao);
			fabao->move(victim);
		}
		else
		{//now a hit should happen, let's consider damage
			damage = 0;
			damage = 100 + my_spi/5 - random(vic_mana/10) - vic_enchant*2;
			//here, my_spi usually 100-10000, so damage maybe upto 2000
			//vic_mana maybe upto 2*vic's max_mana. 
			//note, vic_enchant has no random(), so it's more important...

			if( damage < 0 ) damage = 0;
			if( damage > 2000 ) damage = 2000; 

			if( damage > 0 )
			{
				message_vision(HIC"\n$N躲闪不及，被如意黄金宝塔砸个正着！\n"NOR,victim);
				victim->receive_damage("kee", damage);
				victim->receive_wound("kee", damage/2);
				victim->receive_damage("sen", random(damage));
				victim->receive_wound("sen", random(damage/2));
				COMBAT_D->report_status(victim);
				COMBAT_D->report_sen_status(victim);
			}
			
		}
	}

	if( (int)fabao->query("time_available") < 1 ) 
	{
		message_vision("\n突然间$N发出一阵金芒冲上天去。\n", fabao);
		destruct(fabao);
	}

	return 1;
}

int ji (string target)
{
	object fabao = this_object ();
	object me = this_player();
	string name=fabao->query("name");
	object victim;

	if (!target)
		return notify_fail("你想对谁祭"+name+"？\n");

	victim=present(target,environment(me));
	return fabao->ji_ob(victim);
}

