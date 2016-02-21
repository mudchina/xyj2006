// write by canoe
// 查询离线player状态
#include <ansi.h>
int help(object me);
int main(object me, string name)
{       
        object ob; 
        mapping skl,lrn, map;
        string *sname, *mapped;
	int i,flag;
        if( !name) return help(me);
	seteuid(getuid());
	if(!ob=find_player(name))
        	{
        	flag=1;
        	ob = new(USER_OB);
        	ob->set("id", name);
        	if (!ob->restore()) return notify_fail("没有这个玩家。\n");
        	}
        write("\n"+HIY+ob->name(1)+NOR+"状态如下：门派："+HIY);
        write(ob->query("family/family_name")?ob->query("family/family_name"):"普通百姓");
        write(NOR+"武学："+HIY+ob->query("combat_exp")+NOR+"\t道行："+HIY+COMBAT_D->chinese_daoxing(ob->query("daoxing"))+NOR+"\n");
        write("内力："+HIY+ob->query("max_force")+NOR+"\t法力："+HIY+ob->query("max_mana")+NOR+"\t西游历程："+HIY+FINGER_D->age_string((int)ob->query("mud_age"))+NOR+"\n");
        skl = ob->query_skills();
        if(!sizeof(skl))
                {
		write(ob->name(1)+ "目前并没有学会任何技能。\n");
		return 1;
	        }
        write( "目前所掌握的技能如下：\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});
	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	for(i=0; i<sizeof(skl); i++)
		 {
		printf("%s%s%-40s" NOR " - %-10s %4d/%5d\n", 
		(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": HIR"★"NOR),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		SKILL_D(sname[i])->level_description(skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],);
	        }
	write("\n");
        if (flag) destruct(ob);
        return 1;
}

int help(object me)
{
write(@HELP
指令格式：adcheck <id>
察看某个玩家状态，包括不在线的。
HELP
	);
    return 1;
}
