// time.c

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
        
        if(ob->query("rulaitask/accomplish")) 
              { write("你刚刚完成了一个难度"+chinese_number(ob->query("rulaitask/level"))+"的"+ob->query("rulaitask/kind")+"妖任务。\n");
                write("你今天已经拿了"+chinese_number(ob->query("rulaitask/oneday"))+"个任务。\n");
                return 1;
              }
                      
        else if(ob->query("rulaitask/fail")) 
              { write("你任务失败了。\n");
                write("你今天已经拿了"+chinese_number(ob->query("rulaitask/oneday"))+"个任务。\n");
                return 1;
              }
              
        else if(!ob->query("rulaitask/get")) 
              { write("你没有任务在身。\n");
                write("你今天已经拿了"+chinese_number(ob->query("rulaitask/oneday"))+"个任务。\n");
                return 1;
              }      
              
        else if(!ob->query("rulaitask/guai")) 
              { write("如来佛已经出手收了你的妖怪。\n");
                write("你今天已经拿了"+chinese_number(ob->query("rulaitask/oneday"))+"个任务。\n");
                return 1;
              }
        
                                  
	write("你现在的任务是" + ob->query("rulaitask/kind")+"妖,"+ob->query("rulaitask/where")+"。\n");
	write("难度：" + chinese_number(ob->query("rulaitask/level"))+"\n");
	write("你今天已经拿了"+chinese_number(ob->query("rulaitask/oneday"))+"个任务。\n");
	if (wizardp(me)) 
	      printf("妖怪：%O\n",ob->query("rulaitask/guai"));
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: ctask

这个指令让你知道你现在的如来任务。

HELP
    );
    return 1;
}
 

