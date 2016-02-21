// dtask.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{       object ob;
        
        seteuid(getuid(me));
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("您要察看谁的状态？\n");
        } 
		else return notify_fail("只有巫师才可以察看别人的状态。\n");
        
        printf("　　 ┃ 难度一 ┃ 难度二 ┃ 难度三 ┃ 获得潜能 ┃ 获得武学 ┃ 获得道行 \n");
        printf("杀妖 ┃%8|d┃%8|d┃%8|d┃%10|d┃%10|d┃%d \n",
              ob->query("rulaitask_log/kill1"),  ob->query("rulaitask_log/kill2"),     
              ob->query("rulaitask_log/kill3"),  ob->query("rulaitask_log/kill_potential"),
              ob->query("rulaitask_log/kill_combat"),
              ob->query("rulaitask_log/kill_daoxing"));
        printf("擒妖 ┃%8|d┃%8|d┃%8|d┃%10|d┃%10|d┃%d \n",
              ob->query("rulaitask_log/arrest1"),  ob->query("rulaitask_log/arrest2"),     
              ob->query("rulaitask_log/arrest3"),  ob->query("rulaitask_log/arrest_potential"),
              ob->query("rulaitask_log/arrest_combat"),
              ob->query("rulaitask_log/arrest_daoxing"));
        printf("劝妖 ┃%8|d┃%8|d┃%8|d┃%10|d┃%10|d┃%d \n",
              ob->query("rulaitask_log/persuade1"),  ob->query("rulaitask_log/persuade2"),     
              ob->query("rulaitask_log/persuade3"),  ob->query("rulaitask_log/persuade_potential"),
              ob->query("rulaitask_log/persuade_combat"),
              ob->query("rulaitask_log/persuade_daoxing"));
        printf("降妖 ┃%8|d┃%8|d┃%8|d┃%10|d┃%10|d┃%d \n",
              ob->query("rulaitask_log/fight1"),  ob->query("rulaitask_log/fight2"),     
              ob->query("rulaitask_log/fight3"),  ob->query("rulaitask_log/fight_potential"),
              ob->query("rulaitask_log/fight_combat"),
              ob->query("rulaitask_log/fight_daoxing"));
        printf("殉职次数： %d\n",ob->query("rulaitask_log/die"));
        
        
        
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: dtask

这个指令让你知道你做如来任务的统计情况。

HELP
    );
    return 1;
}

