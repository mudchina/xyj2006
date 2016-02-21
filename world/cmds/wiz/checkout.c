//
// checkout.c
//
// Created :  96-08-15  09:20PM   Falcon
//

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "stick":        "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
	"iron-cloth": 	"硬功",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "magic":        "法术",
        "spells":       "咒文",
        "move":         "行动",
        "array":        "阵法",
	"whip":     	"鞭法",
]);

int main(object me, string arg)
{
	object player;
        mapping map;
        string *types, *skill, ski, map_to;
        int i, modify;

        if ( arg )
	{
         	player = present( arg, environment( me ) );
		if ( !player )
			player = find_player( arg );
		if ( !player )
			player = find_living( arg );
		if ( !player )
			return notify_fail( "你想查看谁的状态? \n" );	
		map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("他现在没有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是他目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" : 
to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }
	else
	{
        	return notify_fail( "你想看谁的状态啊? \n" );
	}
}



