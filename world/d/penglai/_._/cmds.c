//created by vikee
//2000.10
//score.c (new)
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);
void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
        object ob;
        mapping my;
        string line, str, skill_type, *marks;
        object weapon;
        int i, attack_points, dodge_points, parry_points;
        seteuid(getuid(me));
        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");
        my = ob->query_entire_dbase();
        line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
        str = "";
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] ) str = my["family"]["master_name"];
        }
        if( mapp(my["marks"]) ) {
                marks = keys( my["marks"] );
                for( i = 0; i < sizeof(marks); i ++ ) {
                        if( str != "" ) str += "、";
                        str += marks[i];
                }
        }
        line += sprintf( " "HIY"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡"NOR"\n\n");
		line += sprintf( " 姓名：[%s% 6s%s]  性别：[%s% 6s%s] 年龄：[%s% 6s%s]"NOR"\n",
                WHT, ob->query("name"), NOR,
                WHT, ob->query("gender"), NOR,
                WHT, chinese_number(ob->query("age")), NOR );
			if (ob->query("married")==1)
		{
			if (ob->query("gender")=="女性")
			{
				line += sprintf( " 种类：[%s% 6s%s]  派系：[%s%-1s%s]  丈夫：[%s%-1s%s]\n",
                HIC, ob->query("race"), NOR,
                HIC, ob->query("family/family_name"), NOR,
				HIC, ob->query("couple/name"),NOR );
			}
			else
			{
				line += sprintf( " 种类：[%s% 6s%s]  派系：[%s%-1s%s]  妻子：[%s%-1s%s]\n",
                HIC, ob->query("race"), NOR,
                HIC, ob->query("family/family_name"), NOR ,
				HIC, ob->query("couple/name"),NOR );
			}
		}
			else
			{
				if (ob->query("gender")=="女性")
				{
				line += sprintf( " 种类：[%s% 6s%s]  派系：[%s%-1s%s]  婚姻：["HIC"待字闺中"NOR"]\n",
                HIC, ob->query("race"), NOR,
                HIC, ob->query("family/family_name"), NOR);
				}
				else 	
				{
				line += sprintf( " 种类：[%s% 6s%s]  派系：[%s%-1s%s]  婚姻：["HIC"打光棍儿"NOR"]\n",
                HIC, ob->query("race"), NOR,
                HIC, ob->query("family/family_name"), NOR);
				}
			}               
        if( str != "" ) 
		line += sprintf( " 师承：[%s% 6s%s]  生日：[%s%-32s%s] \n",HIY, str, NOR,
                                HIY,  CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) , NOR );
        if( str =="")	
		{
			str = "尚未拜师";
			line += sprintf( " 师承：[%s% 6s%s]  生日：[%s%-42s%s] \n",HIY, str, NOR,
                                HIY,  CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) , NOR );
		}
		line += sprintf( " "HIC"-----------------------------------------------------------------------"NOR"\n");
		if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
        line += sprintf( " 容貌  [%s %4s %s]  ",
                HIG, display_attr(my["per"], ob->query_per()), NOR );
        line += "精神  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], MAG, HIW ,HIR)
                + sprintf( "  [%s%8d%s / %s%7d%s]\n", HIW, my["sen"], HIG,
                HIM, my["max_sen"],  NOR );
        line += sprintf( " 福缘：[%s %4d %s]  ",
                HIY, ob->query_kar(), NOR );
        line += "气血  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], MAG, HIW ,HIR)
                + sprintf( "  [%s%8d%s / %s%7d%s]\n", HIW, me->query("kee"), HIG,
                HIM, my["max_kee"],NOR );
        line += sprintf( " 悟性：[%s %4s %s]  ",
                HIG, display_attr(my["int"], ob->query_int()), NOR );
		line += "内力：" + tribar_graph(my["force"], ob->query("force"),
                ob->query("max_force"), MAG, HIC ,HIR)
                + sprintf( "  [%s%8d%s / %s%7d%s]\n", MAG HIC, my["force"], HIG,
                HIM, ob->query("max_force"),NOR );
        line += sprintf( " 体格：[%s %4s %s]  ",
                HIG, display_attr(my["str"], ob->query_str()), NOR );
        line += "法力：" + tribar_graph(my["mana"], ob->query("mana"),
                ob->query("max_mana"), MAG, HIC ,HIR)
                + sprintf( "  [%s%8d%s / %s%7d%s]\n", MAG HIC, my["mana"], HIG,
                HIM, ob->query("max_mana") ,NOR );
		line += sprintf( " 根骨：[%s %4s %s]  ",
                HIG, display_attr(my["con"], ob->query_con()), NOR );
		if( my["food"] * 100 / ob->max_food_capacity() > 10 ) str = HIC + "正常";
        else str = HIR + "缺食";
        line += "食物：" + tribar_graph(my["food"], ob->max_food_capacity(),
                ob->max_food_capacity(), MAG, HIY ,HIR)
                + sprintf( "  [%s%4d%s / %s%4d%s , %4s%s]\n", MAG HIC, my["food"], HIG,
                HIM, ob->max_food_capacity(), HIG, str, NOR );    
		line += sprintf( " 灵性：[%s %4s %s]  ",
                HIG, display_attr(my["spi"], ob->query_spi()), NOR );
    	if( my["water"] * 100 / ob->max_water_capacity() > 10 ) str = HIC + "正常";
        else str = HIR + "缺水";
        line += "饮水：" + tribar_graph(my["water"], ob->max_water_capacity(),
                ob->max_water_capacity(), MAG, HIY ,HIR)
                + sprintf( "  [%s%4d%s / %s%4d%s , %4s%s]\n", MAG HIC, my["water"], HIG,
                HIM, ob->max_water_capacity(), HIG,  str, NOR );		
		line += sprintf( " 胆识：[%s %4s %s]  ",
                HIG, display_attr(my["cor"], ob->query_cor()), NOR );
		line += sprintf("攻击：[%s%12d%s (%s+%4d%s)%s]  躲闪：[%s%12d%s]%s\n" NOR,
                HIC, attack_points + 1, HIG, HIW, ob->query_temp("apply/damage"), HIG, NOR,
                HIC, dodge_points + 1, NOR, NOR);
		line += sprintf( " 定力：[%s %4s %s]  ",
                HIG, display_attr(my["cps"], ob->query_cps()), NOR );
		line += sprintf("防御：[%s%12d%s (%s+%4d%s)%s]  招架：[%s%12d%s]%s\n"NOR,
                HIC, (dodge_points + (weapon ? parry_points: (parry_points/10))) + 1, HIG,
                HIW, ob->query_temp("apply/armor"), HIG, NOR,
                HIC, parry_points + 1, NOR, NOR);
		if (wiz_level(me) >0 )
		{
		line += sprintf( " 杀生："GRN"["HIR"%6d"NOR""GRN"]"NOR" ",
                ob->query("MKS")+ob->query("PKS"));
		line += sprintf( " 杀人："GRN"["RED"%2d"NOR""GRN"]"NOR" ",
							ob->query("PKS") );
		line += sprintf( " 已吃人参果："GRN"["HIW"%2d"NOR""GRN"]"NOR" ",
							ob->query("rsg_eaten") );
		line += sprintf( " 银行存款："GRN"["HIY"%8d"NOR""GRN"]"NOR" \n",
							ob->query("balance")/10000 );
		}
		else
		{	
		line += sprintf( " 杀生："GRN"["HIR"%6d"NOR""GRN"]"NOR" ",
                ob->query("MKS")+ob->query("PKS"));
		line += sprintf( " 杀人："GRN"["RED"%4d"NOR""GRN"]"NOR" \n",
							ob->query("PKS") );
		}
		line += sprintf( " "HIC"-----------------------------------------------------------------------"NOR"\n");
		if(ob->query("kill/pkgain") ) { 
          line +=sprintf(" ＰＫ道行增加： %s  \n",
       COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
          if(!ob->query("kill/pklose") &&
        !ob->query("kill/nkgain") ) line+="\n";
        }
		if(ob->query("kill/pklose") ) {
          line +=sprintf(" ＰＫ道行减少： %s\n",
       COMBAT_D->chinese_daoxing(ob->query("kill/pklose")));
          if(!ob->query("kill/nkgain") ) line+="\n";
        }
		if(ob->query("kill/nkgain") ) {
          line +=sprintf(" ＮＫ道行增加： %s\n\n",
		COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
        }
		line += sprintf(" 道行境界：[%s% 6s%s]  武学境界：[%s%20s%s] \n",
                HIR, RANK_D->describe_dx(ob->query("daoxing")), NOR,
                HIG, RANK_D->describe_exp(ob->query("combat_exp")), NOR);
        line += sprintf(" 法力修为：[%s%6s%s]  内力修为：[%s%20s%s] \n\n",
                HIR, RANK_D->describe_fali(ob->query("max_mana")), NOR,
                HIG, RANK_D->describe_neili(ob->query("max_force")), NOR);
		line += sprintf( " "HIY"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ 西游记2006 ≡≡≡≡≡≡≡"NOR"\n\n");
        write(line+BBLK);
        return 1;
}
string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%4d", value );
        else return sprintf("%3d", value);
}
string status_color(int current, int max)
{
        int percent;
        if( max ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 10;
        if( max == 0 ) max = 1;
        n = val * 100 / max / 5;
        eff_n = eff * 100 / max / 5;
        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;
        ret = NOR "[" + bcolor + fcolor ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += dcolor;
                if( i < n )  ret += "★";
                else ret += "☆";
        }
        ret += fcolor + NOR "]";
        return ret;
}
int help(object me)
{
        write(@HELP
指令格式：score
          score <对象名称>      （巫师专用）
显示自己或者指定对象（含怪物）的基本资料。
相关讯息：hp
HELP
        );
        return 1;
}
