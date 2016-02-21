//Cracked by Roath
#include <ansi.h>
#include <mudlib.h>
#define TOPTEN_RICH 	"/topten/topten/rich.txt"
#define TOPTEN_QUESTS 	"/topten/topten/quests.txt"
#define TOPTEN_PKER	"/topten/topten/pker.txt"
#define TOPTEN_NKER 	"/topten/topten/nker.txt"
#define TOPTEN_EXP	"/topten/topten/exp.txt"
#define TOPTEN_DX	"/topten/topten/dx.txt"
#define TOPTEN_FORCE	"/topten/topten/force.txt"
#define TOPTEN_PER	"/topten/topten/per.txt"
#define TOPTEN_AGE	"/topten/topten/age.txt"
#define TOPTEN_TASK	"/topten/topten/task.txt"
#define TOPTEN_MANA	"/topten/topten/mana.txt"
#define RICH_B 		CYN"幻想西天十大"HIC"富豪(RICH）"NOR
#define QUESTS_B        CYN"幻想西天十大"HIC"解迷高手（QUESTS）"NOR
#define PKER_B 		CYN"幻想西天十大"HIC"P K 狂魔（PKER）"NOR
#define NKER_B 		CYN"幻想西天十大"HIC"N K 高手（NKER）"NOR
#define EXP_B  		CYN"幻想西天十大"HIC"武学高手（EXP）"NOR
#define DX_B 	        CYN"幻想西天十大"HIC"道行高手（DX）"NOR
#define FORCE_B		CYN"幻想西天十大"HIC"内力高手（FORCE）"NOR
#define PER_B		CYN"幻想西天十大"HIC"美女（PER）"NOR
#define AGE_B		CYN"幻想西天十大"HIC"老前辈（AGE）"NOR
#define TASK_B		CYN"幻想西天十大"HIC"TASK高手（TASK）"NOR
#define MANA_B		CYN"幻想西天十大"HIC"法力高手（MANA）"NOR
void topten_checkplayer(object);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
string topten_query(string);
string query_type();


void topten_checkplayer(object player)
{//对于外貌等属性用先天还是后天呢？还有有些是需要有点区分的（比如男女性别）
	topten_add(player,"rich");
	topten_add(player,"quests");	
	topten_add(player,"pker");
	topten_add(player,"nker");	
	topten_add(player,"exp");
	topten_add(player,"dx");
	topten_add(player,"force");
	topten_add(player,"per");	
	topten_add(player,"age");
	topten_add(player,"task");
        topten_add(player,"mana");
	return;
}

string query_type()
{
	return HIM"西行"NOR+HIG"战记"NOR+HIY"."NOR+CHINESE_MUD_NAME+"现在有以下类型的排行榜：\n"+
		HIR"一：\t"NOR+RICH_B+"\n"+
		HIR"二：\t"NOR+QUESTS_B+"\n"+		
		HIR"三：\t"NOR+PKER_B+"\n"+
		HIR"四：\t"NOR+NKER_B+"\n"+
		HIR"五：\t"NOR+EXP_B+"\n"+
		HIR"六：\t"NOR+DX_B+"\n"+
		HIR"七：\t"NOR+FORCE_B+"\n"+
		HIR"八：\t"NOR+PER_B+"\n"+
		HIR"九：\t"NOR+AGE_B+"\n"+
		HIR"十：\t"NOR+TASK_B+"\n"+
              HIR"十一：\t"NOR+MANA_B+"\n"+
		
		NOR;
}
int topten_save(string f_name,string b_name,string str)
{
	string *astr;
	int i;
	astr=explode(str,"\n");
	str="";
	for(i=0;i<sizeof(astr)&&i<10;i++)
		str+=astr[i]+"\n";
	if(!write_file(f_name,str,1))
		return notify_fail("无法写文件"+f_name+"，权限不够!不能更新"+b_name+"!\n");
	return 1;
}

string topten_query(string type)
{
	string b_name,f_name,str,*astr,*bstr,name,id;
	int i,j,data;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "nker":
			b_name=NKER_B;
			f_name=TOPTEN_NKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per":
			b_name=PER_B;
			f_name=TOPTEN_PER;
			break;
		case "task":
			b_name=TASK_B;
			f_name=TOPTEN_TASK;
			break;
                 case "mana":
                        b_name=MANA_B;
                        f_name=TOPTEN_MANA;
                        break;
		default:
			return query_type();
	}
	if(file_size(f_name)==-1)
		return b_name+"的数据文件还没有创建！\n";
	astr=explode(read_file(f_name),"\n");
	str=HIM"西行"NOR+HIG"战记"NOR+HIY"."NOR+CHINESE_MUD_NAME+HIY"：\n"NOR+HIC+b_name+"\n";
	for(i=0;i<sizeof(astr);i++)
	{
		bstr=explode(astr[i],";");
		str+=NOR CYN"排行第"HIR+chinese_number(i+1)+NOR"：";
		for(j=0;j<sizeof(bstr);j++)
		{
			if(sscanf(bstr[j],"%s(%s)%d",name,id,data)!=3)
				return "数据错误!文件："+f_name+"第"+i+"行第"+j+"项！\n"+
					"该行数据："+bstr[j]+"\n";
			str+=name+"("+id+")\t";
		}
		str+="\n"NOR;
	}
	return str;
}
int get_all_data(object player,string type)
{
	int total;
	switch(type)
	{
		case "rich":
    total=(int)player->query("balance")+(int)player->query("money");
			break;
		case "quests":
			total=(int)player->query("quest/number");
			break;
		case "pker":
			total=(int)player->query("PKS");
			break;
		case "nker":
			total=(int)player->query("MKS");
			break;
		case "exp":
			total=(int)player->query("combat_exp");
			break;
		case "dx":
             total=(int)player->query("daoxing");
			break;
		case "force":
			total=(int)player->query("max_force");
			break;
		case "age":
			total=(int)player->query("mud_age");
			break;
		case "per":
			if (player->query("gender")!="女性")
				total=-1;
			else total=player->query_per();
			break;
		case "task":
			total=(int)player->query("task_job");
			break;
                case "mana":
			total=(int)player->query("max_mana");
			break;			
		default:
			total=-1;//用-1标志类型出错！
	}
	return total;
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,b_name,f_name;
	int i,j,k;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "nker":
			b_name=NKER_B;
			f_name=TOPTEN_NKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per":
			b_name=PER_B;
			f_name=TOPTEN_PER;
			break;
		case "task":
      	        	b_name=TASK_B;        
			f_name=TOPTEN_TASK;
			break;
                case "mana":
                        b_name=MANA_B;
                        f_name=TOPTEN_MANA;
                        break;
		default:
			return notify_fail("没有"+type+"这种排行榜！\n");
	}
	if(file_size(f_name)==-1)
		return notify_fail(b_name+"还没有创建！\n");
	str=read_file(f_name);
	astr=explode(str,"\n");
	for(i=0;i<sizeof(astr);i++)
	{
		if(strsrch(astr[i],pid)!=-1)//该行包括id则为真
		{
			if(strsrch(astr[i],";")==-1)
			//为真表示该行只有一个id，即pid
			{
				str="";
				for(j=0;j<sizeof(astr);j++)
					if(j!=i)
						str+=astr[j]+"\n";
				return topten_save(f_name,b_name,str);
			}
			else
			{
				bstr=explode(astr[i],";");
				for(j=0;j<sizeof(bstr);j++)
					if(strsrch(bstr[j],pid)!=-1)//说明该项即pid,应该去除
					{
						astr[i]="";
						for(k=0;k<sizeof(bstr);k++)
							if(k!=j)
							{
								if((k+1)!=sizeof(bstr)
									&&!((j+1)==sizeof(bstr)&&j==(k+1))
								)
									astr[i]+=bstr[k]+";";
								else
									astr[i]+=bstr[k];
							}
						//本来去除后j的循环应该停止,但是不影响结果
					}
				str=implode(astr,"\n");
				return topten_save(f_name,b_name,str);
			}
		}
	}
	return 1;
}

int topten_add(object player,string type)
{
	string str,name,id,b_name,f_name;
	string *astr;
	int i,j,data;
	if(wizardp(player))//禁止巫师参加排行榜
		return 0;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "quests":
			b_name=QUESTS_B;
			f_name=TOPTEN_QUESTS;
			break;			
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "nker":
			b_name=NKER_B;
			f_name=TOPTEN_NKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "dx":
			b_name=DX_B;
			f_name=TOPTEN_DX;
			break;
		case "force":
			b_name=FORCE_B;
			f_name=TOPTEN_FORCE;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "per":
			b_name=PER_B;
			f_name=TOPTEN_PER;
			break;
		case "task":
			b_name=TASK_B;
			f_name=TOPTEN_TASK;
			break;
                case "mana":
                        b_name=MANA_B;
                        f_name=TOPTEN_MANA;
                        break;	
		default:
			return notify_fail("没有"+type+"这种排行榜！\n");
	}
	if(!objectp(player)||!userp(player))
		return 0;
	if(file_size(f_name)==-1)
	{
		str=player->short()+"("+player->query("id")+")"+
			get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	//主要程序！
	if(get_all_data(player,type)==-1)
		return notify_fail("数据查询错误，可能是查询类型错误！\n");
	//应该先排除该player的id!
	topten_del(player->query("id"),type);
	str=read_file(f_name);
	astr=explode(str,"\n");
	i=0;
	while(i<sizeof(astr))
	{
		if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3)
			if(sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)
				return notify_fail(b_name+"文件数据错误！请呼叫巫师！\n");
		str="";
		if(data<(int)get_all_data(player,type))
		{
			//单独加入，暂时没考虑人数超过十行！
			for(j=0;j<sizeof(astr);j++)
			{
				if(j==i)
					str+=player->query("name")+"("+player->query("id")+")"+
						get_all_data(player,type)+"\n";
				str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		else
		if(data==(int)get_all_data(player,type))
		{
			//并排加入
			for(j=0;j<sizeof(astr);j++)
			{
			//	if(j==i)
			//		str+=astr[j]+";"+player->query("name")+
			//			"("+player->query("id")+")"+get_all_data(player,type)+"\n";
			//	else
					str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		i++;
	}
	if(sizeof(astr)<10)
	{
		str=implode(astr,"\n")+"\n"+player->query("name")+"("+player->query("id")+
			")"+get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	return 0;
}
