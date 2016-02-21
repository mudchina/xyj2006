// nophase.c 无色无相
// /daemon/class/sanxian/mysticism/nophase.c
// writted by mind 2001/2

inherit SSERVER;
#include <ansi.h>

int cast(object me)
{
        int howlong;
        int spell;
        spell=me->query_skill("spells")/2 + me->query_skill("mysticism");
        if(!me->query("m_success/变色龙"))
                return notify_fail("你还没学会无色无相。。。。\n");
        if( (string)me->query("family/family_name")!="三界散仙")
                return notify_fail("你非散仙，无缘修习无色无相。\n");
        if(spell < 100)
                return notify_fail("你法术修为太浅。\n");

        if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

        if (me->query("betrayer") || me->query("betray/count"))
           return notify_fail("三心二意者很难领悟散仙的精髓所在。\n");
        
        
        message_vision("$N看了看四周的环境，默运起从变色龙悟得的无色无相法术。\n", me);

        if( random(me->query("max_mana")) < 100 ) {
                me->add("mana",-(int)me->query_skill("spells"));
                me->receive_damage("sen",10);
                message("vision", "但是什么也没有发生。\n", environment(me));
                return 5+random(5);
        }

        me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 20);

        howlong = 10 + random((me->query_skill("spells") -100));
        if (!me->query("env/invisibility"))
                call_out("free", howlong, me, howlong);
        me->set_temp("nophasetime", howlong+(int)me->query_temp("nophasetime"));

        me->set("env/invisibility", 1);
        me->set_temp("no_heal_up/nophase",1);
        
        message_vision(HIB"\n凭空消失了$N，踪迹皆无。\n\n"NOR, me);
        
        return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
        if (!user->query("env/invisibility")) return;
        if (user->query_temp("nophasetime") - howlong) {
                user->set_temp("nophasetime", 
                        user->query_temp("nophasetime") - howlong);
                call_out("free", user->query_temp("nophasetime"), 
                        user, user->query_temp("nophasetime"));
                return;
                }
        user->delete_temp("nophasetime");
        user->set("env/invisibility", 0);      
        user->save();
        message_vision(HIB"\n凭空又多了$N身形。\n\n"NOR, user);
        user->delete_temp("no_heal_up/nophase");
        return;
}


