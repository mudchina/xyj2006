#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if(!arg) return notify_fail("指令：kick <living>\n");
        ob = find_player(arg);
        if (!ob) return notify_fail("找不到这个玩家。\n");
if(ob->query("id")=="bear"&&ob->query("name")=="小熊")
return notify_fail("你怎么可以把小熊大神踢出去呢？\n");
        write("你飞起一脚将"+ob->name()+"踢的灰飞烟灭！！\n");
        ob->set("kickout_time",time());
        ob -> save();
        seteuid(ROOT_UID);
        destruct(ob);
        return 1;
}

int help(object me)
{
   write(@HELP
指令格式: nuke <玩家>
将某个玩家踢出风云，并且使其在一个小时内不可以联线


HELP
   );
   return 1;
}
