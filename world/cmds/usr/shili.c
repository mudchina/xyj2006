
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
         string faname=me->query("family/family_name");   

          if( ! faname )
           return notify_fail("你连个门派都没有何来势力而言！\n");
        write("你的门派是"+HIC+faname+NOR+"，势力如下：\n");
write("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");   
     "/adm/daemons/shili"->query_all_shili(faname);
write("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"); 

        return 1;
           
}

 
int help(object me)
{
        write(@HELP
指令格式 : shili
这个指令告诉你所在的门派在取经路的各国上的范围势力.
HELP
    );
    return 1;
}                     
