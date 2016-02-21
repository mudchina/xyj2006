#include <ansi.h>

inherit NPC;
string start();
int dn();
void end_game();
int compare_score(object ob1, object ob2);
string end_time();

object ob = this_object();
object *users = ({});
object *tUsers = ({});
object *ctUsers = ({});

void create()
{
  set_name(HIY"大鸟王子"NOR, ({ "daniao wangzi", "wangzi" }) );
  set("title",HIW"ＣＳ大赛报名大使"NOR);
  set("gender", "男性");
  set("age", 20);
  set("combat_exp", 300000+random(20000));
  set("attitude", "heroism");
  set("no_clean_up",1);
  set("str", 30);
  set("per", 30);
  set("max_kee", 600);
  set("max_gin", 600);
  set("force", 600);
  set("max_force", 600);
  set("force_factor", random(20)+25);
  set_skill("unarmed", 80);
  set_skill("parry", 80);
  set_skill("dodge", 80);
	set("inquiry", ([
		"比赛" : (: start :),
		"大赛" : (: start :),
		"game" : (: start :),
		"cs" : (: start :),
		"cslist" : (: dn :),
		"参加人" : (: dn :),
		"参加者" : (: dn :),
		]) );  
  setup();

  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
}

void init()
{
   add_action("do_baoming", "baoming");
   ::init();
}

/******************************************************************************
todo:
	开始报名。
******************************************************************************/
string start()
{
	object me;
	me = this_player();
	if ( ob->query("start_baoming") ) return "报名已经开始，请用指令baoming参加游戏。\n";
	if ( ob->query("end_baoming") ) return "这次比赛已经开始，等下一次吧！\n";
	if ( ob->query("no_baoming") ) return end_time();
	if ( me->query("daoxing") <= 500000 ) return "你道行太浅，只怕召集不到多少人。\n";
	if ( me->query("combat_exp") <= 500000 ) return "你实战经验太少，还是先去别的地方锻炼锻炼吧。\n";
	ob->set("start_baoming",1);
	message( "system", HIR"【"+HIY"大鸟王子"+HIR"】： "HIR+me->query("family/family_name")+HIY""+me->query("name")+HIR"前来邀请各路妖仙参加ＣＳ大赛,愿意参加者请在五分钟内报名。\n" NOR, users() );
          call_out("choose_faction",5*60);
  return "比赛系统已经启动，请快来报名(baoming)吧。\n";
}

/******************************************************************************
todo:
	参赛者报名。
******************************************************************************/
int do_baoming()
{
	int i ;
	object me;
	me = this_player();

	if ( ob->query("end_baoming")) return notify_fail("这次ＣＳ大赛已经停止报名。\n");
	if ( !ob->query("start_baoming") ) return notify_fail("ＣＳ大赛还没开始报名呢。\n");
if ( me->query_temp("no_heal_up/bian") ) return notify_fail("比赛的时候还是不要变身了吧。\n");
	if ( me->query_temp("in_hell") ) return notify_fail("灵魂是不能参加比赛的。\n");
	if ( me->query("daoxing") <= 500000 ) return notify_fail("你道行太浅，还是不要参加了。\n");
	if ( me->query("combat_exp") <= 500000 ) return notify_fail("你实战经验太少，还是先去别的地方锻炼锻炼吧。\n");

	
	// 判断是否重复报名或者同ip 同port 报名
	for ( i = 0; i < sizeof(users); i++ )
	{
		if ( users[i] == me ) return notify_fail("你不是来报过名了吗？\n");

//                if ( (users[i]->query_ip_number() == me->query_ip_number()) && (users[i]->query_ip_port() == me->query_ip_port()) )
//                       return notify_fail("你不能同时开两个或两个以上id参加比赛。\n");
	}
	
	// Add this new user
	users += ({ me });
	
	message( "chat", HIC"【"+HIY"大鸟王子"+HIC"】： "HIC+me->query("family/family_name")+HIY""+me->query("name")+HIC"报名参加ＣＳ大赛。\n" NOR, users() );
	return 	1;
}

/******************************************************************************
todo:
	决定参赛者组别。
	先按score排序，再选择：(现已改为随机分组，不再按score 排序)
	奇数者为t（纵火犯）；偶数者为ct（大侠）。
******************************************************************************/
void choose_faction()
{
	int i,j;
	object *list;
	string cslist;
	string lastType;

  list = ({});
	
	// 参赛人数太少，取消比赛。
	if ( sizeof(users)<2 ) {
		message( "system", HIR"【"+HIY"大鸟王子"+HIR"】： 由于参赛人数少于十人，比赛取消。\n" NOR, users() );
		users = ({});
	  tUsers = ({});
	  ctUsers = ({});
		end_game();
		return;
	}
	ob->set("end_baoming",1);
	
	// 设置每个人的组别，并告诉其本人。
  
  
  /*******************************************************************
 
  for ( i = 0; i < sizeof(users); i++ )
  {
  	j = random(sizeof(users)-i);
		message( "system", HIR"【"+HIY"大鸟王子"+HIR"】："+users[i]->query("id")+users[j]->query("id")+" \n" NOR, users() );
  	list += ({users[j]});
  	users[j] = users[sizeof(users)-i];       // 这一句有问题。。。。。。。。。。。。。。。
  }
  以上部分为更改后随机分组方式。
  *******************************************************************/
  // 按score 分组,为了防止玩家利用此分组方式取得奖励改成两两随机分组
  list = sort_array(users, (: compare_score :) );      
  users = list;
	for ( i = 0; i < sizeof(users); i++ )
	{
		string type;
		type = i%2 ? (lastType == "t" ? "ct" : "t") : (random(2) ? "t" : "ct");
		lastType = type;
		users[i]->set_temp("pkgame", type);
		message( "tell", HIR"【" + HIY"大鸟王子" + HIR"】： 从现在开始你是"BLINK HIY + 
			(type == "t" ? "纵火犯" : "大侠") +
			HIR"。\n" NOR, users[i] );
		if (type == "t")
			tUsers += ({ users[i] });
		else
			ctUsers += ({ users[i] });
	}

/*
	// 输出组员名单
	cslist = HIR"【"+HIY"大鸟王子"+HIR"】： 系统choose结果：\n" NOR;
	cslist += "纵火犯组：";
	for ( i = 0; i < sizeof(users); i+=2 )
	{
		cslist += users[i]->query("name") + "	";
	}
	cslist += "\n";
	cslist += "大侠组：";
	for ( i = 1; i < sizeof(users); i+=2 )
	{
		cslist += users[i]->query("name") + "	";
	}
	cslist += "\n";
	message( "system", cslist, users() );
*/	
	users = ({});
	tUsers = ({});
	ctUsers = ({});
	message( "system", HIR"\n\n【"+HIY"大鸟王子"+HIR"】： CS大赛正式开始！\n\n" NOR, users() );
	ob->set("no_baoming",1);
	ob->delete("start_baoming");	
	call_out("wait_start",3);
	return;
}

void wait_start()
{
	"/cmds/usr/pkgame"->main(0,"start");
}
/******************************************************************************
todo:
	User按score排序回调函数。
******************************************************************************/
int compare_score(object ob1, object ob2)
{
    int score1,score2;

    score1 = "/cmds/usr/top"->get_score(ob1);
    score2 = "/cmds/usr/top"->get_score(ob2);

    return score2 - score1;
}

/******************************************************************************
todo:
	返回参赛者名单。
******************************************************************************/
int dn()
{
	int i;
	write("参赛者：\n");
	for ( i = 0; i < sizeof(users); i++ )
	{
		write(users[i]->query("name")+"	");
	}
	write("\n");
	return 1;
}		
	
/******************************************************************************
todo:
	cs游戏结束，清除内部变量。
******************************************************************************/
void end_game() {
	children("/u/take/cs")->delete("end_baoming");
	children("/u/take/cs")->delete("start_baoming");	
	call_out("restart",180*60);
}

void restart()
{
	children("/u/take/cs")->delete("no_baoming");
}

string end_time()
{
	string cStatus ;
	cStatus = chinese_number ( 180 - ( time() - ob->query("End_Time") )/ 60  ) ;
	if ( !cStatus ) return "ＣＳ系统出现数据问题，请通知"+BLINK HIY"九天(take)。\n"NOR;
	cStatus = "比赛刚结束，你等"BLINK HIY+cStatus+NOR"分钟再来吧。\n";
	return cStatus;
}
