// qkill.c
// tomcat
// 查询当前的灭妖任务

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string yaos ,yaos_status;
	int yaos_num,t ;
	
        if (!me->query_temp("mieyao/ob")){
            write("\n你目前没有灭妖任务\n");
            return 1;
           }  
	yaos = me->query("mieyao/name");
	yaos_num = me->query_temp("mieyao/level"); 
	yaos_status = "已经完成";

         if( (t=(int)me->query("mieyao/time_start")) &&
		!me->query("mieyao/done")) {
	    if(t<=time() &&
		    time()<t+1800) {
		yaos_status="没有完成"; }}

	
	write("\n你当前的灭妖任务是:"+yaos);
	write("\n第个"+yaos_num+"妖 "+ yaos_status+"\n");
	return 1;
}

