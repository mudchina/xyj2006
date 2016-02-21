// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// /cmds/usr/freeze.c
// FoF 00-5-29
// 冻结帐号 
// last motified by ammy@yszz  12/06/2000
// 加入巫师对在线及离线玩家的操作

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
    object ob,link_ob;
    string id,wiz_status;
    int day, hour, freeze_time;
    if(!arg || sscanf(arg,"%s %d day %d hour",id,day,hour) !=3 )       
        return notify_fail("指令格式：freeze <id> <n> day <n> hour\n");
    arg=lower_case(arg);
    if (!me->id(id)) {
          wiz_status = SECURITY_D->get_status(me);
          if( wiz_status != "(admin)" && wiz_status != "(arch)" && wiz_status != "(wizard)")
	        return notify_fail("只有 (wizard) 以上的巫师才能冻结或解冻其他玩家！\n");
     }
    if( day < 0 || hour < 0 ) return notify_fail("时间不能是负数！\n");
    freeze_time =day*24*60*60 + hour*60*60;
    if(freeze_time > 36*24*60*60 ) return notify_fail("冻结的时间太长了！\n");
    freeze_time +=time();
    ob=find_player(id);
    if(!ob)
    {
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() )
                return notify_fail("没有这个玩家。\n");
        else
        {
          ob->set("freeze_time",freeze_time);
          tell_object(me,ob->query("id") + "("+ob->query("name")
                + ")的账号已经冻结。自动解冻将在"+day+"天"+hour+"小时后! \n");
          log_file( "freeze_account.log", sprintf("%s %s(%s)冻结%s(%s)的账号!  \n 冻结时间为%d天%d小时. \n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id"),day,hour));
          ob->save();
          destruct(ob);
          return 1;
                }
        }
    if (!wizardp (me)){    
      if( ob->query("last_freeze_account") )
        if( time() - ob->query("last_freeze_account") < 60 )
            return notify_fail("帐号冻结失败！你刚刚才冻结过帐号。\n");
     }
    // LOGIN_OB 要做相应的改动，否则set("freeze_time", freeze_time)失败
    link_ob = ob->query_temp("link_ob");
    if( link_ob->set("freeze_time", freeze_time) && link_ob->save() ) {
          tell_object(me,ob->query("id") + "("+ob->query("name")
                + ")的账号已经冻结。自动解冻将在"+day+"天"+hour+"小时后! \n");
          log_file( "freeze_account.log", sprintf("%s %s(%s)冻结%s(%s)的账号!  \n 冻结时间为%d天%d小时. \n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id"),day,hour));
          ob->set("last_freeze_account", time());
          ob->save();
    } else
        write("帐号冻结失败！\n");
    return 1;
}

int help(object me)
{
    write("
"HIY"指令格式:"NOR" "HIM"freeze "HIR"<"HIW""BLINK"id"NOR""HIR"> <"HIW""BLINK"n"NOR""HIR">"HIW" day "HIR"<"HIW""BLINK"n"NOR""HIR"> "HIW"hour"NOR"

这个指令可以让你在一定时间内冻结自己的帐号，在帐号冻结期间
任何人都无法使用这个帐号登录，如果你不希望在自己离线期间被
别人盗用帐号，或者因为某些原因（例如学习工作紧张等）在一定
时间内不想登录，最好把自己的帐号冻结起来。
注意：冻结的时间就是现实中的时间，不能是负数，也不要太长。

"HIY"例如："HIW"freeze ammy 0 day 5 hour"NOR" \n 
");
    return 1;
}
