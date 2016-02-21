#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//yudian
inherit SSERVER;
//inherit F_SSERVER

//int valid_enable(string usage) { return usage=="array"; }

//int form_array(object me)
int perform(object me, object target)
{
        object *member,ob, weapon;
        int i,j,n;
        int max,min,skill;
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("你不是龙宫弟子怎么戏珠啊！\n");
        member = me->query_team();
        if( sizeof(member) != 2 )
                return notify_fail("一条龙怎么戏？\n");

        j=sizeof (member);
        for (i=0;i<j;i++)
        {
                ob=member[i];
                if (!ob||!living(ob)||!ob->is_character())
                {
                        return notify_fail("你想和谁一齐使用双龙戏珠？\n");
                }
                if (ob->query_temp("array/name"))
                {
                        return notify_fail("双龙合体了。\n");
                }
                if (environment(me)!=environment(ob))
                {
                        return notify_fail("人数不够两人。\n");
                }
                if (!ob->query_skill("fengbo-cha",1))
                {
                        return notify_fail(ob->name()+"还不会风波叉呢！\n");
                }
                if (ob->is_ghost())
                {
                        return notify_fail("只有阳间的人才能再现双龙合体。\n");
                }

                if( (int)ob->query("max_force") < 50 )
                        return notify_fail(ob->query("name")+"的内力不够。\n");

                if( (string)ob->query_skill_mapped("force")!= "dragonforce")
                        return notify_fail(ob->query("name")+"没有使用龙神心法。\n");

                if( !(weapon = ob->query_temp("weapon"))
                ||      (string)weapon->query("skill_type") != "fork" )
                        return notify_fail(ob->query("name")+"必须拿把叉做武器。\n");

                if( (int)ob->query_skill("fengbo-cha",1)<30)
                        return notify_fail(ob->query("name")+"的风波叉还不够熟练。\n");

                if( (string)ob->query_skill_mapped("fork")!="fengbo-cha")
                        return notify_fail(ob->query("name")+"必须使用风波叉。\n");
        }

//get the average array skill of the team
        n=0;
        for (i=0;i<j;i++)
        {
                ob=member[i];

                n+=(int)ob->query_skill("fengbo-cha",1);
        }
        n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
        max=member[0]->query_skill("fengbo-cha",1);
        min=max;
        for (i=0;i<j;i++)
        {
                skill=member[i]->query_skill("fengbo-cha",1);
                if(skill>max)
                        max=skill;
                else if(skill<min)
                        min=skill;
        }

//and the me is important
        n += me->query_skill("fengbo-cha", 1) ;
        n /= max - min + 1;
        for (i=0;i<j;i++)
        {
                ob=member[i];

                ob->set_temp("no_quit",1);

                ob->set_temp("array/name","fengbo-cha");
                ob->set_temp("array/level",n);

                ob->add_temp("apply/attack",n);
                ob->add_temp("apply/defense", n);
                ob->add_temp("apply/damage",n);
                ob->add_temp("apply/armor", n);
        }
        message_vision( HIG "$N与$N两条飞龙遥飞九天，双龙合体了！\n" NOR, me);
        return 1;
}

int dismiss_array(object person)
{
        int i,j,n;
        object *member,ob;

        member=person->query_team();
        j=sizeof(member);
        n=person->query_temp("array/level");
        for (i=0;i<j;i++)

        {
                ob=member[i];
                ob->delete_temp("array");
                ob->add_temp("apply/attack",-n);
                ob->add_temp("apply/damage",-n);
                ob->add_temp("apply/defense",-n);
                ob->add_temp("apply/armor", -n);
                tell_object(ob,"双龙离位！\n");
        }
}

//if the me kills enemy, then all members in the array kill enemy
int array_kill(object me, object enemy)
{
        object *member, ob;
        int i,j;
        member=me->query_team();
        j=sizeof(member);

        for(i=0;i<j;i++) {
                ob=member[i];
                ob->kill_ob(enemy);
        }


        return 1;
}



int effective_level() { return 10;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}

