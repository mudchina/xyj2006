//modified by vikee 
//2000.10

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_tianlong(object,object);
int main(object me, string arg)
{
        object obj, guard_ob;
        string *killer, callname;

         if(me->query_temp("12gong/tianlong")!="done")
               return notify_fail("没有童虎的传授,你如何会用天龙?\n");

		 if( !wizardp(me) && environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

if( environment(me)->query("name")=="百花谷" )
 return notify_fail("乘人之危,不太好!\n");
        if( !arg )
                return notify_fail("你想对谁用天龙？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");
if (userp(obj))
                        return notify_fail("你想对玩家下毒手?\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj==me)
                return notify_fail("用 suicide -f指令会比较快:P。\n");
    
             if(obj->query("age")<=16 && userp(obj))
                return notify_fail("用天龙对付小孩子，你太没人性了!\n");
        // forbid to kill a player whose mudage <17 .here is added by vikee :P
        
   
        

    //    if(!valid_tianlong(me,obj,0)) return 0;

        callname = RANK_D->query_rude(obj);

        message_vision("\n$N对着$n喝道：「" 
                + callname + "！看我的绝招[天龙]！」\n\n", me, obj);        

       if (arg=="shura")
       {
		message_vision(HIY"\n\n\n只见$N身背后浮现出一条巨龙伸出龙爪紧紧抓住$n,冲向天空!\n\n"NOR, me, obj); 
         message("chat",HIY+"突然从山羊宫爆发两股强大的小宇宙,直冲九天,就像一颗流星缓缓消失在天际!\n"NOR,users());
		 obj->unconcious();
		 me->kill_ob(obj);
		 return 1;
	   }
        do_tianlong(me, obj);

        return 1;
}

void do_tianlong(object me, object obj)
{
        me->kill_ob(obj);
        if( !userp(obj) ){
                if(!obj->accept_kill(me) )
                obj->kill_ob(me);
        } else {
                obj->fight_ob(me);
                  tell_object(obj, HIR""+me->name()+"对你使用了绝招[天龙]\n"NOR);
              }
message_vision(HIY"\n\n\n只见$N身背后浮现出一条巨龙伸出龙爪紧紧抓住$n,只冲九天!\n\n"NOR, me, obj);
tell_object(obj,HIR"\n\n\n眼前狂风大作,吹的睁不开眼睛,耳边传来巨龙的怒吼.你不知道"+
"飞了多高,突然抓住你的巨龙爪子一松,你朝地面直坠了下去.........."NOR);
obj->unconcious();
me->delete_temp("12gong/tianlong");
}


/*int help(object me)
{
  write(@HELP
指令格式 : tianlong <人物>
 
绝招天龙,是黄金圣斗士元老,天秤座童虎的绝招,在通过黄金十二宫时可以用来完成'天龙架山羊'
    );
  return 1;
}
*/
