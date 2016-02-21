//JackyBoy Write these Functions for CCTX's TOPTEN!
//Updated in 1999/3/8

#include <ansi.h>
#include <mudlib.h>
#include "/topten/topten.h";

void topten_checkplayer(object player);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
string topten_query(string);

void topten_checkplayer(object player)
{ 
	//对于外貌等属性用先天还是后天呢？还有有些是需要有点区分的（比如男女性别）
	if (wizardp(player)) 
	 {
	  topten_del(player->query("id"),"rich");
	  topten_del(player->query("id"),"pker");
	  topten_del(player->query("id"),"exp");
	  return ;
	 }
	topten_add(player,"rich");
	topten_add(player,"pker");
	topten_add(player,"exp");
	return;
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
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		default:
			return "没有"+type+"这种排行榜！\n";
	}
	if(file_size(f_name)==-1)
		return b_name+"的数据文件还没有创建！\n";
	astr=explode(read_file(f_name),"\n");
	str=HIY+CHINESE_MUD_NAME+"：\n"NOR+HIC+b_name+"\n";
	for(i=0;i<sizeof(astr);i++)
	{
		bstr=explode(astr[i],";");
		str+=HIC"排行第"+chinese_number(i+1)+"："HIW;
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
			total=(int)player->query("balance");
			break;
		case "pker":
			total=(int)player->query("PKS");
			break;
		case "exp":
			total=(int)player->query("combat_exp");
			break;
		default:
			total=-1;//用-1标志类型出错！
	}
	return total;
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,name,id,b_name,f_name;
	int i,j,k,money;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
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
	string str,name,id,str1,b_name,f_name;
	string *astr;
	int i,j,data;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		default:
			return notify_fail("没有"+type+"这种排行榜！\n");
	}
	if(!objectp(player)||!userp(player))
		return 0;
	if(file_size(f_name)==-1)
	{
		str=player->query("name")+"("+player->query("id")+")"+
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
//                                str+=HIM+RANK_D->query_rank(player)+NOR+player->short(1)+NOR;
				str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		/*
		else
		if(data==(int)get_all_data(player,type))
		{
			//并排加入
			for(j=0;j<sizeof(astr);j++)
			{
				if(j==i)
					str+=astr[j]+";"+player->query("name")+
						"("+player->query("id")+")"+get_all_data(player,type)+"\n";
				else
					str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		
	        }
	        */  
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