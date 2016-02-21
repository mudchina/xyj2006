// modified by vikee 2000.11
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;
#include <ansi.h>
string chinese_daoxing(int gain);
void create()
{
        set("short", HIG"祭祀厅"NOR);
        set("long", @LONG
      这是蜀山剑派祭祀的地方，正中间只有一个大炉，上面挂着多串佛珠。
炉前有祭祀桌，上面供放着许多祭祀的食物和香烛，供奉蜀山历届祖先。如果你
收服过妖怪，你可以上前祭拜(jibai)，以求祖先保佑你得道升仙。
LONG
        );
        set("item_desc", ([
                "化妖炉": @TEXT
用来对付低等妖魔的炉，低等妖魔被困在里面，不出一个时辰，就会尽失道行！
你可以在这里化妖，只要把妖怪(putin)，就可以啦。
TEXT        ]));
        set("exits", ([
                "south" : __DIR__"houdian",
        ]));
        set("objects", ([
                __DIR__"npc/laodao" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_jibai", "jibai");
}

int do_jibai(string arg)
{
        object room, ob;
        object me = this_player();
        message_vision("$N跪下来，向蜀山祖先祭拜。\n",me);
        if((int)me->query("shushan/reward") > 0){
        tell_object(me,HIW"因为你的诚心和积德，佛祖奖励你"+ chinese_daoxing((int)me->query("shushan/reward",1))+"道行和"
        +chinese_number((int)me->query("shushan/reward",1)/4 + 1)+"点潜能！\n你顿时觉得修行充实了许多！\n"NOR);
        me->add("combat_exp",(int)me->query("shushan/reward",1));
        me->add("potential",(int)me->query("shushan/reward",1)/4 +1);
        me->add("shushan/reward_got",(int)me->query("shushan/reward",1));
        me->set("shushan/reward",0);
        }
        else tell_object(me,HIY"只要你多行善积德，佛祖一定会奖励你。\n"NOR);
        return 1;
}                

string chinese_daoxing(int gain)
{
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"年";
             if(day) str=str+chinese_number(day)+"天";
             if(hour) str=str+chinese_number(hour)+"时辰";

             return str;
}