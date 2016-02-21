//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"飞瀑"NOR);
        set("long",@LONG
在你面前是飞流直下三千尺的瀑布，见到这么长的瀑布，
你不由想去试试挥剑断水！
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"houshan",
        ]));
       set("objects", 
        ([ //sizeof() == 1
            __DIR__"npc/jian" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_huijian", "huijian");
}

int do_huijian(string arg)
{
        object room, ob;
        object me = this_player();
        int sk = me->query_skill("shushan-jianfa",1);
        if(me->query("family/family_name") != "蜀山剑派")
        {
        tell_object(me,"你感觉到力不从心。\n"); 
        return 1;
        }
        if(me->query("combat_exp") < (sk*sk*sk/10))
        {
        tell_object(me,"你的道行不够。\n");     
        return 1;
        }
        if(me->query("kee") < 50)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }
        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你必须先找一把剑才能挥剑断水。\n");

        message_vision("$N挥剑去断水，结果弄得个“挥剑断水水更流，全身湿透汗也流”。\n",me);
        me->add("kee",-30);
        if(me->query_skill("shushan-jianfa",1) > 249 )
        {
        tell_object(me,"你似乎不能在这里悟到什么了。\n");       
        return 1;
        }
        if((int)me->query_skill("mindsword", 1) > 99){
        tell_object(me,HIW"你似乎对挥剑断水有所领悟！\n你感觉到你的蜀山剑法在不断进步！\n"NOR);
        me->improve_skill("shushan-jianfa", random(me->query_int()*10) +1,0);
        if(!me->query("shushan/duanshui_master"))
        {
        if(random(100) < 3)
        me->add("shushan/duanshui",1);
        if(me->query("shushan/duanshui",1) > 99)
        {
        me->set("shushan/duanshui_master",1);
        tell_object(me,HIY"你在不知不觉间悟到了「断水无痕」的要领。\n"NOR);
        me->delete("shushan/duanshui");
        }
        }
        }
        else tell_object(me,HIY"也许你的心剑修为不够，你无法悟到什么。\n"NOR);
        return 1;
}                

