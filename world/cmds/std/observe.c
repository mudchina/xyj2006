// observe.c
// mon 1/4/97, msg_exp by crab.

#include <ansi.h>

int main(object me, string arg)
{
    string *msg_expression = ({
        "脸上露出愉快的微笑。",
        "正躲在一边幸灾乐祸地笑。",
        "脸上露出狡诈的神情，大概又想到了什么坏主意了。",
        "正在绷着个脸扮酷。",
        "捧着肚子笑得前仰后合。",
        "眉头紧锁，不知在想什么心事。",
        "正托着腮帮子作沉思状。",
        "咬牙切齿，一副愤愤不平的样子。",
        "一脸的迷茫，不知道周围发生了什么事。",
        "正在咧着嘴傻乐。",
        "正作天真状。",
        "正在闷闷不乐。",
        "骄傲地昂着头，满脸不屑的神情。",
        "痛苦得呲牙咧嘴，大概是牙痛得厉害。",
        "正强颜欢笑，但掩饰不住心里的哀伤。",
        "正在眉飞色舞。",
        "一脸的尴尬相。",
        "脸上露出灿烂的笑容。",
        "笑得比哭还难看。",
        "正强忍着不让自己哭出来。",
        "媚眼如丝。",
        "正作小鸟依人状。",
        "开怀大笑，露出满嘴的金牙。",
});

     int size=sizeof(msg_expression);
     int spellme,spellwho,know;
     object who;
     string str;

     if (!arg || !objectp(who=present(arg,environment(me))) ||
	 !living(who))
	 return notify_fail("你想查看谁？\n");
     if (who==me) return notify_fail("看你自己？\n");
     
     if (me->query("mana")<100)
	 return notify_fail("你的法力不足。\n");
     me->add("mana",-50);

     spellme=me->query_skill("spells");
     spellwho=who->query_skill("spells");

     if (random(20)<((spellme-spellwho)/10+10) && 
	 who->name()!=who->query("name") &&
	 who->query_temp("d_mana")>0) {
       str="却见"+who->query("name");
       know=1;
     }
     else {
       str="只见"+who->name();
       know=0;
     }

     if (random(3)==1)
       tell_object(who, "你一抬头，发现"+me->name()+
         "正把一道锐利的目光向你投来。\n");
     write("你微一凝神，向"+who->name()+"细细打量过去，"
       +str+msg_expression[random(size)]+"\n\n");
    
     if(know==1&&who->query_temp("d_mana")>0) {
       write("\n你要运用法力迫使"+who->name()+
         "现出本形吗？(y/n)[n]");
       input_to("do_force",me,who);
     }

     return 1;
}
	 
void do_force(string yn,object me,object who)
{    
     if(!objectp(present(who,environment(me)))) {
       write("你的目标已经不在了。\n");
       return;
     }

     if( yn[0]=='y' || yn[0]=='Y' ) {
       if(me->query("mana")<=100) {
         write("你现在的法力太低了。\n");
	 return;
       } else {
         me->add("mana",-100);
         message_vision("$N朝$n大喝一声："+RANK_D->query_rude(who)+
         "！快现原形！\n",me,who);
         if(random(2)==0&&who->query_temp("d_mana")>0) {
	   int mana=who->query("mana");
	     
	   mana-=200;
	   if(mana<0) mana=0;
	   who->set("mana", mana);

           message_vision("只见$N"+
           "浑身松软，瘫倒在地．．．却果然正是"+who->query("name")+"！\n",who);
            who->delete_temp("spellslevel");
            who->delete_temp("d_mana");
            who->delete_temp("apply/name");
            who->delete_temp("apply/id");
            who->delete_temp("apply/short");
            who->delete_temp("apply/long"); 
	    who->delete_temp("no_heal_up/bian");
         }
     }
   }
   return;
}

int help(object me)
{
      write(@HELP

指令格式 ： observe <人物> 或
	    observe <人物> [ 2 | 3 | ...] 当有多个同名人物时。

这个指令让你运用法术来观察别的人物，如果你的法术高强，则
可能识破别人的变身术。

其他相关指令： bian
HELP
     );
     return 1;
}


