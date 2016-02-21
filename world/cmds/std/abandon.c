// abandon.c

inherit F_CLEAN_UP;

// mon@xyj 10/15/98
void do_abandon(string yn, object me, string arg);

int main(object me, string arg)
{
    mapping skills;

	if( !arg || arg=="" ) return notify_fail("你要放弃哪一项技能？\n");

	skills=me->query_skills();
	if( !skills || undefinedp(skills[arg]) )
	    return notify_fail("你并没有学过这项技能。\n");

	if((int)skills[arg]>=10) {
	    write("你确定要放弃"+to_chinese(arg)+
		    "？(y/n)");
	    input_to("do_abandon",me,arg);
	} else
	    do_abandon("yes",me,arg);
	
	return 1;
}

void do_abandon(string yn, object me, string arg)
{
     if(!me) return;

     if(!yn) {
	 write("什么？\n");
	 return;
     }

     if(yn[0]=='y' || yn[0]=='Y' ) {
	if( !me->delete_skill(arg) ) {
		write("你没有学过这项技能。\n");
		return;
	}

	write("你决定放弃继续学习" + to_chinese(arg) + "。\n");
	
	if(MISC_D->random_capture(me,8000,0)) return;

	return;
     } else {
	 write("你决定保留这项技能。\n");
	 return;
     }
}

int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称>

放弃一项你所学的技能，注意这里所说的「放弃」是指将这项技能从你人物的资料中
删除，如果你以后还要练，必须从 0 开始重练，请务必考虑清楚。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由於我们假设你
的人物随时都会从他／她的各种动作、战斗中学习，因此有些技能会因为你经常地使
用而出现在你的技能列表中，这个人物就必须花费一些精神去「记住」所学过的一切
，然而，人的资质各有不同，灵性高的人能够学习许多技能而成为多才多艺的才子，
灵性较差的人就只能专心於特定几项技能，如果你学的技能种类太多，超过你的灵性
，你会发现人物的学习速度将比只学几种技能的人慢，超过越多，学习效果低落的情
况越严重，这种情形就像是一个学期同时选修太多学分，虽然你仍然可以凭著超人的
意志力练下去，不过这将会多花费你许多宝贵的时间。
TEXT
	);
	return 1;
}
