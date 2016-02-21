// breakup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int breaking(object me);
int halt_breaking(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int exercise_cost;
        object where;
        int maxneili;

        seteuid(getuid());
        where = environment(me);
        
        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

        if (me->query("breakup"))
                return notify_fail("你已经打通了任督二脉了，似乎没有必要再来一次。\n");

/*        if (wizardp(me))
                return notify_fail("巫师也要打通任督二脉？是不是烧得慌？\n");*/

        if (! where->query("no_fight"))
                return notify_fail("在这里打通任督二脉？不太安全吧？\n");

        if (! where->query("sleep_room"))
                return notify_fail("你得找一个能够休息的地方闭关修行。\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if (me->query("potential") < 500)
                return notify_fail("你的潜能不够，没法闭关修行以打通任督二脉。\n");

        if ((int)me->query("kee") * 100 / me->query("max_kee") < 90)
                return notify_fail("你现在的气太少了，无法静心闭关。\n");

        if ((int)me->query("sen") * 100 / me->query("max_sen") < 90)
                return notify_fail("你现在的精太少了，无法静心闭关。\n");

        if ((int)me->query("force") < 3000)
                return notify_fail("你觉得内力颇有不足，看来目前还难以"
                                   "打通任督二脉。\n");

        if ((int)me->query("force") * 100 / me->query("max_force") < 90)
                return notify_fail("你现在的内力太少了，无法静心闭关。\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("你觉得自己的内功火候还有限，看来需"
                                   "要先锻炼好内功才行。\n");

        message_vision("$N盘膝坐下，开始冥神运功，闭关修行。\n", me);
        me->set("startroom", base_name(where));
        me->set("doing", "breakup");
        me->set_temp("biguan", 1);
        
        me->start_busy(10);
                   
        CHANNEL_D->do_channel(this_object(), "rumor",
                              sprintf("%s%s(%s)开始闭关修行，试图打通任督二脉。",
                              "",me->name(1), me->query("id")));
        if (call_out("breaking", 10, me) && !me->query("breakup"))
                call_out("breaking", 10, me);
        return 1;
}

int continue_breaking(object me)
{
        me->start_busy(60);
        
        tell_object(me, HIR "\n你继续闭关修行以打通任督二脉...\n" NOR);
        return 1;
}

private void stop_breaking(object me)
{
        if (! interactive(me))
        {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
        }
}

int breaking(object me)
{
        string msg;

        if (me->query("potential") <= 500)
        {
                tell_object(me, "你的潜能耗尽了。\n");
                message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("听说%s(%s)闭关结束，似乎没有太大的进展。",
                                      me->name(1), me->query("id")));
                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        call_out("user_quit", 0, me);
                }

                return 0;
        }

        me->add("potential",-1);

        if (random(10))
        { 
              call_out("breaking", 10, me);
              return 1;
        }       
        if (random(100) < me->query("con") && !me->query("breakup"))
        {
                message_vision(HIW "只见$N" HIW "头上白雾腾腾、浑身"
                               "如同笼罩在云中，看来已经到了三花聚顶、"
                               "五气朝元、龙虎相济、天人交会的紧要关头！\n" NOR, me);
                tell_object(me, HIR "你觉得内力在丹田源源而生，不断"
                            "冲击诸处大穴，浑身燥热难当，几欲大声呼喊。\n" NOR);
                message_vision(HIC "突然$N" HIC "大喝一声，一股无形气浪"
                               "陡然散布开来，四周空气登时变得燥热。\n" NOR, me);
                tell_object(me, HIG "你顿时觉得浑身一阵轻松，一股清凉之意油然"
                            "而起，心灵一片空明，内力没有丝毫阻滞，舒泰之极。\n" NOR);
                me->set_temp("biguan", 0);
                me->set("breakup", 1);
                CHANNEL_D->do_channel(this_object(), "rumor",
                                      sprintf("听说%s(%s)经过闭关苦修，终于打通"
                                              "了任督二脉，窥视到了无上的武学境界。",
                                      me->name(1), me->query("id")));
                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 500000);
            me->add("max_kee",1000);
            me->add("eff_kee",1000);
			me->add("max_sen",1000);
            me->add("eff_sen",1000);
//                CHAR_D->setup_char(me);
                stop_breaking(me);
                return 0;
        }

        switch (random(5))
        {
        case 0:
                msg = "你默默运转内力，隐隐有些感觉。\n";
                me->start_busy(5);
                break;

        case 1:
                msg = "你将内力运出丹田，过紫宫、入泥丸、透十二重楼，遍布奇筋八脉，然后收回丹田。\n";
                me->start_busy(5);
                break;

        case 2:
                msg = "你将内力运经诸穴，抵四肢百赅，然后又回收丹田。\n";
                me->start_busy(5);
                break;

        case 3:
                msg = "你在丹田中不断积蓄内力，只觉得浑身燥热。\n";
                me->start_busy(5);
                break;

        default:
                msg = "你缓缓呼吸吐纳，将空气中水露皆收为己用。\n";
                me->start_busy(5);
                break;
        }

        tell_object(me, msg);
        call_out("breaking", 5, me);
        return 1;
}

int halt_breaking(object me)
{
//        CLOSE_D->user_opened(me);
        tell_object(me, "你中止了闭关。\n");
        message_vision(HIY "$N" HIY "轻轻叹了一口气，缓缓的睁开眼。\n\n" NOR, me);
                        me->set_temp("biguan", 0);
//        me->add("potential", me->query("potential")/ 2);
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + me->name(1) +
                              "闭关中途突然复出。");
        return 1;
}

private void user_quit(object me)
{
        if (! me || interactive(me))
                return;
      
        me->force_me("quit");
}

int help(object me)
{
        write(@HELP
指令格式 : biguan

闭关修行以打通任督二脉，需要非常深厚的内力和内功功底才能做到。
而且会消耗潜能。一旦打通了任督二脉可以同时扩展精、气、精力、
内力的上限。

HELP );
        return 1;
}

