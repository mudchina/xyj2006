//Cracked by Roath
// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *ob,*target;
        int i;
	string mebang,obbang;

	mebang = (string)me->query("marks/帮派");
	if ((mebang==0) || (mebang=="空")) return 1;
        ob=users();
        i = sizeof(ob);
        while (i--) {
		obbang = (string)ob[i]->query("marks/帮派");
		if ( (obbang!=0) && (obbang!="空") && (mebang == obbang) )
		{
			if (sizeof(target)==0)
			{
				target=({ob[i]});
			} else {
				target+=({ob[i]});
			}
		}
	}
	
	message("vision", HIW "【帮会】" + me->name(1) + "：" + arg + "\n" NOR, target);	
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ulist

将线上所有玩家的/obj/user number 显示出来。
HELP
    );
    return 1;
}
