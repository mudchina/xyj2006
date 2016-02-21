// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	"unarmed":	"拳脚",
	"sword":	"剑法",
	"blade":	"刀法",
	"stick":	"棍法",
	"staff":		"杖法",
	"throwing":	"暗器",
	"force":	"内功",
	"parry":	"招架",
	"dodge":	"轻功",
//	"magic":	"魔法",
	"spells":	"法术",
//	"move":		"行动",
//	"array":	"阵法",
	"whip" :	"鞭法",
	"spear":	"枪法",
	"axe":          "斧法",
	"mace":         "锏法",
	"fork":		"叉法",
	"rake":		"钯法",
	"archery":	"弓箭",
	"hammer":	"锤法",
	"literate":     "读书识字",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	int i, modify;
	string check;

	seteuid(getuid());
	if (arg) 
		sscanf(arg, "-%s %s", check, arg); 
	if (check=="check" && wizardp(me) && arg) {
		me = find_player(arg);
		if (!me) me = LOGIN_D->find_body(arg);
		if (!me) return notify_fail("没有这个人。\n");
		}

	if( !arg || check=="check" ) {
		map = me->query_skill_map();
		if( !mapp(map) || sizeof(map)==0 )
			return notify_fail("你现在没有使用任何特殊技能。\n");

		skill = keys(valid_types);
		write("以下是你目前使用中的特殊技能。\n");
		for (i=0; i<sizeof(skill); i++) {
			if( undefinedp(valid_types[skill[i]]) ) {
				map_delete(map, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			modify = me->query_temp("apply/" + skill[i]);
			printf("  %-20s： %-20s  有效等级：%s%4d\n" NOR, 
				valid_types[skill[i]] + " (" + skill[i] + ")",
				undefinedp(map[skill[i]]) ? 
				"无" : to_chinese(map[skill[i]]),
				(modify==0 ? "" : (modify>0 ? HIC : HIR)),
				me->query_skill(skill[i]));
		}
		return 1;
	}

	if( arg=="?" ) {
		write("以下是可以使用特殊技能的种类：\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		for(i=0; i<sizeof(skill); i++) {
			printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
		}
		return 1;
	}

	if( sscanf(arg, "%s %s", ski, map_to)!=2 )
		return notify_fail("指令格式：enable [<技能种类> <技能名称>|none]\n");

	if( undefinedp(valid_types[ski]) )
		return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");

	if( map_to=="none" ) {
		me->map_skill(ski);
		me->delete_temp("perf_quick");
		me->reset_action();
		write("Ok.\n");
	} else if( map_to==ski ) {
		write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
		return 1;
	} else {

	  if( !me->query_skill(map_to, 1) )
		return notify_fail("你不会这种技能。\n");

	  if( !SKILL_D(map_to)->valid_enable(ski) )
		return notify_fail("这个技能不能当成这种用途。\n");

	  me->map_skill(ski, map_to);
	  me->delete_temp("perf_quick");
	  me->reset_action();
	  write("Ok.\n");
	}
	
	if( ski=="magic" ) {
		write("你改用另一种魔法，灵力必须重新修炼。\n");
		me->set("atman", 0);
		me->receive_damage("gin", 0);
	} else if( ski=="force" ) {
	        int f1, f2;
		if( map_to!="none")
		  write("你改用另一种内功，内力必须重新修炼。\n");
		me->set("force", 0);
		me->set("force_factor", 0);
		//need this to fix low special high factor. 
		me->receive_damage("kee", 0);
		
		// mon 12/10/98
		f1=me->query_max_force();
		f2=me->query("maximum_force");
		if(f1>f2) f1=f2;
		me->set("max_force",f1);
		
	} else if( ski=="spells" ) {
	        int f1, f2;
		if( map_to!="none")
		  write("你改用另一种法术，法力必须重新修炼。\n");
		me->set("mana", 0);
		me->set("mana_factor", 0);
		//same as the fix for force.
		me->receive_damage("sen", 0);

		// mon 12/10/98
		f1=me->query_max_mana();
		f2=me->query("maximum_mana");
		if(f1>f2) f1=f2;
		me->set("max_mana",f1);
	}

	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : enable|jifa [<技能种类> <技能名称> | none]
           enable ?

这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个 ? 会列出
所有能使用特殊技能的技能种类。
 
HELP
        );
        return 1;
}
