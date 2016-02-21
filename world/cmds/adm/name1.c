#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string tmp;
        object ob = me;

        if( !arg )
                return notify_fail("你要给谁取什么名字？\n");

        if (sscanf(arg, "%s %s", tmp, arg) == 2)
                ob = find_player(tmp);
        if (!ob) return notify_fail("这里没有这个人。\n");

        if( strlen(arg) > 20 )
                return notify_fail("这个名字太长了，想一个短一点的、响亮一点的。\n");
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
        message_vision(HIY "$N将$n的名字改为" + arg + "。\n" NOR, me, ob);
        ob->set("name", arg);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: name [玩家] 名字
 
修改玩家或自己的名字。

HELP );
        return 1;
}
