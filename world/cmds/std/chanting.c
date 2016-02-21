// xiudao.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void finish(object me,int dx_gain, int pot_gain);

int main(object me, string arg)
{
	object where;
	int level,time,dx_gain,pot_gain,constant;

	where=environment(me);

	if(where->query("no_fight") || where->query("no_magic") )
	     return notify_fail("安全区内禁止练功。\n");
	
	if (!where->query("jingzuo_room"))
		return notify_fail("此处不宜静坐修练！\n");

	if ( (int)me->query_skill("buddhism") < 20 ) 
                return notify_fail("你的大乘佛法修为太低，不能行功修炼！\n");
	
 if( (string)me->query("bonze/class")!="bonze") 
		return notify_fail("你又没有出家，诵什么经哪！\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中还要禅听？\n");

	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
		return notify_fail("你现在神智不清，再炼恐怕要走火入魔！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
		return notify_fail("你现在体力不够，再练就要累死了！\n");
	
	if( (int)me->query("water") < 10 )
		return notify_fail("你现在口干舌燥，还是歇歇吧。\n");

	level=(int)me->query_skill("buddhism",1);
	time= level/20 + random(20);
// time=level of buddhism/2, max 60-70 seconds.
	constant= level/10 + 15;
// not the real constang, divid by 25. the constant is from 17/25-1.
//	dx_gain= (level/5)*(k/25) is the formula, dx_gain=level/4.
//	so max. 1 minutes, about 20-25 dx. that's about 1.2k-1.5k/h
//	also a little random. (that's for a player with 100 level)
//	maybe a little high?
	dx_gain= (level*constant)/125;
        dx_gain= dx_gain/2 + random(dx_gain) + random((int)me->query("spi")/2) + 1;
        if( dx_gain > 50 ){
                dx_gain=40 +random(10);
	}
//	pot_gain=time/10, so each hour 400-500 dx.
        pot_gain= time/10 + random((int)me->query("int")) + 1;

	message_vision(HIY "$N席地而坐，双目微闭，口中轻声诵起了经文。\n" NOR, me);
	me->start_busy(time);
	call_out("finish",time, me, dx_gain,pot_gain);
	return 1;
}

void finish(object me,int dx_gain, int pot_gain)
{	int buddhism;
	string *msg=({
		"多欲为苦，生死疲劳，从贪欲起；少欲无为，身心自在。",
		"懈怠坠落，常行精进，破烦恼恶，摧伏四魔，出阴界狱。",
		"愚痴生死，菩萨常念，广学多闻，增长智慧，成就辩才，教化一切，悉以大乐。",
		"贫苦多怨，横结恶缘，菩萨布施，等念怨亲，不念旧恶，不憎恶人。",
		"生死炽燃，苦恼无量，发大乘心，普济一切。",
		"愿代众生，受无量苦，令诸众生，毕竟大乐。",
		"愿以此功德，庄严佛净土，上报四重恩，下济三途苦。",
		"若有见闻者，悉发菩提心，常行菩萨道，广度诸有情。",
		});
	message_vision(HIY "$N轻声念道："+msg[random(sizeof(msg))]+"\n" NOR, me);
	message_vision(HIY "$N缓缓睁开眼睛，长舒一口气站了起来。\n" NOR, me);

	me->add("daoxing", dx_gain);
	tell_object(me, HIC "你的道行增加了" + chinese_number(dx_gain*3) + "时辰！\n" NOR);
	me->add("buddhism/dx", dx_gain); 
        if ((me->query("potential") - me->query("learned_points")) < 1000000){
                me->add("potential", pot_gain);
		me->add("buddhism/pot", pot_gain);
		tell_object(me, HIC "你的潜能增加了" + chinese_number(pot_gain) + "点！\n" NOR);
	}

//        if (me->query("water") >= pot_gain) me->add("water",-pot_gain*2);
//        else me->set("water", 0);

	me->receive_damage("sen", me->query("int"));
	me->receive_damage("kee", me->query("int"));
	buddhism=random(dx_gain*3);
	me->improve_skill("buddhism", buddhism, 1);
	tell_object(me, HIC "你的大成佛法增加了" + chinese_number(buddhism) + "点！\n" NOR);
	me->start_busy(1);
}

int help(object me)
{
        write(@HELP
指令格式 : chanting

诵经修炼以提高道行。
HELP
        );
        return 1;
}
