//Cracked by Roath
// rankd.c

#include <ansi.h>

//descriptions...

//note, be careful with the size of this list, dx increases as n^3. 
string *dx_level_desc = ({
        BLU "新入道途" NOR, //in unit of year 
        BLU "闻道则喜" NOR, //1x2=2   
        BLU "初领妙道" NOR, //8x2=16
        BLU "略通道行" NOR, //27x2=56    
        HIB "渐入佳境" NOR, //64x2=128
        HIB "元神初具" NOR, //125x2=250
        HIB "道心稳固" NOR, //216x2=432    
        HIB "一日千里" NOR, //343x2=686
        CYN "道高德隆" NOR, //512x2=1024
        CYN "脱胎换骨" NOR, //729x2=1458    
        CYN "霞举飞升" NOR, //1000x2=2000
        CYN "道满根归" NOR, //1331x2=2662    
        HIC "不堕轮回" NOR, //1728x2=3456
        HIC "已证大道" NOR, //2197x2=4394    
        HIC "反璞归真" NOR, //2744x2=5688 
        HIW "天人合一" NOR  //3375x2=6750
});

string *fali_level_desc = ({
        BLU "初具法力" NOR, //    
        BLU "略晓变化" NOR, //1x40=40
        BLU "降龙伏虎" NOR, //4x40=160
        HIB "腾云驾雾" NOR, //9x40=360   
        HIB "神出鬼没" NOR, //16x40=640
        HIB "预知祸福" NOR, //25x40=1000
        HIB "妙领天机" NOR, //36x40=1440    
        CYN "呼风唤雨" NOR, //49x40=1960
        CYN "负海担山" NOR, //64x40=2560    
        CYN "移星换斗" NOR, //81x40=3240
        CYN "包罗万象" NOR, //100x40=4000
        HIC "随心所欲" NOR, //121x40=4840    
        HIC "变换莫测" NOR, //144x40=5760
        HIW "法力无边" NOR  //169x40=6760
});

string *exp_level_desc = ({
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
                HIR "威不可当" NOR,
                MAG "出神入化" NOR,
                MAG "豁然贯通" NOR,
                MAG "超群绝伦" NOR,
                CYN "登峰造极" NOR,
                CYN "卓然大家" NOR,
                CYN "一代宗师" NOR,
                HIC "独步天下" NOR,
                HIC "空前绝后" NOR,
                HIC "旷古绝伦" NOR,
                WHT "登堂入室" NOR,
                WHT "超凡入圣" NOR,
                WHT "返璞归真" NOR,
                HIW "深不可测" NOR
});

string describe_dx(int value)
{
        int grade, two_year, n;
        
        two_year = value/2000;
        for(grade=0; grade<sizeof(dx_level_desc); grade++)
//sizeof(dx_level_desc)
        {
                n = (grade+1)*(grade+1)*(grade+1);
                if( two_year<n ) break;
        }
        if( grade>=sizeof(dx_level_desc) ) grade=sizeof(dx_level_desc)-1;
        return dx_level_desc[grade];
}

int grade_dx(string desc)
{
        int grade, n;

        for(grade=0; grade<sizeof(dx_level_desc); grade++) 
        {
                n = grade;
                if ( dx_level_desc[grade] == desc )
                        return n;
        }
        return 0;
}

string describe_exp(int value)
{
        int grade, lvl , n;
        
        lvl = value/100;
        //note, this is to make 深不可测 requires 2700k combat_exp,
        //which also means player can learn skill level to 300.

        for(grade=0; grade<sizeof(exp_level_desc); grade++) 
        {
                n = (grade+1)*(grade+1)*(grade+1);
                if( lvl<n ) break;
        }
        if( grade>=sizeof(exp_level_desc) ) grade=sizeof(exp_level_desc)-1;
        return exp_level_desc[grade];
}

int grade_exp(string desc)
{
        int grade, n;

        for(grade=0; grade<sizeof(exp_level_desc); grade++) 
        {
                n = grade;
                if ( exp_level_desc[grade] == desc )
                        return n;
        }
        return 0;
}

string describe_neili(int value)
{
        int year, sixty, left;
        string line;
        
        year = value/100;
        sixty = year/60;
        left = year - sixty*60;

        if( year <= 0 )
        {
                line = HIB "不到一年" NOR;
                return line;
        }
        
        if(sixty > 0 )
        {
                if ( left != 0 )
                { 
                        line = HIW + chinese_number(sixty) + "甲子" + NOR + "又" +  HIR + chinese_number(left) + "年" + NOR;
                }
                else 
                {
                        line = HIW + chinese_number(sixty) + "甲子"  + NOR;     
                }               
        }
        else 
                line = HIR + chinese_number(year)+"年" + NOR;

        return line;
}

string describe_fali(int value)
{
        int grade, lvl, n;

        //in unit of 40, increase by n^2.
        lvl=value/40;
        for(grade=0; grade<sizeof(fali_level_desc); grade++) 
        {
                n=(grade+1)*(grade+1);
                if( lvl<n ) break;
        }
        if( grade>=sizeof(fali_level_desc) ) grade=sizeof(fali_level_desc)-1;
        return fali_level_desc[grade];
}
 
int grade_fali(string desc)
{
        int grade;

        for(grade=0; grade<sizeof(fali_level_desc); grade++) 
        {
                if ( (string)fali_level_desc[grade] == desc )
                        return grade;
        }
        return 0;
}

string query_description(int type)
{
    int i;
    string *level_desc;
    string line = "";
    
    if(type==0) level_desc = dx_level_desc;
    else if(type==1) level_desc = exp_level_desc;
    else level_desc = fali_level_desc;
    
    for(i=0; i<sizeof(level_desc); i++)
    {
        line += level_desc[i] + "    ";
        if( (i%4)==3 ) line += "\n";
    }
    
    return line;
}

string _query_rank(object ob);

string query_rank(object ob)
{
    string rank=_query_rank(ob);
    string s1,s2,s3;
    int len, len1, len2;
    
    if(sscanf(rank,"%s【%s】%s",s1,s2,s3)!=3) return rank;
    len=14-sizeof(s2);
    if(len<1) return rank;

    len1=len/2;
    len2=len-len1;
    if(len1) s2=repeat_string(" ",len1)+s2;
    if(len2) s2+=repeat_string(" ",len2);
    
    return s1+"【"+s2+"】"+s3;
}

string _query_rank(object ob)
{
        string at;
        int dx, exp, avg;
	    int budd;
        int age;
        if(strlen(ob->query("added_title"))<1) ob->set("added_title", "无名");
        //need this default, otherwise looks too ugly sometimes.

        at = ob->query("added_title");
        dx = (int)ob->query("daoxing");
        exp = (int)ob->query("combat_exp");
        avg = (dx + exp)/2;
        age = ob->query("age");

        if( ob->is_ghost() ) return HIB "【 鬼  魂 】" NOR;
        switch(ob->query("gender")) 
        {
        case "女性":
                switch(wizhood(ob)) {
                        case "(admin)": return GRN "【 巫  女 】" NOR;
                        case "(arch)":          return GRN "【 巫  女 】" NOR;
                        case "(wizard)":        return GRN "【 巫  女 】" NOR;
                        case "(apprentice)":    return GRN "【见习巫女】" NOR;
                                case "(immortal)":      return GRN "【客座巫女】" NOR;
                                case "(elder)":         return GRN "【荣誉玩家】" NOR;
                        default:
                                switch(ob->query("class")) 
                                {
//------------------rank for girls--------------------
case "xiake":
        if(dx<1000) 
                return HIC "【 女剑童 】" NOR;
        else if(dx<10000) 
                return HIC "【 女剑士 】" NOR;
        else if(dx<500000) 
                return HIC "【 女剑客 】" NOR;
        else if(dx<1000000) 
                return HIC "【"+at+"剑仙】" NOR;
        else 
                return HIC "【"+at+"剑圣】" NOR;
case "xian":
        if(dx<1000) 
                return HIM "【 玉  女 】" NOR;
        else if(dx<10000) 
                return HIM "【 小神女 】" NOR;  
        else if(dx<100000) 
                return HIM "【 神  女 】" NOR;
        else if(dx<500000) 
                return HIM "【"+at+"仙妃】" NOR;        
 else if ( ob->query("family/family_name") == "五庄观" )
       return HIC "【"+at+"天仙】" NOR;
   else
                return HIM "【"+at+"天后】" NOR;
        break;
case "yaomo":
if ( ob->query("family/family_name") == "盘丝洞" )
        if(avg<1000) 
                return MAG "【 小魔女 】" NOR;
        else if(avg<10000) 
                return MAG "【 精   灵】" NOR;  
        else if(avg<100000) 
                return MAG "【 女  魔 】" NOR;
        else if(avg<500000) 
                return MAG "【"+at+"精】" NOR;        
        else 
                return MAG "【"+at+"魔尊】" NOR;
if ( ob->query("family/family_name") == "火云洞" )
        if(avg<1000) 
                return RED "【 小妖女 】" NOR;
        else if(avg<10000) 
                return RED "【 妖  精 】" NOR;  
        else if(avg<100000) 
                return RED "【 女  妖 】" NOR;
        else if(avg<500000) 
                return RED "【"+at+"女洞主】" NOR;        
        else 
                return RED "【"+at+"女妖王】" NOR;
if ( ob->query("family/family_name") == "大雪山" )
        
                if(avg<1000) 
                return HIW "【 小妖女 】" NOR;
        else if(avg<10000) 
                return HIW "【 妖  精 】" NOR;  
        else if(avg<100000) 
                return HIW "【 女  魔 】" NOR;
        else if(avg<500000) 
                return HIW "【"+at+"魔女】" NOR;        
        else 
                return HIW "【"+at+"明王】" NOR;

if ( ob->query("family/family_name") == "陷空山无底洞" )
                if(avg<1000) 
                return YEL "【 小妖女 】" NOR;
        else if(avg<10000) 
                return YEL "【 妖  精 】" NOR;  
        else if(avg<100000) 
                return YEL "【 女  魔 】" NOR;
        else if(avg<500000) 
                return YEL "【"+at+"妖女】" NOR;        
        else 
                return YEL "【"+at+"天魔】" NOR;

        break;
case "bonze":           
        if(dx<1000) 
                return HIY "【 小尼姑 】" NOR;
        else if(dx<10000) 
                return HIY "【 小师太 】" NOR;  
        else if(dx<100000) 
                return HIY "【 圣  尼 】" NOR;
        else if(dx<500000) 
                return HIY "【"+at+"神尼】" NOR;        
        else 
                return HIY "【"+at+"菩萨】" NOR;
        break;
case "taoist":                     
        if(dx<1000) 
                return HIG "【 女道童 】" NOR;
        else if(dx<10000) 
                return HIG "【 小道姑 】" NOR;  
        else if(dx<100000) 
                return HIG "【 玄  女 】" NOR;
        else if(dx<500000) 
                return HIG "【"+at+"玄女】" NOR;        
        else 
                return HIG "【"+at+"圣母】" NOR;
        break;
case "shen":            
        if(avg<1000) 
                return HIC "【 小仙女 】" NOR;
        else if(avg<10000) 
                return HIC "【 仙  姑 】" NOR;  
        else if(avg<100000) 
                return HIC "【 神  女 】" NOR;
        else if(avg<500000) 
                return HIC "【"+at+"玄女】" NOR;        
        else 
                return HIC "【"+at+"圣女】" NOR;
        break;
case "dragon":          
        if(avg<1000) 
                return HIC "【 小宫娥 】" NOR;
        else if(avg<10000) 
                return HIC "【 母夜叉 】" NOR;  
        else if(avg<100000) 
                return HIC "【 小龙女 】" NOR;
        else if(avg<500000) 
                return HIC "【"+at+"龙女】" NOR;        
        else 
                return HIC "【"+at+"公主】" NOR;
        break;
case "scholar":
        if( (string)at=="未设" )
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return GRN "【 女学童 】" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return GRN "【 才  女 】" NOR;
                else 
                        return GRN "【 女学士 】" NOR;
        }
        else
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return GRN "【 女学童 】" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return GRN "【"+at+"秀才】" NOR;
                else 
                        return GRN "【"+at+"学士】" NOR;
        }
        break;
case "fighter":         
        if(exp<1000) 
                return HIR "【 女  兵 】" NOR;
        else if(exp<10000) 
                return HIR "【 女参将 】" NOR;  
        else if(exp<100000) 
                return HIR "【 女将军 】" NOR;
        else if(exp<500000) 
                return HIR "【"+at+"大将军】" NOR;      
        else 
                return HIR "【"+at+"大元帅】" NOR;
        break;
case "youling": 
        if(avg<1000) 
                return HIB "【阴曹小鬼】" NOR;
        else if(avg<10000) 
                return HIB "【迷魂女鬼】" NOR;  
        else if(avg<100000) 
                return HIB "【幽冥女使】" NOR;
        else if(avg<500000) 
                return HIB "【"+at+"修罗】" NOR;        
        else 
                return HIB "【"+at+"女王】" NOR;
        break;  
case "dancer":
        return GRN "【 舞  妓 】" NOR;  
        break;
default:                        
        if (age <= 16)
                                    return HIM "【 少  女 】"NOR;
                                else
                                    return CYN "【 民  妇 】"NOR;
//------------------end rank for girls--------------------
                                }
                        }
//begin 男性：
        default:
                switch(wizhood(ob)) 
                {
                        case "(admin)":         return HIY "【 天  神 】" NOR;
                        case "(arch)":                  return GRN "【 巫  师 】" NOR;
                        case "(wizard)":                return GRN "【 巫  师 】" NOR;
                        case "(apprentice)":                return GRN "【见习巫师】" NOR;
                                case "(immortal)":               return GRN "【客座巫师】" NOR;
                        case "(elder)":                     return GRN "【荣誉玩家】" NOR;
                        default:
                                switch(ob->query("class")) 
                                {
//------------------rank for men--------------------
case "xiake":
        if(dx<1000) 
                return HIC "【 剑  童 】" NOR;
        else if(dx<10000) 
                return HIC "【 剑  士 】" NOR;
        else if(dx<100000) 
                return HIC "【 剑  客 】" NOR;
        else if(dx<500000) 
                return HIC "【"+at+"剑仙】" NOR;
        else 
                return HIC "【"+at+"剑圣】" NOR;
case "xian":                    
        if(dx<1000) 
                return RED "【 仙  童 】" NOR;
        else if(dx<10000) 
                return RED "【 散  仙 】" NOR;  
        else if(dx<100000) 
                return RED "【 大  仙 】" NOR;
        else if(dx<500000) 
                return RED "【"+at+"天王】" NOR;        
        else if(dx<1000000) 
                return RED "【"+at+"真君】" NOR;
        else 
                return RED "【"+at+"天尊】" NOR;
        break;
case "yaomo":
if ( ob->query("family/family_name") == "火云洞" )
        if(avg<1000) 
                return RED "【 小  妖 】" NOR;
        else if(avg<10000) 
                return RED "【 妖  怪 】" NOR;  
        else if(avg<100000) 
                return RED "【 护  法 】" NOR;
        else if(avg<500000) 
                return RED "【"+at+"护法】" NOR;        
        else if(avg<1000000) 
                return RED "【"+at+"洞主】" NOR;
        else 
                return RED "【"+at+"大圣】" NOR;
        if ( ob->query("family/family_name") == "盘丝洞" )
        if(avg<1000) 
                return MAG "【 小  魔 】" NOR;
        else if(avg<10000) 
                return MAG "【 精  灵 】" NOR;  
        else if(avg<100000) 
                return MAG "【 魔  鬼 】" NOR;
        else if(avg<500000) 
                return MAG "【 "+at+"精 】" NOR;        
        else if(avg<1000000) 
                return MAG "【"+at+"老怪】" NOR;
        else 
                return MAG "【"+at+"魔尊】" NOR;
 if ( ob->query("family/family_name") == "大雪山" )

                if(avg<1000) 
                return HIW "【 小  妖 】" NOR;
        else if(avg<10000) 
                return HIW "【 妖  怪 】" NOR;  
        else if(avg<100000) 
                return HIW "【 妖  仙 】" NOR;
        else if(avg<500000) 
                return HIW "【 "+at+"怪 】" NOR;        
        else if(avg<1000000) 
                return HIW "【"+at+"老魔】" NOR;
        else 
                return HIW "【"+at+"明王】" NOR;
 if ( ob->query("family/family_name") == "陷空山无底洞" )

                if(avg<1000) 
                return YEL "【 小  妖 】" NOR;
        else if(avg<10000) 
                return YEL "【 妖  怪 】" NOR;  
        else if(avg<100000) 
                return YEL "【 妖  仙 】" NOR;
        else if(avg<500000) 
                return YEL "【"+at+"妖王】" NOR;        
        else if(avg<1000000) 
                return YEL "【"+at+"老妖】" NOR;
        else 
                return YEL "【"+at+"天魔】" NOR;

        break;
case "bonze":           
        if(dx<1000) 
                return HIY "【 小和尚 】" NOR;
        else if(dx<10000) 
                return HIY "【 比  丘 】" NOR;  
        else if(dx<100000) 
                return HIY "【 圣  僧 】" NOR;
        else if(dx<500000) 
                return HIY "【"+at+"禅师】" NOR;        
        else if(dx<1000000) 
                return HIY "【"+at+"长老】" NOR;
        else 
                return HIY "【"+at+"佛】" NOR;
        break;
case "taoist":                      
        if(dx<1000) 
                return HIG "【 小道士 】" NOR;
        else if(dx<10000) 
                return HIG "【 道  士 】" NOR;  
        else if(dx<100000) 
                return HIG "【 道  长 】" NOR;
        else if(dx<500000) 
                return HIG "【"+at+"天师】" NOR;        
        else if(dx<1000000) 
                return HIG "【"+at+"真人】" NOR;
        else 
                return HIG "【"+at+"祖师】" NOR;
        break;
case "shen":            
        if(avg<1000) 
                return HIC "【 小仙童 】" NOR;
        else if(avg<10000) 
                return HIC "【 仙  童 】" NOR;  
        else if(avg<100000) 
                return HIC "【 小  仙 】" NOR;
        else if(avg<500000) 
                return HIC "【"+at+"仙人】" NOR;        
        else 
                return HIC "【"+at+"神仙】" NOR;
        break;
case "dragon":          
        if(avg<1000) 
                return HIC "【 虾  兵 】" NOR;
        else if(avg<10000) 
                return HIC "【 蟹  将 】" NOR;  
        else if(avg<100000) 
                return HIC "【巡海夜叉】" NOR;
        else if(avg<500000) 
                return HIC "【"+at+"夜叉】" NOR;        
        else if(avg<1000000) 
                return HIC "【"+at+"天龙】" NOR;
        else 
                return HIC "【"+at+"海王】" NOR;
        break;
case "scholar":
        if( (string)at=="无名" )
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return RED "【 童  生 】" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return RED "【 秀  才 】" NOR;
                else 
                        return RED "【 大学士 】" NOR;
        }
        else
        {
                if((int)ob->query_skill("literate", 1)<20) 
                        return RED "【 童  生 】" NOR;
                else if((int)ob->query_skill("literate", 1)<100) 
                        return RED "【"+at+"秀才】" NOR;
                else 
                        return RED "【"+at+"学士】" NOR;
        }
        break;
case "fighter":         
        if(exp<1000) 
                return HIR "【 小  兵 】" NOR;
        else if(exp<10000) 
                return HIR "【 小  校 】" NOR;  
        else if(exp<100000) 
                return HIR "【 参  将 】" NOR;
        else if(exp<500000) 
                return HIR "【"+at+"将军】" NOR;        
        else if(exp<1000000) 
                return HIR "【"+at+"大将军】" NOR;
        else 
                return HIR "【"+at+"大元帅】" NOR;
        break;
case "youling": 
        if(avg<1000) 
                return HIB "【阴曹小鬼】" NOR;
        else if(avg<10000) 
                return HIB "【勾魂使者】" NOR;  
        else if(avg<100000) 
                return HIB "【地府判官】" NOR;
        else if(avg<500000) 
                return HIB "【"+at+"无常】" NOR;        
        else if(avg<1000000) 
                return HIB "【"+at+"王】" NOR;
        else 
                return HIB "【"+at+"冥王】" NOR;
        break;
default:
        if (age <= 16)
                                            return "【 少  年 】";
                                        else
                                            return CYN"【 平  民 】"NOR;
//------------------end rank for men--------------------
                                }
                        }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "女性":
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 18 ) return "小师太";
        else return "师太";
        break;
case "shen":
        if( age < 18 ) return "小仙姑";
        else return "仙姑";
        break;
case "taoist":
        if( age < 18 ) return "小仙姑";
        else return "仙姑";
        break;
case "xian":
        if( age < 18 ) return "小仙姑";
        else return "仙姑";
        break;
default:
        if( age < 18 ) return "小姑娘";
        else if( age < 50 ) return "姑娘";
        else return "婆婆";
        break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) 
                        {
case "xian":
        if( age < 18 ) return "小神仙";
        else if( age < 50 ) return "仙兄";
        else return "老神仙";
        break;
case "shen":
        if( age < 18 ) return "小神仙";
        else if( age < 50 ) return "仙兄";
        else return "老神仙";
        break;
case "bonze":
        if( age < 18 ) return "小师父";
        else if( age < 50 ) return "大师";
        else return "长老";
        break;
case "taoist":
        if( age < 18 ) return "小道爷";
        else if( age < 50 ) return "道兄";
        else return "道长";
        break;
case "fighter":
        if( age < 18 ) return "小将军";
        else if( age < 50 ) return "大将军";
        else return "老将军";
        break;
case "scholar":
        if( age < 18 ) return "小相公";
        else if( age < 50 ) return "相公";
        else return "老先生";
        break;
case "swordsman":
        if( age < 18 ) return "小老弟";
        else if( age < 50 ) return "壮士";
        else return "老前辈";
        break;
default:
        if( age < 18 ) return "小兄弟";
        else if( age < 50 ) return "壮士";
        else return "老爷子";
        break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "女性":
                        switch(ob->query("class")) 
                        {
case "xian":
        if(age < 30) return "小妖精";
        else if(age < 50) return "妖女";
        else return "老妖婆";
        break;
case "yaomo":
        if(age < 30) return "小妖女";
        else if(age < 50) return "妖女";
        else return "老妖婆";
        break;
case "shen":
        if(age < 30) return "小妖女";
        else if(age < 50) return "妖女";
        else return "老妖婆";
        break;
case "bonze":
        if(age < 30) return "小贼尼";
        else if(age < 50) return "贼尼";
        else return "老贼尼";
        break;
case "taoist":
        if(age < 30) return "小妖女";
        else if(age < 50) return "妖女";
        else return "老妖婆";
        break;
default:
        if( age < 30 ) return "小贱人";
        else if(age < 50) return "贱人";
        else return "死老太婆";
        break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) 
                        {
case "xian":
        if( age < 50 ) return "死妖怪";
        else return "老妖怪";
        break;
case "yaomo":
        if( age < 50 ) return "死妖怪";
        else return "老妖怪";
        break;
case "bonze":
        if( age < 50 ) return "死秃驴";
        else return "老秃驴";
        break;
case "taoist":
        return "死牛鼻子";
        break;
case "scholar":
        if( age < 18 ) return "小书呆子";
        else if( age < 50 ) return "臭书呆子";
        else return "老童生";
        break;
default:
        if( age < 18 ) return "小王八蛋";
        else if( age < 50 ) return "臭贼";
        else return "老匹夫";
        break;
case "shen":
        return "死牛鼻子";
        break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "女性":
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "贫尼";
        else return "老尼";
        break;
default:
        if( age < 30 ) return "小女子";
        else return "妾身";
        break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "贫僧";
        else return "老纳";
        break;
case "taoist":
        return "贫道";
        break;
case "scholar":
        if( age < 30 ) return "晚生";
        else return "不才";
        break;
default:
        if( age < 50 ) return "在下";
        else return "老头子";
        break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        // added by snowcat
        age = ob->query("fake_age");
        if (age == 0) age = ob->query("age");
        switch(ob->query("gender")) 
        {
                case "女性":
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "贫尼";
        else return "老尼";
        break;
default:
        if( age < 50 ) return "本姑娘";
        else return "老娘";
        break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) 
                        {
case "bonze":
        if( age < 50 ) return "大和尚我";
        else return "老和尚我";
        break;
case "taoist":
        return "本山人";
        break;
case "scholar":
        if( age < 50 ) return "本相公";
        else return "老夫子我";
        break;
default:
        if( age < 18 ) return "你家小爷我";
        else if( age < 50 ) return "大爷我";
        else return "你爷爷我";
        break;
                        }
        }
}
string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }


        return "错误：rankd.c -> query_self_close()\n";
}

string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}
string imud_query_self_close(object ob,int age,string gender)
{
        int a1, a2;
        if (objectp(ob))
        {
                a1=ob->query("age");
                a2=age;
        } 
        else 
        {       
                a1 = this_player()->query("age");
                a2 = 0;
        }
        switch (gender) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}
string imud_query_close(object ob,int age,string gender)
{
        int a1, a2;

        if (objectp(ob))
        {
                a1=ob->query("age");
                a2=age;
        } else 
        {       
                a1 = this_player()->query("age");
                a2 = 0;
        }
                                                        
        switch (gender) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}
varargs string new_short( object ob ,int withshort)
{
        mixed tmp;
        string icon="", str;
        if(!objectp(ob))
        {
                CHANNEL_D->do_channel(this_player(),"chat","object参数错误！");
                return "";
        }
        if(!ob->query_temp("apply/id")||!ob->query_temp("apply/name")||!ob->query_temp("apply/short"))
                str = ob->query("name") + "(" +ob->query("id") + ")" +(!withshort?"":ob->short());
        else
                str = ob->query_temp("apply/name")[0] + "(" +ob->query_temp("apply/id")[0] + ")" +(!withshort?"":ob->query_temp("apply/short")[0]);
        if( (tmp = ob->query("icon")))
        {
                if( intp(tmp) )
                        icon = sprintf("%d",tmp);
                else if( stringp(tmp) )
                        icon = tmp;
                else
                        icon = "00901";
        }
        else
        {
                if(userp(ob)) icon=( ob->query("gender") == "男性" )?"1174":"1173";
                else if(living(ob)) icon = "00901";
                else icon = "00961";
        }
        while( sizeof(icon)<5 )
                icon = "0" + icon;

        return str + icon;
}



