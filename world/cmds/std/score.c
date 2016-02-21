//Cracked by Roath

#include <ansi.h>
#include <combat.h>
#include <mudlib.h>

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
        int i, attack_points, dodge_points, parry_points,obstacles,dntg;

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
        write(NOR YEL"≡≡≡≡≡≡≡≡≡≡"HIG"个"NOR YEL"≡≡"HIG"人"NOR YEL"≡≡"HIG"档"NOR YEL"≡≡"HIG"案"NOR YEL"≡≡≡≡≡≡≡≡≡≡\n"NOR);
        write("你现在的仙衔 : "+RANK_D->query_rank(ob)+"\n");
        write("你现在的职称 : "+ob->short(1)+"\n");
        line = NOR YEL"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR;
        str = "";
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] ) str =my["family"]["family_name"]+HIC+my["family"]["master_name"];
        }
        if( mapp(my["marks"]) ) {
                marks = keys( my["marks"] );
                for( i = 0; i < sizeof(marks); i ++ ) {
                        if( str != "" ) str += "、";
                        str += marks[i];
                }
        }

        line += sprintf( " 年龄：[%s%-4s%s]         生日：[%s%-24s%s]\n",
                 HIC, chinese_number(ob->query("age")), NOR,
                 HIC, CHINESE_D->chinese_date(((int)ob->query("birthday") -14*365*24*60) * 60), NOR );

        line += sprintf( " 性别：[%s%-4s%s]         体重：[%s%-4s公斤%s]  门派：[%s%-6s%s]\n\n",
                 HIC, ob->query("gender"), NOR,
                 HIC, chinese_number((int)ob->query_weight()/1000), NOR,
                 HIC, ob->query("family/family_name")?ob->query("family/family_name"):"普通百姓", NOR );
if (ob->query("couple/name") != 0) line += sprintf(" 婚姻状况：" HIG"伴侣：%-11s"NOR,ob->query("couple/name"));
	else line += sprintf(" 婚姻状况：" MAG"未婚\t\t\t"NOR);
        if( str != "" ) line += sprintf( " 师承：[%-20s%s]\n\n",str, NOR );
        else line+="["CYN"还未曾求仙访道"NOR"]\n";	
        
        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

       attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

       line += sprintf( " 体格：[%s %4s %s]  ",
                 NOR, display_attr(my["str"], ob->query_str()), NOR );
        if( my["eff_gin"] <my["max_gin"] ) str = HIR+"生病";
        else if( my["gin"]*100 / my["max_gin"]>=70 ) str = HIG + "饱满";
        else if( my["gin"]*100 / my["max_gin"]>=40 ) str = HIR + "疲倦";
        else str = HIB + "很累";
        line += "〖"HIR"精神"NOR"〗  " + tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n", str,NOR);
        line += sprintf( " 根骨：[%s %4s %s]  ",
                NOR, display_attr(my["con"], ob->query_con()), NOR );
        if( my["eff_kee"] <my["max_kee"] ) str = HIR+"伤残";
        else if( my["kee"]*100 / my["max_kee"]>=70 ) str = HIG + "充沛";
        else if( my["kee"]*100 / my["max_kee"]>=40 ) str = HIR + "受伤";
        else str = HIB + "重伤";
        line += "〖"HIR"气血"NOR"〗  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n",str,NOR);
        
        
        
        

        if( my["food"] * 100 / ob->max_food_capacity() >= 80 ) str = HIG+"很饱";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 50 ) str = HIC+"正常";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 20 ) str = HIR+"缺食";
        else str = HIB + "饥饿";
        
        

        if( my["water"] * 100 / ob->max_water_capacity() > 60 ) str = HIG + "正常";
        else if( my["water"] * 100 / ob->max_water_capacity() > 30 ) str = HIR + "缺水";
        else str = HIB + "饥渴";
        line += sprintf( " 悟性：[%s %4s %s]  ",
                NOR, display_attr(my["int"], ob->query_int()), NOR );
        line += "〖"HIC"食物"NOR"〗：" + tribar_graph(my["food"], ob->max_food_capacity(),
                ob->max_food_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n", str, NOR );        
        line += sprintf( " 灵性：[%s %4s %s]  ",
                NOR, display_attr(my["spi"], ob->query_spi()), NOR );
        line += "〖"HIC"饮水"NOR"〗：" + tribar_graph(my["water"], ob->max_water_capacity(),
                ob->max_water_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n",  str, NOR );
        line += sprintf( " 容貌：[%s %4s %s]  ",
                NOR, wizardp(ob)?display_attr(my["per"], ob->query_per()):"隐藏", NOR );
        
        line += "〖"HIW"死亡"NOR"〗：" 
                + sprintf( "杀害玩家：%s%d%s 位,杀死敌人：%s%d%s 名\n",  HIR, my["PKS"], NOR,
                HIW, my["MKS"], NOR);
	
        
  

        line += sprintf( " 福缘：[%s %4s %s]  ",
                NOR, wizardp(ob)?display_attr(my["kar"], ob->query_kar()):"隐藏", NOR );
        if((int)ob->query("balance"))
        line+= "〖"HIY"存款"NOR"〗："+MONEY_D->money_str((int)ob->query("balance"))+"\n\n";
        else line+="〖"HIY"存款"NOR"〗："+HIW"没有任何存款"NOR+"\n\n";
      if(wizardp(this_player())) 
	line += sprintf(" 战斗攻击力 " HIW "%d (+%d)" NOR "\t\t战斗防御力 " HIW "%d (+%d)\n\n" NOR,
	attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: 
		(parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
	else line+=sprintf(" 兵器伤害力： ["HIR"%d"NOR"]" NOR "\t\t盔甲保护力： ["HIG"%d"NOR"]\n\n" NOR,
	ob->query_temp("apply/damage"),
	ob->query_temp("apply/armor"));
obstacles = ob->query("obstacle/number");
        line+= "〖"HIC"门派威望"NOR"〗："+HIR""+(int)ob->query("score")+NOR+"\t\t\t\t〖"HIC"门派忠诚度"NOR"〗"+HIR""+(int)ob->query("faith")+NOR+"\n\n";
        if(obstacles)
		line += sprintf(RED" 西天取经"NOR"：你已经历了"RED"%s"NOR"道劫难。\n", chinese_number(obstacles));
		else line += RED" 西天取经"NOR"：你还未曾踏上取经之路\n";
	dntg = ob->query("dntg/number");
	     if (dntg == 0) line += " "RED"大闹天宫"NOR"：你还未曾大闹天宫\n";
	     else line+= RED" 大闹天宫"NOR"：你大闹天宫已过"HIR+chinese_number(dntg)+NOR"关。\n";
	if(ob->query("kill/pkgain") ) 
	{ 
		line +=sprintf(" ＰＫ道行增加： %s  \n", COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
		if(!ob->query("kill/pklose") && !ob->query("kill/nkgain") ) line+="\n";
	}
	if(ob->query("kill/nkgain") ) 
	{
		line +=sprintf(" ＮＫ道行增加： %s\n", COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
	}

        line += sprintf(" 道行境界：[%s]       武学境界：[%s]\n",
                 RANK_D->describe_dx(ob->query("daoxing")),  RANK_D->describe_exp(ob->query("combat_exp")) );
        line += sprintf(" 法力修为：[%s]       内力修为：[%s]\n",
                 RANK_D->describe_fali(ob->query("max_mana")),  RANK_D->describe_neili(ob->query("max_force")) );
line += YEL"≡≡≡≡≡≡≡≡≡≡ "HIR"西游记2006"HIY"·"HIG"总站"NOR YEL" ≡≡≡≡≡≡≡≡≡≡≡\n"NOR;
 line += sprintf(WHT+" 为求取真经%s已经历了"HIR"%s"NOR"的岁月 \n\n"+NOR,ob==me?"你":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));

        write(line+BBLK);
        return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%4d", value );
        else if( value < gift ) return sprintf( HIC "%4d", value );
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
        int i, n, eff_n, max_n = 12;

        if( max == 0 ) max = 1;
        n = val * 100 / max / 10;
        eff_n = eff * 100 / max / 10;

        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;

        ret = NOR  + bcolor + fcolor ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += dcolor;
                if( i < n )  ret += "━";
                else ret += HIW"━"NOR;
        }
        ret += fcolor + NOR ;
        return ret;
}
int help(object me)
{
        write(@HELP
指令格式：score
          score <对象名称>      （巫师专用）

显示自己或者指定对象（含怪物）的基本资料。此指令可以“sc”代替。

相关讯息：hp
HELP
        );

        return 1;
}
