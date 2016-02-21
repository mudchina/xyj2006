// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// arrest.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if((int)me->query_skill("spells") < 200)
                return notify_fail("你还没学会召唤黄巾力士。。。\n");

        if( me->query("family/family_name")!="昆仑山玉虚洞")
                return notify_fail("你不是昆仑山玉虚洞门下，黄巾力士是不会来的。\n");
        if( me->query("faith")<100)
                return notify_fail("以你在昆仑山玉虚洞的名望，黄巾力士是不会听你的。\n");
        if( me->is_fighting() )
                return notify_fail("你正在打架呢！\n");
        if( me->is_busy() )
                return notify_fail("你正在忙呢！\n");
                
        if((int)me->query("mana") < 1200 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你无法集中精力！\n");
        write("你要抓谁？");        
        input_to( (: call_other, __FILE__, "select_other", me:));
        return 5+random(2);        
}

void select_other(object me,string arg)
{ 
        string msg;
        int ap, dp,success;
        object target;
        
        if(!arg||arg=="")return;        
                
       msg = HIC
        "$N口中念了句咒文，朝空中一指：黄巾力士何在！\n" 
        NOR;
        
        message_vision(msg, me);        
    if(!objectp(target = find_living(arg))||!environment(target)){
            tell_room(environment(me),"半空中现出一朵金色云彩，一个黄巾力士拱手行礼：禀法主，找不到这个人！\n");
            return;
        }
        msg = HIC
        "速去将$n抓来！\n半空中现出一朵金色云彩，一个浑身金甲的黄巾力士现出身形：是！然后就风驰电掣般地去了。\n"
        NOR;

        message_vision(msg,me,target);
      
        me->add("mana", -600);
        me->receive_damage("sen", 30);

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
        if( ap < dp ) success = 0;
        //here we compared exp and spells level. 
        //note: has nothing to do with target's spells level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
        if( ap < dp ) success = 0;
        //here we compared max_mana.

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        if( ap < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.

      if(success == 1 ){
          tell_room(environment(target),"空中伸出一只大手将"+target->query("name")+"抓走了。\n");       
          target->move(environment(me));
          msg =  HIR "不一会儿，金色云彩陡现，黄巾力士将$n往地上一扔，把$n摔了个头晕脑胀\n" NOR;
          message_vision(msg,me,target);
          me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(1+random(2));
      }       
      else {
      msg =  HIR "不一会儿，半空传来黄巾力士大叫：请法主赎罪，我无法抓获$n！\n" NOR;
         message_vision(msg,me,target);         
         me->start_busy(5);
      } 
}

