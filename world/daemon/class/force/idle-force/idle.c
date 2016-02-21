#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill,howlong, damage, force,time;
               mapping action; 
        if (me->query_skill("idle-force",1)<80)
         return notify_fail("你的发呆大法还不够。\n");
        message_vision(HIC "\n$N使出发呆大法,痴痴的朝$n望去。\n"NOR,me);
        message_vision(HIC "\n$n一下惊呆了，当场昏迷.\n"NOR,me);
        command("rumor "+"听说$n被$N用发呆大法袭击成功！");
        howlong=1000-me->query_skill("idle-skill")*2;
        me->set_temp("pfm_idle",1);
        me->set("actions",action);
        me->reset_action();
        return 1;
}


int remove_ansi(object me,int strength)
{       
        me->delete_temp("pfm_idle");
message_vision(HIW"$N又可以施展发呆大法了！\n"NOR,me);  return 1;       

}

