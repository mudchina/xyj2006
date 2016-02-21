#include <ansi.h>
inherit F_DBASE;
inherit SSERVER;
int cast(object me, object target)
{
        int skill_spells, skill_dodge, dodge_amount,howlong;
        skill_dodge = me->query_skill("dodge");            
        if (skill_dodge<100) return notify_fail("你的轻功还不够高明，变了蝙蝠也飞不起来。\n");
        skill_spells=me->query_skill("spells");        
        if (skill_spells<100) return notify_fail("你的妖法不够纯熟。\n");
if( (int)me->query("mana") < 100 )      
                return notify_fail("你的法力不够。\n");
        if (me->query("sen")<100)
              return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("wdd_powerup") )
                return notify_fail("你已经在运功中了。\n");
//        if (!me->query_temp("wdd_drink_hulu"))
//           return notify_fail("你好久没偷油吃了，变不成蝙蝠。\n");
        me->add("mana", -50);
        me->add("sen",-50);
//        me->delete_temp("wdd_drink_hulu");
        message_vision(HIB"$N嘴里念念有辞，突然肩膀上长出了一对翅膀，变成了一只蝙蝠！\n"NOR,me);
        dodge_amount=me->query_skill("kugu-blade",1)/2; 
        me->add_temp("apply/dodge",dodge_amount);  
        me->set_temp("wdd_powerup", 1);
        me->set_temp("wdd_limbs",me->query("limbs"));
        me->set("limbs",({
  "头部",  "颈部", "胸口",  "后心",  "左肩",  "右肩",  "左臂", "右臂",
  "左手",  "右手", "腰间",  "小腹",  "左腿",  "右腿",  "左脚", "右脚",
  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",  "翅膀",
}));
        howlong=me->query_skill("yaofa",1)/5+5+random(5);
        if (howlong>60) howlong=60;
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, dodge_amount:), howlong);
         return 1;
}
void remove_effect(object me, int dodge_amount)
{
        me->add_temp("apply/dodge", -dodge_amount);
        me->delete_temp("wdd_powerup");
        me->set("limbs",me->query_temp("wdd_limbs"));
        message_vision(HIB"$N渐感浑身难受，摇了摇脑袋，现出了原形。\n"NOR,me);
}
