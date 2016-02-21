/*robotd.c 2000-8-17 03:37下午*/

#include <ansi.h>
#define TIME 60

string *graph_nums=({
"■■■   ■   ■■■ ■■■ ■  ■ ■■■ ■■■ ■■■ ■■■ ■■■ ",
"■  ■   ■       ■     ■ ■  ■ ■     ■         ■ ■  ■ ■  ■ ",
"■  ■   ■       ■     ■ ■  ■ ■     ■         ■ ■  ■ ■  ■ ",
"■  ■   ■   ■■■ ■■■ ■■■ ■■■ ■■■     ■ ■■■ ■■■ ",
"■  ■   ■   ■         ■     ■     ■ ■  ■     ■ ■  ■     ■ ",
"■  ■   ■   ■         ■     ■     ■ ■  ■     ■ ■  ■     ■ ",
"■■■   ■   ■■■ ■■■     ■ ■■■ ■■■     ■ ■■■ ■■■ ",
});

string *colours=({
	HIR, HIY, HIW, HIM, YEL, HIB, MAG, RED, 
	});

mapping types=([
	"动物"	:	({
"马","骡","驴","牛","猪","羊","斑马","羚羊","鹿","驯鹿",
"长颈鹿","骆驼","单峰驼","大羊驼","大象","非洲象","犀牛",
"河马","猫","狮子","猞猁","美洲豹","老虎","华南虎","东北虎",
"牦牛","狗","獾","黄鼠狼","水獭","狐","鬣狗","狼","松鼠","河狸",
"土拨鼠","雪貂","熊","兔子","野兔","鼠","鼹鼠","田鼠","猴子",
"黑猩猩","大猩猩","猩猩","长臂猿","獭猴","食蚁兽","鸭嘴兽","袋鼠",
"树袋熊","刺猬","豪猪","蝙蝠","鲸","河豚","海豹","海象","金丝猴",
"大熊猫","小熊猫"}),
	"蔬菜"	:	({
"番茄","西红柿","芦笋","黄瓜","茄子","菜豆","甜菜","胡椒",
"甜椒","马铃薯","胡萝卜","菜花","花椰菜","蚕豆","卷心菜",
"辣椒","蒜","葱","莴苣","芹菜","韭菜","萝卜","蘑菇","雪维菜",
"细叶芹","鹰嘴豆","苣荬菜","水田芥","法国菜豆","洋姜","兵豆",
"羽扇豆","豌豆","豆瓣菜","青豆","豆芽","苦瓜","冬瓜","金瓜",
"南瓜","海带","藕","金针菇","平菇","香菇","空心菜","毛芋",
"菠菜"}),
	"水果"	:	({
"苹果","梨","杏","桃","水蜜桃","蟠桃","葡萄","香蕉","菠萝",
"李子","西瓜","香瓜","橙","柠檬","芒果","草莓","枇杷","桑椹",
"油桃","樱桃","石榴","无花果","柑子","柿子","胡桃","榛子",
"花生","枣","粟","可可","越桔","黑莓","鳄梨","红橙","番木瓜",
"石榴","荔枝","龙眼","猕猴桃","哈密瓜"}),
	"花卉"	:	({
"杜鹃花","秋海棠","仙人掌","山茶","康乃馨","灯笼花","海棠","菊花",
"大丽花","雏菊","曼陀罗","昙花","蝴蝶花","栀子","茉莉","丁香",
"百合","木兰花","玉兰花","喇叭花","水仙花","夹竹桃","兰花","牡丹",
"芍药","蝶兰","玫瑰","月季","文竹","凤仙花","郁金香","紫罗兰",
"凤眼兰"}),
]);


mapping query_know_question()
{
	string *lists;
	string quest_list, random_list, tmp_list;
	string *answers;
	int i, true_num;
	mapping answer;

	answer=([
		"quest" : "",
		"answer": 0,
	]);
	lists=keys(types);
	answers=allocate(4);
	switch(random(3))
	{
		case 0:
			quest_list=lists[random(sizeof(lists))];
			true_num=random(4);
			answers[true_num]=types[quest_list][random(sizeof(types[quest_list]))];
			for(i=0;i<4;i++)
			{
				random_list=lists[random(sizeof(lists))];
				if(i==true_num)
					continue;
				tmp_list=types[random_list][random(sizeof(types[random_list]))];
				if(random_list==quest_list ||
				member_array(tmp_list, answers)!=-1)
					i--;
				else answers[i]=tmp_list;
			}
			answer["quest"]=sprintf("请在下面物品中选出属于%s的：\n", quest_list);
			break;
		case 1:
			quest_list=lists[random(sizeof(lists))];
			true_num=random(4);
			answers[true_num]=types[quest_list][random(sizeof(types[quest_list]))];
			do{
				random_list=lists[random(sizeof(lists))];
			}while(quest_list==random_list);

			for(i=0;i<4;i++)
			{
				if(i==true_num)
					continue;
				tmp_list=types[random_list][random(sizeof(types[random_list]))];
				if(member_array(tmp_list, answers)!=-1)
					i--;
				else answers[i]=tmp_list;
			}
			answer["quest"]=sprintf("请在下面物品中选出其他三样不相同的：\n");
			break;							
		case 2:
			for(i=0;i<4;i++)
			{
				random_list=lists[random(sizeof(lists))];
				if(member_array(random_list, answers)!=-1)
					i--;
				else answers[i]=random_list;
			}
			if(!random(5))
				answers[3]="以上都不是";

			true_num=random(4);
			if(true_num==3 && answers[3]=="以上都不是")
				do{
					quest_list=lists[random(sizeof(lists))];
				}while(member_array(quest_list, answers)!=-1);
			else quest_list=answers[true_num];			
			answer["quest"]=sprintf("%s属于下面的哪类：\n", types[quest_list][random(sizeof(types[quest_list]))]);
			break;
	}
	for(i=0;i<4;i++)
		answer["quest"]+=sprintf("%d. %s\n", i, answers[i]);
	answer["answer"]=true_num;
	return answer;
}


mapping query_num_question()
{
        int temp, length, *digit, j, k, rand, flag, i;
        mapping answer;

	i=random(9000)+1000;
	answer=([
		"quest"	: "",
		"answer": 0,
	]);
        temp=i;
        for(length=1;;length++)
        {
                temp/=10;
                if(temp<1)
                        break;
        }
        temp=i;
        digit=allocate(length);
        flag=random(3);
        if(flag)
        	rand=random(length);
        else rand=i;
        do{
                digit[length-1]=temp%10;
                temp=temp/10;
                length--;
        }while(length>0);
        temp=random(sizeof(colours));
       	switch(flag)
       	{
       		case 0:
       		answer["quest"]="下面图形所组成的数字是：\n";
       		break;
       		case 1:
       		answer["quest"]="下面图形所组成的数字中，与其他的不同是第几个数字：\n";
       		break;
       		case 2:
       		answer["quest"]="下面图形所组成的数字中，颜色与其他的不同是第几个数字：\n";
       		break;
       	}
        for(k=0;k<sizeof(graph_nums);k++)
        {
        	for(j=0;j<sizeof(digit);j++)
        	switch(flag)
        	{
        		case 0:
        		answer["quest"]+=CYN+graph_nums[k][digit[j]*7..digit[j]*7+6]+NOR;
        		break;
        		case 1:
        		if(rand==j)
        			answer["quest"]+=CYN+replace_string(graph_nums[k][digit[j]*7..digit[j]*7+6],
        				"■", "□")+NOR;
        		else answer["quest"]+=CYN+graph_nums[k][digit[j]*7..digit[j]*7+6]+NOR;
        		break;
        		case 2:
        		if(rand==j)
        			answer["quest"]+=colours[temp]
        				+graph_nums[k][digit[j]*7..digit[j]*7+6]+NOR;
        		else answer["quest"]+=CYN+graph_nums[k][digit[j]*7..digit[j]*7+6]+NOR;
        		break;
        	}
                answer["quest"]+="\n";
        }
        answer["answer"]=flag?rand+1:rand;
        return answer;
}

mapping give_question()
{
	mapping question;
	
	if(random(2))
		question=query_num_question();
	else question=query_know_question();
	
	return question;
}