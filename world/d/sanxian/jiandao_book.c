// jiandao_book剑道遗篇
// writted by mind

#include <ansi.h>
inherit ITEM;



void create()
{
        set_name("剑道遗篇",({"jiandao yipian","yipian","book"}));
        set("unit","卷");
        set("long","一卷记载着「剑道」中山夫子关于修炼剑道的残缺竹编。\n");
        set("no_give",1);
        setup();
}
void init()
{
        add_action("do_study","study");
        add_action("do_study","du");
}
int do_study(string arg)
{
        int k;
        object me;
        string str;
        
        me=this_player();
        if( !living(me))        return 0;
        if (!id(arg))
        return 0;
        if(me->query_skill("spysword",1)<50||!me->query_skill("spysword",1))
        {
        tell_object(me,"你的「刺客剑法」功力不够，还没有领悟「剑道」呢。\n");
        return 1;
        }
        k=me->query("old_flag/jiandao");
        if(!k||k==0)    k=3;
        if(k==10)       
        {
        tell_object(me,"从如此残破的竹编上，你领悟的「剑道」已达到最高境界了，再研究它也没用啦。\n");
                return 1;
        }
        message_vision("$N正仔细地阅读，专研「剑道」的精髓要旨。\n",me);
        if((me->query_skill("literate",1)/2)<50+(k-2)*5)
        {
        tell_object(me,"以你当前的领悟力还难以理解更深的「剑道」。\n");
                return 1;
        }
        if(random(me->query_kar())<25)
        {
        tell_object(me,"你好象对「剑道」有所理解，但又不敢肯定。\n");
                return 1;
        }
        tell_object(me,HIW"你对「剑道」的理解已经进入第"+chinese_number(k)+"层境界！\n"NOR);
        str=me->name()+"对「剑道」的理解已经进入第"+chinese_number(k)+"层境界！";
        message("channel:rumor",HIM"【惊天谣传】某人："+str+"\n"NOR,users());
        k=k+1;
         me->set("old_flag/jiandao",k);
        return 1;
}

