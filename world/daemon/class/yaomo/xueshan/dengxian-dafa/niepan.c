// 凤凰涅磐
//lestat for 雪山

#include <ansi.h>

int cast(object me, object target)
{
        int mymana=me->query("mana"), cost=100, cure;
	int jin, qi, neili, fali, shiwu, yinshui;
	string msg;

	if(me->is_busy())
		return notify_fail("你正忙着呢，过会儿再念咒吧！\n");
        if( time()-(int)me->query_temp("xiao_end") < 10 )
          return notify_fail("你刚浴火重生了！\n");
      if(me->query("family/family_name") != "大雪山"
      || me->query_skill("dengxian-dafa", 1) < 100)
              return notify_fail("你不是飞禽，无法浴火重生。\n");
      if(!me->is_fighting())
          return notify_fail("凤凰涅磐只能在战斗中使用！\n");
        if( mymana < cost*2 )
                return notify_fail("你的法力不够。\n");

//        if (cost<mymana/2) cost=mymana/2-1;
        if (cost<mymana/10) cost=mymana/10-1;

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )

		cost=cost/2;
		message_vision(BLU"\n$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着点燃红磷粉，咬破舌尖，一口"RED"鲜血"BLU"喷出。嗤嗤两声轻响，爆出几朵火花，"HIR"火花"BLU"忽地一暗，随即大为明亮。\n"NOR,me,target);
		message_vision(HIW"\n此时$N脸上已无半点血色，一口口鲜血不住向"RED"火焰"WHT"中吐去 ，火势越来越猛!!\n"NOR,me,target);
		message_vision(HIR"\n随即，$N念了几句咒。猛地身子急旋，如陀螺般连转了十多个圈子，接着大袖拂动，整个火焰堆陡地拨起，凌空燃烧，便如一座"RED"火墙"HIR"般，夹着排山倒海之势将$N吞没！\n"NOR,me,target);
		message_vision(HIR"\n但听一声凤鸣，一只"HIY"彩凤"HIR"从火焰中冲天而起，一片片羽毛从空中雪花般飘落，$N缓缓落下，全身上下焕然一新！\n"NOR,me,target);
		me->start_busy(random(8-me->query_kar()/5));

        me->add("mana", -cost);
        jin = me->query("max_sen");
        qi =me->query("max_kee");
        fali = me->query("max_mana");
        neili = me->query("max_force");
        shiwu = me->max_food_capacity();
        yinshui = me->max_water_capacity();
        me->set("eff_sen", jin);
        me->set("eff_kee", qi);
        me->set("sen", jin);
        me->set("kee", qi);
//        me->set("mana", fali);
//        me->set("force", neili);
        me->set("force", neili*2);
        me->set("food", shiwu);
        me->set("water", yinshui);
	me->set_temp("xiao_end",time());
        return 1;
}
