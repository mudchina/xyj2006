//谁与争锋·/clone/misc/jincai-biao.c
//稍作修改就可以应付很多让玩家在游戏中押注的东东。

#include <ansi.h>
inherit ITEM;//继承物品
inherit F_SAVE;//继承可save的属性

mapping *all_biao;//全局变量，即储存玩家押注的所有数据
int num;//全局变量，此处为中国队目前金牌数
int jieguo;//全局变量，此处为最终结杲

//以下四行为函数声明
int do_read(string);
int do_post(string);
int do_ya(string);
void enough_rest();

void create()
{
	set_name(HIY"2000年"HIR"悉尼"HIC"奥运"HIG"竞猜表"NOR, ({ "biao"}) );
	set("long",
		"这是一个记录“谁与争锋”玩家对本届奥运会中国代表团将获得\n"
		"的金牌数的竞猜押注情况。如何押注请read rules，查看目前的\n"
		"投注情况请read biao。\n");//这两个可以按实际情况修改成：亚洲杯竞猜表等等
	set("unit", "张");
	set("no_put", 1);
	set("no_get", 1);
	set_weight(900000000);//设大点不让玩家Get
	seteuid(getuid());
	restore();
}

void init()
{
	add_action("do_read", "read");
	add_action("do_post", "post");
	add_action("do_ya","ya");
	add_action("do_duijiang","duijiang");
}

string query_save_file()
{
	return DATA_DIR + "board/jingcai-biao";//你可以定义一个储存文件的路径
}

int do_ya(string arg)//玩家下注
{
	int i,j;
	object me,ob;
	mapping biao;
	
	me = this_player();
	if(query("end_ya"))             //表示停止下注，由巫师在do_post()函数里加入
    	return notify_fail("截止时间已过，等2004年奥运会再来押吧......\n");
	if (query_temp("busy"))        //防止多人同意押注产生意外
		return notify_fail("稍候........\n");
	if(me->query("du"))            //调玩家身上的参数
   	    return notify_fail("每人只能押一次！\n");
	if(!arg || sscanf(arg, "%d %d", i,j) != 2)//分析玩家指令
		return notify_fail("命令格式：ya <枚数> <多少两黄金>\n");
    if(i<1||i>50)                  //排除一些不可能的押注可能
		return notify_fail("不可能吧？你是不是想白送钱？\n");
	if(j < 1)                     //至少1gold
		return notify_fail("你想白赚啊？\n");
    if(j>1000)                    //上限，可以自由调整
	    return notify_fail("押得太多，请少于1000。\n");
    if((int)j>me->query("balance")/10000) //钱庄的存款不够押的钱
        return notify_fail("这里不收现金！到钱庄存够了钱再来！”\n");
	
	message_vision("$N想了半天大声喊道：“我认为中国队能拿到 "+i+" 枚金牌！押 "+j+" 两黄金！”\n",me);
	me->add("balance",-j*10000);
	tell_object(me,"钱庄已经扣除了你押下的"+j+"两黄金。请等候闭幕结果吧！\n");
    
    me->set("du/win",i);//在玩家身上设下参数这个是赌的结果
    me->set("du/gold",j);//这个是押的钱数

    biao = ([
    	"id":me->query("id"),
    	"name":me->query("name"),
    	"win":i,
    	"gold":j,
    	]);//这是一个记录该玩家押注数据的映射
    if( !pointerp(all_biao) ) all_biao = ({ biao });
	else all_biao += ({ biao });
	save();//储存进这个文件对应的.o文件里
    
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);//1秒后取消busy
	return 1;
}

int do_post(string arg)//巫师专用，更新情况
{
	int i;
	object me= this_player();

	if(!wizardp(me)) return 0;
	if( !arg)
		return notify_fail("你要更新什么？\n");
	if(sscanf(arg, "%d", i)==1 )//只加数字表示更新即时情况
	{
		if( i > num )//记住，这个num是在文件头定义的，是对于这个文件内任何函数都可公用的
		{
			shout( HIW"〖赌场消息〗：某位巫师将奥运竞猜表上的中国金牌数由 "+num+" 枚更新为 "+i+" 枚！\n"NOR);
			num = i;//更新
			save();
			return 1;
		}
		else return notify_fail("金牌数会越挣越少吗？\n");
	}
	if(sscanf(arg, "-last %d", i)==1 )//加-last参数，表示更新最终结果
	{
		if( i > num )
		{
			shout( HIW"〖赌场消息〗：奥运竞猜最终结果公布，是 "+jieguo+" 枚！押对的快去兑奖啊！\n"NOR);
			jieguo = i;//更新
			save();
			return 1;
		}
		else return notify_fail("金牌数会越挣越少吗？\n");
	}
	if(arg=="end")
	{
		set("end_ya",1);//停止押注
		shout( HIW"〖赌场消息〗：奥运竞猜开始停止下注，请关注比赛结果！\n"NOR);
		save();
		return 1;
	}
	return notify_fail("你要更新的金牌数是多少？\n");
}

int do_read(string arg)//玩家查看
{
	int i,j,k;
	object me;
	string name,str,str1,str2;
	mapping biao;
	
	me = this_player();
	
	if(arg == "rules")
	{
		write("悉尼奥运会，中国代表团究竟能获多少枚金牌？欢迎在此押注：\n"
			"押注者以黄金为单位，最高押1000 gold，最少 1 gold。现金不\n"
			"收，必须先存进钱庄。押赌后钱庄直接扣钱。押赌时间到20号截\n"
			"止。押小于15块的数字一赔十二，押15至22之间的数字是一赔六，\n"
			"22以上的数字是一赔十五，比赛结束，押中者按倍数返还黄金，\n"
			"不中者则罢。想好了后就 "HIY"ya <枚数> <多少两黄金>"NOR"\n"
			"当然每个ID只能押一次，押过不许后悔！\n");//这个规则根据每次巫师设计的定
		write("请使用duixian指令，你的奖金将自动进入你帐户。\n");
		return 1;
	}
	if(arg == "biao")
	{
		if(num)//有了金牌的参数
			write("★★★★★★★★★★★★★★★★★★★★★★★★\n"
			HIG"本届奥运会，中国获 "HIY+num+HIG" 枚金牌！(开始兑奖duijiang)");
		if( !pointerp(all_biao) || !sizeof(all_biao) ) //表示还没有数据
		{
			write("\n还没有人开始投注。\n");
			return 1;
		}
		write("已有 "+sizeof(all_biao)+" 个玩家投注：\n"
		HIC"玩家名　　　　预测金牌数　押黄金数｜玩家名　　　　预测金牌数　押黄金数\n"
		"—————————————————｜—————————————————\n");
		str1 = HIM"已经兑过奖的玩家：\n"NOR;
		str2 = HIM"还未兑过奖的玩家：\n"NOR;
		j = 0;
		k = 0;
		for(i=0; i<sizeof(all_biao); i++)//all_biao也是全局变量，看文件头
		{
			name = all_biao[i]["name"]+"("+all_biao[i]["id"]+")";//取出每个押注玩家的名字
			if(!(int)all_biao[i]["dui"])//dui这个参数是在兑奖后加入的,这表示没兑奖的，加入str2
			{
				str2 += sprintf("%-18s    %-5d  %-5d%s",name,(int)all_biao[i]["win"],
					(int)all_biao[i]["gold"],j%2?"\n":"｜",);
				j++;//j和下面的k都是为了两个一行，分行用的j%2就是除2剩下的余数，为0就换行
			}
			else//有dui参数的，记入str1
			{
				str1 += sprintf("%-18s    %-5d  %-5d%s",name,(int)all_biao[i]["win"],
					(int)all_biao[i]["gold"],k%2?"\n":"｜",);
				k++;
			}
		}
/*这里的str1与str2可以根据不同的情况表现不同的信息,比如在比赛中，可以
根据all_biao[i]["win"]是否大于num，即目前的金牌数，判断哪些玩家还有希
望，哪些玩家已经被淘汰：str1="无获奖希望的玩家"：......
*/
		write(str1+"\n"+str2+"\n");//显示信息
		return 1;
	}
	else
		write("你要看什么？押注规则请read rules，押注情况请read biao。\n");
	return 1;
}

void enough_rest()
{
	delete_temp("busy");
}

int do_duijiang()//兑奖指令
{
	int i,j;
	object me,ob;
	mapping biao,du;

	me = this_player();
	
	if(!jieguo)//没有jieguo就表示没有开始兑奖
		return notify_fail("还未到兑奖时间！\n");
	if(!du = me->query("du"))//查找身上参数
		return notify_fail("你没有奖的，或者已经兑过奖了！\n");
	if (query_temp("busy"))
		return notify_fail("稍候........\n");
	set_temp("busy",1);
	if(du["win"]==jieguo)//与结果相符，即中奖
	{
		if(du["win"]>22) i = du["gold"]*15;//1赔15
		else if(du["win"]>14) i = du["gold"]*6;//1赔6
		else		i = du["gold"]*12;//1赔12
//这些都可以按照设定的规则来定
		write("你押 "+du["win"]+" 块金牌 "+du["gold"]+" 两黄金，按规定得奖金 "+i+" 两黄金，已划入你的钱庄帐户！\n");
		shout( HIW"〖赌场消息〗："+me->name()+"兑奖得到 "+i+" 两黄金！\n"NOR);	
		me->add("balance",i*10000);
	}
	else//没有对的也来个空门奖吧
	{
		ob = new("/clone/food/jitui");
		ob->move(me);
		write("你没押对，但发一个安慰奖，送你一根鸡腿吧！\n");
		message_vision(HIY"竞猜表上头突然金光一闪，“扑”地掉下一根油光光的鸡腿，正好掉进$N的手中。\n"NOR,me);
	}
	for(j=0; j<sizeof(all_biao); j++)
	{
		if(all_biao[j]["id"]==me->query("id"))
			all_biao[j]["dui"] = 1;//表示此人兑过奖了
	}
	save();//存盘
	me->delete("du");//身上参数取消，以防重复兑奖
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	return 1;
}

