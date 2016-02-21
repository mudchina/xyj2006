// describe.c

#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *txt;

	if( !arg ) return notify_fail("指令格式：describe <描述>\n");

	txt = explode(arg, "\n");
	if( (wizardp(me) && sizeof(txt) > 20) || sizeof(txt) > 8 )
		return notify_fail("请将您对自己的描述控制在八行以内。\n");

	arg = implode(txt, "\n") + "\n";

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

	me->set("long", arg + NOR);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：describe <描述>

这个指令让你设定当别人用 look 指令看你时，对你的描述，通常当你
的描述超过一行时可以用 to describe 的方式来输入。
TEXT
	);
	return 1;
}
