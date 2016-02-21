// 本程序由 yesi原做
// tomcat 修改完善

#include <ansi.h>
inherit NPC;

#define	BOOKNUM		4
#define	SHELFNUM	7
#define	RETRY		7

int ask_question();
int ask_rule();
int do_guess(string arg);
int do_list(string arg);

void create()
{
	set_name("刘好弈", ({ "liu haoyi", "liu" }));
	set("nickname", HIC"世袭子爵"NOR);

	set("gender", "男性");
	set("age", 40);
	set("long", "他目光炯炯，步履稳重，显是武功不低。\n");
	set_skill("unarmed", 20);
	set_skill("dodge", 15);
	set_temp("apply/damage", 5);

	set("combat_exp", 5000);
	set("attitude", "peaceful");
	
	set("inquiry", ([
		"题" : (: ask_question :),
		"question" : (: ask_question :),
		"规则" : (: ask_rule :),
		"rule" : (: ask_rule :),
	]) );

	setup();
	carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
        add_action("do_guess", ({"guess", "cai"}));
        add_action("do_list", ({"list", "lie"}));
	::init();
}

int ask_question()
{
	object me = this_player();
        object ob = this_object();
        object qust_ob = ob->query_temp("last_question_ob");
	int i, j, temp;
	string tempstr, result = "";

        
       if(ob->query_temp("last_question_time")!=0)
        { if (uptime() - ob->query_temp("last_question_time") > 300) //5分钟
           {
        	write("刘好弈叹了口气道：“刚才那题可能太难了，还是放弃算了！等我准备好再来猜一个吧。”\n");
                ob->delete_temp("last_question_ob");
                ob->delete_temp("last_question_time");
                qust_ob = 0;
           }
        }
        // 正有人猜
        if(qust_ob) {  
         if(qust_ob->query("id")!= me->query("id"))
          {
      
            message_vision("$N对$n摇了摇头，说：现在别人正在猜呢，别打扰人家。\n",ob,me);          
            return 1;
          }else{
             message_vision("$N对$n摇了摇头，说：你快猜呀，有时间限制呀。\n",ob,me);            
             return 1;
           }
                  
       }
         // 休息5秒
         if (uptime() - me->query_temp("last_question_time")< 5 )
           {
            message_vision("$N对$n摇了摇头，说：猜谜太伤脑筋，你先休息一下吧。\n",ob,me);
            return 1; 
          }
        
        ob->set_temp("last_question_time",uptime());  // 开始时间
	ob->set_temp("last_question_ob",this_player()); // 谁在猜
 
        if (me->query_temp("qipu_guess_win"))
		write("刘好弈笑道：“还想再解一次？好吧，等我准备好就来猜吧。”\n");
	else
		write("刘好弈道：“题目是这样的："+HIC"我有一套" + CHINESE_D->chinese_number(BOOKNUM) + "册《梅花谱》，而书房里有\n");
		write(CHINESE_D->chinese_number(SHELFNUM) + "个书架，现在我把这" + CHINESE_D->chinese_number(BOOKNUM) + "册书分别放到不同的书架上去，你只需猜出\n");
		write("来每册书放在那个书架上即可。”\n"NOR);
	write("刘好弈匆匆走进书房，不一会又出来了。\n");
	write("刘好弈点点头道：“好了，来"+HIC"猜(guess)"+NOR"吧，也可以先问我"+HIC"规则(rule)"+NOR"。”\n");
	for (i = 0; i < BOOKNUM; i++) {
		temp = random(SHELFNUM) + 1;
		tempstr = "" + temp;
		for (j = 0; j < i; j++) {
			if (tempstr == result[j..j]) {
				temp = random(SHELFNUM) + 1;
				tempstr = "" + temp;
				j = -1;
			}
		}
		result += tempstr;
	}
	me->delete_temp("qipu_guess");
	me->set_temp("qipu_guess/result", result);
	return 1;
}

int ask_rule()
{
	write("刘好弈道：“规则很简单，你每次用guess来猜你认为的结果。”\n");
	write("刘好弈道：“例如，你认为第一册在２号架上，二册在１号，三册在７号，四册在５号，那就guess 2175。”\n");
	write("刘好弈道：“我会告诉你全对（指猜对了哪个书架放了哪册的）和书架对（指只猜对哪个书架放书而没有猜对放的是哪册的）的个数。”\n");
	write("刘好弈道：“上面的例子里，如果我放的顺序是一册在１号架上，二册在５号，三册在７号，四册在４号，那么答案应该是1574。”\n");
	write("刘好弈道：“你猜对７号架上是三册，表示你有一个全对，另外你猜对１号和５号架上有书，但是没猜对是哪册，表示你有二个书架对。”\n");
	write("刘好弈道：“明白了吧？可以了就开始猜(guess)吧。”\n");
	write("刘好弈道：“记住你有" + CHINESE_D->chinese_number(RETRY) + "次机会。如果你忘了你以前猜的结果，随时可以用list来查看的。”\n");
	return 1;
}

string justify_result(string result, string guess)
{
	int i, j, temp, very_right = 0, right = 0;

	for (i = 0; i < BOOKNUM; i++) {
		for (j = 0; j < BOOKNUM; j++) {
			if (guess[i..i] == result[j..j]) {
				if (i == j) very_right++;
				else right++;
			}
		}
	}
	return "全对的有" + CHINESE_D->chinese_number(very_right) + "个，只有书架对的有" + CHINESE_D->chinese_number(right) + "个。\n";
}

int do_guess(string arg)
{
	object me = this_player();
        object ob = this_object();
        object qust_ob = ob->query_temp("last_question_ob");
	int i, j, times,pot;
	string result, tempstr1, tempstr2;

        if(qust_ob)  // 正有人猜
        { if(qust_ob->query("id")!=me->query("id"))
          {
            message_vision("$N对$n摇了摇头，说：现在别人正在猜呢，别打扰人家。\n",ob,me);          
            return 1;
          }        
       }


	if (!(result = me->query_temp("qipu_guess/result"))) return 0;
	if (!arg) return notify_fail("你要猜什么样的结果？\n");
	if (strlen(arg) != BOOKNUM) return notify_fail("不是告诉你只有" + CHINESE_D->chinese_number(BOOKNUM) + "册书吗？\n");
	for (i = 1; i < BOOKNUM; i++)
		for (j = 0; j < i; j++)
			if (arg[i..i] == arg[j..j])
				return notify_fail("不是告诉你每册书都放在不同的书架上了吗？！\n");
	me->add_temp("qipu_guess/times", 1);
	times = me->query_temp("qipu_guess/times");
	if (arg == result) {
		if (times < 5) {
			tempstr1 = "刘好弈看着你，惊讶地道：“佩服！你只用了";
			tempstr2 = "就";
		}
		else if (times < RETRY) {
			tempstr1 = "刘好弈点头道：“不错，你只用了";
			tempstr2 = "就";
		}
		else {
			tempstr1 = "刘好弈道：“你很侥幸呀，用完了";
			tempstr2 = "才";
		}
		write(tempstr1 + CHINESE_D->chinese_number(times) + "次机会" + tempstr2 + "猜出来了。”\n");
		me->delete_temp("qipu_guess");
		me->set_temp("qipu_guess_win", 1);
                pot = (RETRY - times+1)*me->query_kar()*10+random((RETRY - times+1)*me->query_kar()*10);       
           	if(pot>0) 
                { write("刘好弈对你竖起了大拇指，道：“你真行。”\n");
                  write("你得到了"+ CHINESE_D->chinese_number(pot) + "点经验 \n");
                  me->add("potential",pot);
                 }
	          me->set_temp("last_question_time",uptime());
	          ob->delete_temp("last_question_ob");
            }
	else {
		write("刘好弈道：“你猜的是" + arg + "，" + justify_result(result, arg));
		if (times < RETRY) {
			write("刘好弈道：“你还有" + CHINESE_D->chinese_number(RETRY - times) + "次机会！”\n");
			me->set_temp("qipu_guess" + times, arg);
		}
		else {
			write("刘好弈生气地说：“你可真笨！" + CHINESE_D->chinese_number(RETRY) + "次机会都没猜中！答案应该是" + result + "。”\n");
			write("刘好弈道：“下次再猜吧！”\n");
			me->delete_temp("qipu_guess");
 		        me->set_temp("last_question_time",uptime());
                        ob->delete_temp("last_question_ob");
                     }
	}
     
	return 1;
}

int do_list(string arg)
{
	object me = this_player();
        object ob = this_object();
	int i, times;
	string result;

        if(ob->query_temp("last_question_ob"))  // 正有人猜
       { if((ob->query_temp("last_question_ob"))->query("id")!=me->query("id"))
          {
            message_vision("$N对$n摇了摇头，说：现在别人正在猜呢，别打扰人家。\n",ob,me);          
            return 1;
          }        
       }

	if (!(result = me->query_temp("qipu_guess/result"))) return 0;
	times = me->query_temp("qipu_guess/times");
	write("刘好弈道：“你以前猜的结果如下：”\n");
	for (i = 1; i <= times; i++) {
		write("第" + CHINESE_D->chinese_number(i) + "次：猜" + me->query_temp("qipu_guess/guess" + i) + "，" + justify_result(result, me->query_temp("qipu_guess/guess" + i)));
	}
	return 1;
}



