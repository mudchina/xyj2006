inherit ITEM;

void create()
{
	set_name("下棋指南",({"xiaqi zhinan","xiaqi","zhinan"}) );
	set("long","请用 read zhinan 阅读怎样在品棋亭下棋。\n");
	set_weight(5);
	set("unit","本");
	set("value",100);
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
	object me = this_player();
	string msg = "欢迎到品棋亭来下棋！\n" +
"
品棋亭:从长安南门->s->e->e->nu->enter

在这里您可以下围棋或五子棋，以下告诉您下棋的步骤：
一、先找好对手，然后分别用 sit black 和 sit white 入座；
二、使用 new 开始一盘新的棋局：new [-5] [-b(numbers)] [-h(numbers)]
    其中 -5 代表下五子棋，不选即为下围棋；
　　-b指定所用棋盘的大小；
    -h指定让子的数目；
　　例如：
　　围棋：new
　　十五乘十五的五子棋：new -5 -b15
　　让九子围棋：new -h9
三、使用 play 轮流走棋：例如 play d4 等等。
四、使用 refresh观看棋盘。
五、使用 undo 悔棋。(目前只提供五子棋的悔棋功能。)

";
	if(arg=="zhinan" || arg=="xiaqi zhinan") {
		tell_object(me,msg);
		return 1;
	}
	 else return 0;
}

