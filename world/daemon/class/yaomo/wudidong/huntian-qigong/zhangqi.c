
// roar.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        object *ob;
        int i, skill, damage;
      if ( (string)me->query("class") != "yaomo")
          return notify_fail("你不是妖魔之身,无法使用瘴气!!\n");

//      if(!me->is_fighting())
  //        return notify_fail("「桃花瘴」只能在战斗中才能使用!\n");


    if( (int)me->query("max_force") < 1200)
    return notify_fail("你的内力太弱,不足以喷出「桃花瘴」.\n");
    if( (int)me->query("force") < 500 )
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("force");

        me->add("force", -150);
        me->receive_damage("kee", 10);

    me->start_busy(2+random(2));
        message_vision(
  HIR "$N深深地吸了一口气,突然吐出一团五彩斑斓的桃花瘴!!\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                        if( interactive(ob[i]) ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;
                
        damage = skill*2 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("sen", damage);
 tell_object(ob[i], HIR"你只觉一阵天旋地转,差点没晕了过去.\n"NOR);
                ob[i]->set_temp("last_damage_from",me);
                }
                
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
        }

        return 1;
}

