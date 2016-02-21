// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i;
        string newarg, str1, str2;
        
        if( !arg ) return notify_fail("你要替自己取什么绰号？\n");
        
        if( arg=="none" ) {
        me->delete("nickname");
        return 1;
        }

        while(i--) {
                if( arg[i]<' ' ) {
                        return notify_fail("对不起，你的头衔不能用控制字元。\n");
                }
        }

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
       arg = replace_string(arg, "$BLINK$", BLINK);

        newarg=arg; // strip away ansi color code, then count length
        // mon 8/20/98
        while(sscanf(newarg,"%s*sm%s",str1,str2)==3)
                    newarg=str1+str2;

        if ( (i = strlen(newarg)) > 60 )
                return notify_fail
                    ("你的绰号太长了，想一个短一点的、响亮一点的。\n");

        me->set("nickname", arg + NOR);
        write("Ok.\n");
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : nick <外号, 绰号>
           nick none    取消
 
这个指令可以让你为自己取一个响亮的名号或头衔，你如果希望在绰号中
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

HELP +
"$BLK$ - "BLK"黑色"NOR"         $NOR$ - 恢复正常颜色\n"+
"$RED$ - "RED"红色"NOR"         $HIR$ - "HIR"亮红色"NOR"\n"+
"$GRN$ - "GRN"绿色"NOR"         $HIG$ - "HIG"亮绿色"NOR"\n"+
"$YEL$ - "YEL"土黄色"NOR"               $HIY$ - "HIY"黄色"NOR"\n"+
"$BLU$ - "BLU"深蓝色"NOR"               $HIB$ - "HIB"蓝色"NOR"\n"+
"$MAG$ - "MAG"浅紫色"NOR"               $HIM$ - "HIM"粉红色"NOR"\n"+
"$CYN$ - "CYN"蓝绿色"NOR"               $HIC$ - "HIC"天青色"NOR"\n"+
"$WHT$ - "WHT"浅灰色"NOR"               $HIW$ - "HIW"白色"NOR"\n"+
@HELP
 
其中系统自动会在字串尾端加一个 $NOR$。

HELP
        );
        return 1;
}
