// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
		BLU "初学乍练" NOR,
		BLU "不知所以" NOR,
        BLU "粗通皮毛" NOR,
		HIB "略识之无" NOR,
		HIB "渐有所悟" NOR,
		HIB "半生不熟" NOR,
		YEL "马马虎虎" NOR,
		YEL "平淡无奇" NOR,
		YEL "平平常常" NOR,
		HIY "触类旁通" NOR,
		HIY "心领神会" NOR,
		HIY "深入浅出" NOR,
		HIM "挥洒自如" NOR,
		HIM "驾轻就熟" NOR,
		HIM "出类拔萃" NOR,
		HIR "初入佳境" NOR,
		HIR "神乎其技" NOR,
		HIR "心领神会" NOR,
		MAG "神乎其技" NOR,
		MAG "威不可当" NOR,
		MAG "出神入化" NOR,
		CYN "超群绝伦" NOR,
		CYN "登峰造极" NOR,
		CYN "卓然大家" NOR,
		HIC "一代宗师" NOR,
		HIC "独步天下" NOR,
		HIC "空前绝后" NOR,
		WHT "旷古绝伦" NOR,
		WHT "超凡入圣" NOR,
		WHT "返璞归真" NOR,
		HIW "深不可测" NOR
	});

string *knowledge_level_desc = ({
		BLU "新学乍用" NOR,
		BLU "不甚了了" NOR,
        BLU "不知端倪" NOR,
		HIB "平淡无奇" NOR,
		HIB "司空见惯" NOR,
		HIB "初窥门径" NOR,
		YEL "略知一二" NOR,
		YEL "茅塞顿开" NOR,
		YEL "略识之无" NOR,
		HIY "滚瓜烂熟" NOR,
		HIY "马马虎虎" NOR,
		HIY "轻车熟路" NOR,
		HIM "运用自如" NOR,
		HIM "触类旁通" NOR,
		HIM "深入浅出" NOR,
		HIR "已有小成" NOR,
		HIR "心领神会" NOR,
		HIR "了然于胸" NOR,
		MAG "见多识广" NOR,
		MAG "无所不通" NOR,
		MAG "卓尔不群" NOR,
		CYN "满腹经纶" NOR,
		CYN "豁然贯通" NOR,
		CYN "博古通今" NOR,
		HIC "博大精深" NOR,
		HIC "超群绝伦" NOR,
		HIC "举世无双" NOR,
		WHT "独步天下" NOR,
		WHT "震古铄今" NOR,
		WHT "超凡入圣" NOR,
		HIW "深不可测" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob, *list, couple_ob;
	mapping skl, lrn, map;
	string *sname, *mapped,target,cardname;
	int i, marry_flag;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
                if (!ob) ob = LOGIN_D->find_body(arg);
                if (!ob || !me->visible(ob))
                return notify_fail("你要察看谁的技能？\n");
	}
          
	target = (string) me->query("couple/couple_id");	
	if(stringp(target)) couple_ob = find_player(target);
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public") )
		return notify_fail("只有管理或有师徒关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( (ob==me ? "你" : ob->name()) +"目前共学过"+
chinese_number(sizeof(skl))+"种技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );

	printf(HIC"≡≡────────────────────────────────≡≡\n"NOR);
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		printf("%s%s%-40s ※%-10s※  %3d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? HIG"  "NOR: HIR"＊"NOR),
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
        printf(HIC"\n≡≡────────────"BLINK""HIG"★西游记2006★"NOR""HIC"-────────────≡≡\n"NOR);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 10;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}
string pet_skill(object ob)
{
	string desc;
        object  *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                desc =  ob->name() + "目前并没有学会任何技能。\n";
                return desc;
        }
        	desc =  ob->name() +"目前所学过的技能：\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
              desc +=  sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "＊"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        return desc +"\n";
}
int help(object me)
{
	write(@HELP
指令格式 : skills [<某人>]

这个指令可以让你查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。


HELP
    );
    return 1;
}

