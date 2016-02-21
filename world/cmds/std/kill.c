#include <ansi.h>
#include "valid_kill.h";

//  inherit F_CLEAN_UP;
inherit SSERVER;
void do_kill(object,object);
int main(object me, string arg)
{
        object obj, guard_ob,target;
        string *killer, callname;
        int obj_level, me_level;
        string *vics;
        mapping killvic;

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
       if( environment(me)->query("short") == HIR"CS休息室"NOR )
             return notify_fail("你还是先呆着吧\n");
        if( !wizardp(me) && environment(me)->query("no_fight") && !obj->query("tongji/fanren") )
                return notify_fail("这里不准战斗。\n");
        //the followed is added by vikee
 if ( !("/cmds/usr/pkgame"->query_pk()) )
   {
            if(userp(obj) && obj->query("age")<16 && !wizardp(me))

                return notify_fail("本站暂时保护新手。\n");
 }
if ( (userp(me)) && (userp(obj)) )
{
if ( ((!me->query_temp("pkgame"))&&(obj->query_temp("pkgame"))) || ((me->query_temp("pkgame"))&&(!obj->query_temp("pkgame"))) )
 return notify_fail("比赛队员和非参赛玩家之间不能pk.\n");
}

        if(me->query("combat_exp")<50000 && userp(obj))
                return notify_fail("自己功夫没练好就想杀人？\n");

        if(me->query("daoxing")<50000 && userp(obj))
                return notify_fail("自己功夫没练好就想杀人？\n");       

        if(obj==me)
                return notify_fail("用 suicide 指令会比较快:P。\n");

    if(wizardp(obj)&&!wizardp(me)) 
       return notify_fail("杀巫师？还是考虑清楚吧！\n");
      if(!valid_kill(me,obj,0)) return 0;
         callname = RANK_D->query_rude(obj);
   /**********************************/
    killvic=obj->query_temp("kill/target");
    if(mapp(killvic)&&sizeof(killvic))
       vics = keys(killvic); 
    /*****************************************/
        
        message_vision("\n$N对着$n喝道：「" 
                + callname + "！今日不是你死就是我活！」\n\n", me, obj);        


        if(!me->is_fighting()&&userp(obj))
       if((vics&& member_array(me->query("id"),vics)==-1)||!vics )
                me->set_temp("kill/target/"+obj->query("id"),1); 
              if(me->is_fighting()&&userp(obj))
                {
                    target=offensive_target(me);
                     if(target!=obj)
                if((vics && member_array(me->query("id"),vics)==-1)||!vics)
                   me->set_temp("kill/target/"+obj->query("id"),1); 
               }
        if( obj->query_temp("protected")
          && objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
          && (string)guard_ob->query_temp("protect")==obj->query("id")
          && guard_ob!=me ) {

        message_vision(HIC"$N对着$n大声说：有我在此，不用担心！\n"NOR,guard_ob,obj);
                        message_vision(HIC"$N冲上前去挡住了$n的攻击。\n"NOR, guard_ob, me);
                        guard_ob->kill_ob(me);
                        me->kill_ob(guard_ob);
                }

        do_kill(me, obj);

        return 1;
}
void do_kill(object me, object obj)
{

        me->kill_ob(obj);
        if( !userp(obj) ){
        
                if(!obj->accept_kill(me) )
                obj->kill_ob(me);
				if((me->query("fangcun/panlong_longgong")=="begin")&&(me->query_temp("fangcun/panlong_longgong_longzhu")!="done")&&(obj->query("title")=="龙王九子之"))
                    obj->set_temp("longzhu_kill",me->query("id"));
                if((me->query("fangcun/panlong_hell_18")=="done")&&(me->query("fangcun/panlong_hell_longjin")=="begin")&&(obj->query("class")=="dragon"))
                    obj->set_temp("longjin_kill",me->query("id"));

        } else {
                obj->kill_ob(me);
                tell_object(obj, HIR "如果你要和" + me->name() 
                        + "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);

        }

}

int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且□试杀死对方，kill 和 fight 最大的
不同在于双方将会真刀实枪地打斗，也就是说，会真的受伤。由于 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对于一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

HELP
    );
    return 1;
}
