// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>     // for GB_AND_BIG5 define.
#define FileName "/adm/daemons/UserNumber" // by canoe
inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
	"你", "我", "他", "她", "它", "它", "江泽民", "邓小平", "李鹏", "朱榕基",
	"自己", "某人", "尸体", "我们","你们", "他们", "大家","爸",
	"他妈的", "去你的", "毛泽东", "巫师", "他奶奶的",
});

string *default_name=({"猴子","狐狸", "老鼠", 
	               "蜻蜓","甲虫","蝴蝶","蝈蝈",
		       "螳螂","瓢虫","蝗虫","蟋蟀",
			"牛", "老虎", "兔子",
			"狗","猫咪","羊","猪",
			"骆驼","乌龟","蛇","鱼儿",
			"鹿","马","犀牛"});
string *default_prefix=({"小","大","老","白","黄","黑","花","灰",
	"纸","木头","石头","泥"});


void logind_user_log(); // mon 11/5/98
int total_count;
int howmany_user();
private void encoding(string arg, object ob);
private void if_young(string arg, object ob);
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
private void confirm_gift(string yn,object ob,object user);
private void judge_freeze(object ob); //函数原形 用来判断账号是否被冻结
int do_counter(); // 总共登陆人数统计
int check_legal_password(object ob,string arg); // 验证密码可行性

int howmany_user()
{
	int i,j,reg_cnt;
	string *dir , *ppls, name;
	mixed info;
	seteuid(getuid());
	reg_cnt=0;
	dir=get_dir(DATA_DIR+"login/");
	for(i=0; i<sizeof(dir);i++)	{
		reset_eval_cost();
		ppls=get_dir(DATA_DIR+"login/"+dir[i]+"/");
		reg_cnt+=sizeof(ppls);
	}
	return reg_cnt;
}
void create() 
{
	seteuid(getuid());
	set("channel_id", "连线精灵");
        set("id", "logind");
}

// mon 11/7/98
void logind_user_log()
{
    int user=sizeof(users());
    int total;

    remove_call_out("logind_user_log");
    rm("/log/user_count");    log_file("user_count",""+
            ((total=total_count)?total:user)+"\n"+
            user+"\n"+
            UPTIME_CMD->report_str()+"\n"+
            "西游记2006记\n");
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998


void logon(object ob)
{

#ifdef GB_AND_BIG5
    write("            西游记2006欢迎您来访！使用国标码的玩家请键入：gb\n");
    write("         Welcome to "BLINK HIY"DTXYJ!"NOR" Select GB or BIG5 (gb/big5):");
    input_to( (: encoding :), ob );
#else
    encoding("gb",ob);
#endif

}

private void encoding(string arg, object ob)
{
	object *usr;
	int i, ttl_cnt, wiz_cnt, ppl_cnt, login_cnt, max_online,avg_online;
	string ip_name, ip_number, online_num;
 	int ii;
        mixed info;
	int encode;
	

	if(!arg || arg=="") {
	    write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	} else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
	    input_to( (: encoding :), ob );
	    return;
	}
	
	ob->set_encoding(encode);

	ip_name = query_ip_name(ob);
	ip_number = query_ip_number(ob);



// snowcat dec 10 1997
// try strict ban here...weiqi.

	if ("/adm/daemons/band"->is_strict_banned(query_ip_number(ob)) == 1) {
write(HIR"您的地址在本 MUD 之信誉被人破坏了。\n请E-MAIL:torrow0812@21cn.com申述。\n"NOR);
	   	destruct(ob);
		log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
	   	return;
	}

	
	// try not accept "name" as IP

	if (!ip_name) {
		destruct(ob);
		log_file( "ALLCONT", sprintf("kicked out, No IP\n"));
		return;
	}

	for(ii=0; ii<sizeof(ip_number); ii++) {
		if( (ip_number[ii] != '.')&&(ip_number[ii]>'9') ){
			destruct(ob);
			log_file( "ALLCONT", sprintf("kicked out, Non_number\n"));
			return;
		}
	}
	
	write(CLR);
	cat(WELCOME);
	UPTIME_CMD->report();

	// children will show both netdead and interactive users.
	usr = children(USER_OB);
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) ) login_cnt++;
		else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
		else ppl_cnt++;
	}
        max_online = atoi(read_file(__DIR__"maxonline",1));
	avg_online = atoi(read_file(__DIR__"avguser",1));
	if(ppl_cnt > max_online)
	   {
	   	online_num = sprintf("%d",ppl_cnt);
	   	write_file(__DIR__"maxonline",online_num,1);
	   }
printf("西游记2006("HIY"总站"NOR")现有注册玩家"HIR"%s"NOR"位，共"HIW"%s"NOR"人次访问。\n",chinese_number(howmany_user()),chinese_number(do_counter()));
printf("西游记2006("HIY"总站"NOR")开站以来，最高在线数目："HIY"%s"NOR" 人，平均在线数目："HIY"%s"NOR" 人。\n",chinese_number(max_online),chinese_number(avg_online));
	printf("目前共有"HIR"%s"NOR"位管理人员、"HIC"%s"NOR"位玩家，以及"HIG"%s"NOR"位使用者在尝试连线。\n\n",
		chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
rm("/log/counter_for_web");
log_file("counter_for_web",sprintf("目前共有%s位巫师、%s位玩家在线上，以及%s位使用者尝试连线中",
                chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) ));
login_cnt = 0;
	// mon 11/7/98
	//check whether user_log still running.
	info = filter_array(call_out_info(), (: $1[1]=="logind_user_log" :));
	if(!sizeof(info)) logind_user_log();


      /* move this check to after user input id.
	 
// mon 4/19/98
// reduce number of pending login users.
#ifdef MAX_USERS
	if(sizeof(usr)>(MAX_USERS+10)) {
	    write("对不起，西游记2006的玩家已经太多了，请待会儿再来。\n");
	    destruct(ob);
	    return;
	}
#endif

*/

	if (ob) ob->set_temp("id_count",0);
	//mon 10/15/97 to prevent flooding illegal ID after login.

#ifndef GB_AND_BIG5
#endif
        
	//we do not welcome young kid playing mud. weiqi...971220.
	write("鉴于学生的主要任务是学习，本游戏不欢迎中小学生来玩。\n");
	write("您是否是中小学学生或年龄更小？(yes/no)");
	input_to( (: if_young :), ob );
}

private void if_young(string arg, object ob)
{
        int id_count;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id.
        id_count++;
        ob->set_temp("id_count",id_count);
        if(id_count>3) {
          destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
          return;
        }

        if(arg=="\n" || arg=="") {
	    write("您是否是中小学学生或年龄更小？(yes/no)");
	    input_to( (: if_young :), ob );
	    return;
	}

	if( arg[0..0] == "y" || arg[0..0] == "Y" )
	{
		write("\n好，赶紧去学习才是正道理。\n");
		destruct(ob);
		return;
	}

	if( arg[0..0] != "n" && arg[0..0] != "N" ) {
	    write("您是否是中小学学生或年龄更小？(yes/no)");
	    input_to( (: if_young :), ob );
	    return;
	}

	cat(XYJ_SITES);
	write("\n您的英文名字：（新玩家请键入 new 注册）");
	input_to( (: get_id :), ob);
}

private void get_id(string arg, object ob)
{
	object ppl, *usr = children(USER_OB);
        int id_count;

//edw 6/2/98
        int NowLogin, MaxLimit, login_site, i;
	string my_ip, new_ip;
//end edw

        if(!ob) return;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
        id_count++;
        ob->set_temp("id_count",id_count);
	if(id_count>6) {
	  destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
	  return;
        }

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write("您的英文名字：");
		input_to("get_id", ob);
		return;
	}

	ppl = find_body(arg);

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& sizeof(users()) >= MAX_USERS ) {
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		// i.e., ppl exist. (has nothing to do with whether it interactive) -- mon 3/15/99
		//if( !ppl || !interactive(ppl) ) 
		if( !ppl ) {
		  write("对不起，西游记2006的玩家已经太多了，请待会儿再来。\n");
		  destruct(ob);
		  return;
		} 
	}
#endif

	//if( wiz_level(arg) < wiz_lock_level ) {
		//write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
			//+ " 以上的人才能连线。\n");
		//destruct(ob);
		//return;
	//}
	
//edw@zju.mirror.xyj 6/2/98 (limit multi-login)
// MAX_LOGIN and LOGIN_SITE should be defined in login.h
#ifdef MAX_LOGIN
	
      if(!ppl) { // only check this for new login.
	         // allow existing players to reconnect.
      my_ip=query_ip_number(ob);

      MaxLimit="/adm/daemons/band"->allow_multi_login(my_ip);
      if(!MaxLimit) MaxLimit=MAX_LOGIN;
#ifdef LOGIN_SITE
      login_site=LOGIN_SITE;
#else
	  login_site=0;
#endif
      if(my_ip && login_site==0) // ignore the last field of the IP
	  my_ip=my_ip[0..strsrch(my_ip, ".", -1)];

      NowLogin=0;

      for(i=0;i<sizeof(usr);i++) 
        if(ob!=usr[i]) {
	    new_ip=query_ip_number(usr[i]);
	    
	    // for net_dead players.
	    if(!new_ip && !interactive(usr[i]))
		new_ip=usr[i]->query_temp("netdead_ip");

	    if(new_ip && login_site==0)
		new_ip=new_ip[0..strsrch(new_ip, ".", -1)];

            if(my_ip==new_ip) {
               NowLogin++;
	    }
			
	}

      if(NowLogin>=MaxLimit) {
	      write(sprintf("对不起，从你的IP地址不能同时登录%s位人物。\n",
		      chinese_number(MaxLimit+1)));
              destruct(ob);
              return;
       } 
      }
#endif

	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	if( arg=="guest" ) {
		// If guest, let them create the character.
//		confirm_id("Yes", ob);
//		return;
} else if (arg=="new") { // new player login
                write("\n请您给自己取一个英文名字：");
		input_to("get_new_id",ob);
		return;
	} else if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			judge_freeze(ob);  
			write("\n请输入密码(管理密码或登陆密码)：");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("您的人物储存档出了一些问题，请利用别的人物通知巫师处理。\n");
		destruct(ob);
		return;
	} 
	
        write("没有这个玩家．．．\n");
	write("您的英文名字：（新玩家请键入 new 注册）");
	input_to("get_id", ob);
	return;
}
private void judge_freeze(object ob)
{
        int freeze_time;        
      freeze_time=ob->query("freeze_time");
        if( time() < freeze_time ) {            
write ("对不起，这个账号已经被冻结,还有"+(freeze_time+3600-time())/3600 +"小时才能使用。 \n");
             destruct(ob);
             return;
        }       
}                      

private void get_new_id(string arg, object ob)
{
object ppl, *body;  
   int id_count, i, nb=0;  
// edit by canoe
//修改多重登陆

        if(!ob) return;

        id_count=ob->query_temp("id_count");
// mon 7/19/97 to prevent flooding by repeating illegal id. 
        id_count++;
        ob->set_temp("id_count",id_count);
	if(id_count>6) {
	  destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
	  return;
        }

        if(!arg) {
                write("\n请您给自己取一个英文名字：");
		input_to("get_new_id", ob);
		return;
        }

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
                write("\n请您给自己取一个英文名字：");
		input_to("get_new_id", ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	ppl = find_body(arg);
	if(ppl || arg=="guest" || arg=="new") {
	    write("这个名字已经被别的玩家使用了．．．");
            write("\n请您给自己取一个英文名字：");
	    input_to("get_new_id",ob);
	    return;
	}

	if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
	    write("这个名字已经被别的玩家使用了．．．");
            write("\n请您给自己取一个英文名字：");
	    input_to("get_new_id",ob);
	    return;
// edit by canoe
//修改多重登陆新人
	} 
        ob->set("new_player", 1);  
        body = children(LOGIN_OB);  
        i = sizeof(body);  
        while (i--) {   
          if( clonep(body[i]) && body[i]->query("id")==arg  
              && body[i]->query("new_player")==1 ) nb++;  
          if( nb>1 ) {  
              write("对不起，已经有人在用这个英文名字创造人物了．．．\n");  
              write("\n请您给自己取一个英文名字：");  
              ob->delete("new_player");  
              input_to("get_new_id",ob);  
              return;  
           }  
        }  
// over

	confirm_id("Yes", ob);
	return;
}

private void get_passwd(string pass, object ob)
{
	string my_pass,id;
	object user;
        // by canoe 修改双重密码登陆效果
        int pwdflag=0; 
        write("\n");
	my_pass = ob->query("password");
	
	if( crypt(pass, my_pass) == my_pass)
	{
	write(HIY"\n您使用了登陆密码成功登陆！\n"NOR);
	pwdflag=1;
	} 
	my_pass=ob->query("super_password");
	if(!pwdflag
	&&crypt(pass, my_pass) ==my_pass )
	{
	write(HIR"\n您使用了管理密码成功登陆！\n我们建议您只有在密码被盗等情况下才使用管理密码登陆！\n"NOR);
	pwdflag=1;
	}
	if(!pwdflag
	||!SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) )
	 {
		write("密码错误！");
		write("请重新连线，键入正确的密码或另取一个新的英文名字。\n");
		if((id=ob->query("id")) && member_array(id,
			SECURITY_D->get_wizlist())!=-1)
		  log_file("wizlogin",ctime(time())+" "+id+
			" failed login from "+query_ip_number(ob)+"\n");
		else
		  log_file("login",ctime(time())+" "+id+
			" failed login from "+query_ip_number(ob)+"\n");
		destruct(ob);
		return;
	}
	// end
	// by canoe 修改kickout登陆时间限制
	if(time()-(int)ob->query("kickout_time") < 600)
			{
			write("你现在没有进入〖西游记2006〗的权利，请十分钟后再联线。\n");
			destruct(ob);
			return;
			}
	// end
	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
	    
	    // netdead is delayed being set
	    // after disconnected, so should use interactive.
	    // mon 7/5/98
		if( !interactive(user) ) {
			reconnect(ob, user);
			return;
		}
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

   if( objectp(user = make_body(ob)) ) {
     if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );

        enter_world(ob, user);
        return;
     } else {
        destruct(user);
     }
   }
   write("请您重新创造这个人物。\n");
   confirm_id("y", ob);
}


private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
	    // user may be destructed during the process.
	    // so I put in this check. mon 4/15/98
		write("好吧，欢迎下次再来。\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "有人从别处( " + query_ip_number(ob)
			+ " )连线取代你所控制的人物。\n");
		log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
		user->query("name"), user->query("id"),
			query_ip_number(ob), ctime(time()) ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");

//	if( old_link ) {
	// mon 7/5/98
	// need to check user is interactive before exec.
	// user may become non-interactive after the input_to.
	if( old_link && interactive(user)) {
	        // 5/11/98 mon
	        user->set_encoding(ob->query_encoding());

		exec(old_link, user);
	}
	if(old_link)      // mon 9/14/98
		destruct(old_link);

	reconnect(ob, user);	
}

private void confirm_id(string yn, object ob)
{
    /*
	if( yn=="" ) {
		write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("好吧，那么请重新输入您的英文名字：");
		input_to("get_id", ob);
		return;
	}
	*/


	write( @TEXT

请您给自己想一个符合〖西游记2006〗神话世界的中文名字。这
个名字将代表你在西游记2006中的人物，而且往后将不能再更改。
请不要取一些不雅或是容易造成他人困扰的名字。

TEXT
	);
	write("您的中文名字：");
	ob->set_temp("get_name",0);
	input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
        arg = CONVERT_D->input(arg,ob);

	if( !check_legal_name(arg) ) {
            ob->add_temp("get_name",1);
	    if(ob->query_temp("get_name")>2) {
	        // the user can't input proper chinese name.
	        // assign one for him/her.    mon 4/19/98

		arg=default_prefix[random(sizeof(default_prefix))]+
		    default_name[random(sizeof(default_name))];

		write("因为你不能输入适当的中文名字，系统指定你的名字为："+
			arg+"\n");
		write("请在进入游戏后请巫师帮助修改。\n");

	    } else {
		write("您的中文名字：");
		input_to("get_name", ob);
		return;
	    }
	}
// by canoe for suppwd
	printf("%O\n", ob);
	ob->set("name", arg);
	write(HIG"\n注意：人物口令修改、档案备份、自杀等需要管理密码；\n\n"NOR);
	write(HIR"      一般情况下不予更改，请务必妥善保存。\n\n"NOR);
	write(HIY"请设定您的管理密码："NOR);
	input_to("get_super_password", 1, ob);
}

private void get_super_password(string pass, object ob)
{
	write("\n");
	if( !check_legal_password(ob,pass)) {
		write(HIW"请重新设定您的密码：");
              	input_to("get_super_password", 1, ob);
		return;
	}
	ob->set("super_password", crypt(pass,0) );
	write(HIR"请再输入一次您的管理密码，以确认您没记错："NOR);
	input_to("confirm_super_password", 1, ob);
}
private void confirm_super_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("super_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write(HIY"您两次输入的管理密码并不一样，请重新设定一次管理密码："NOR);
		input_to("get_super_password", 1, ob);
		return;
	}
	write(HIC"游戏登陆密码是指您每次进入游戏时必须输入的密码。\n\n"NOR);
	write(HIG"请设定您的游戏登陆密码："NOR);
	input_to("new_password", 1, ob);
}
// end
private void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write("密码至少要由五个字符组成，请重设您的密码：");
		input_to("new_password", 1, ob);
		return;
	}
	if( crypt(pass, ob->query("super_password"))==ob->query("super_password") ) {
		write("您的登陆密码不能和管理密码一样，请重设您的密码：");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write(HIY"请再输入一次您的密码，以确认您没记错："NOR);
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("您两次输入的密码并不一样，请重新设定一次登陆密码：");
		input_to("new_password", 1, ob);
		return;
	}

	write("您的电子邮件地址：");
	input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
	object user;
        // By Canoe 强调email一定要输入正确
        string id,addr;
        write("\n");
         if (email=="" || strsrch(email,".")==-1 
        || sscanf(email,"%s@%s",id,addr) !=2)
        {
		write(HIC"电子邮件地址需要是 id@dtxy.net 的格式。\n");
		write(HIW"您的电子邮件地址："NOR);
		input_to("get_email", ob);
		return;
	}
	ob->set("email", email);
	//end
	
	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) ) {
	    if(ob) destruct(ob);
	    return;
	}

	write("您要扮演男性(m)的角色或女性(f)的角色？");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	if( gender=="" ) {
		write("您要扮演男性(m)的角色或女性(f)的角色？");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "男性");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "女性" );
	else {
		write("对不起，您只能选择男性(m)或女性(f)的角色：");
		input_to("get_gender", ob, user);
		return;
	}
	
        confirm_gift("n",ob,user);
}

object make_body(object ob)
{
	string err;
	object user;
	int n;

        if(!ob->query("body")) {
	  return 0;
        }
	user = new(ob->query("body"));
	if(!user) {
		write("现在可能有人正在修改玩家物件的程式，无法进行复制。\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

private void confirm_gift(string yn, object ob, object user)
{
        int n, a, b;

	if(!ob || !user) {
            if(user) {
	      destruct(user);
	      return;
	    }
            if(ob) destruct(ob);
	    return;
        }

        user->set("kar", 20 );
	user->set("str", 20 );
	user->set("cps", 20 );
	user->set("int", 25 );
	user->set("cor", 20 );
	user->set("con", 20 );
	user->set("spi", 25 );
	user->set("per", 20 );

	// mon 3/21/99 allow players to choose gift after login.
	user->set("no_gift",1);

	    CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
	    user->set("title", "大唐游民");
	    user->set("birthday", time() );
	    user->set("potential", 99);
	    user->set("food", user->max_food_capacity());
	    user->set("water", user->max_water_capacity());
	    user->set("channels", ({ "chat","rumor","xyj","sldh","es" }) );
	    log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_number(ob), ctime(time()) ) );

	    ob->set("last_from",query_ip_number(ob));
	    ob->set("last_on",time());
// edit by canoe
//修改多重登陆新人
ob->delete("new_player");  
//over

	    return enter_world(ob, user);
}

string dis_attr(int value)
{       int gift=20;
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

varargs void enter_world(object ob, object user, int silent)
{
	object cloth, room, mbx;
	string startroom="";
	string ip_from;
	int num;
        ////////////
	// Add for 上线通知 By Canoe 2001.03.29
       int qqnum;
       string *qqfriends;
       object qqob;
       ////////////////

        reset_eval_cost();
        user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);

	// 5/11/98 mon
	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	write("\n目前权限：" + wizhood(user) + "\n");
	user->setup();

	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();

        if( !silent ) {
	     if(file_size(MOTD)>0)
             user->start_more(read_file(MOTD));
		
	     // mon 3/21/99 
	     // new user login.
             if(user->query("no_gift")) {
	       user->move("/d/wiz/init",1);
	     } else {
		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( strlen(startroom = user->query("startroom"))<2 )
			startroom = START_ROOM;

                if(!wizardp(user) && startroom[0..2]=="/u/") {
		  startroom = START_ROOM;
                  user->set("startroom",startroom);
                }
                //added by mon 10/27/97

		// the following 7 lines are aded by snowcat dec 10 1997
		if (("/adm/daemons/band"
		    ->create_char_banned(query_ip_number(user)) == 1 ||
	    	    "/adm/daemons/band"->is_banned(query_ip_number(user))
		    == 1) && !wizardp(user)) {
			user->move("/d/wiz/guest");
			log_file( "ALLCONT", sprintf("from banned site\n"));
		}
		else if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		// by canoe 修改多物品时突然quit不能进mud Bug
		if(!environment(user))
		       {
		       	user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		// end
				if(!wizardp(user) || !user->query("env/invisibility"))
		tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
			({user}));
	     }
	        if(file_size("/log/notice")>0){
			write(CYN"     ≡≡≡≡≡≡≡≡≡≡≡≡"HIR"西游记2006连线通知"NOR CYN"≡≡≡≡≡≡≡≡≡≡≡≡\n");
          		write("     "+read_file("/log/notice"));
   	  		write(CYN"     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR);        }
   		mbx=ob->query_temp("mbox_ob");
		if (!mbx) {
		  mbx=new(MAILBOX_OB);
		  mbx->set_owner(ob->query("id"));
                }
		num=mbx->query_new_mail();
		if( num>0 ) {
	          write( GRN + "\n千里眼告诉你：有您"
		    +chinese_number(num)+
		    "封信！请到南城客栈来一趟．．．\n\n" + NOR);
		}
		destruct(mbx);
	      	ip_from="/adm/daemons/ipd"->seek_ip_address(query_ip_number(user));
// add by canoe 2001-06-17
// wiz上线通知
   CHANNEL_D->do_channel( this_object(),wizardp(user)?"wiz":"sys",sprintf(NOR WHT "%s由 " HIG "%s" NOR WHT "连线进入,IP来自："HIG"%s"NOR,user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user), ip_from)); 
// over 上线通知
		}

	UPDATE_D->check_user(user, 0);
	TOPTEN_D->topten_checkplayer(user);
     //////////////////////////////////////////////////////
     // Add for QQ上线通知 By Canoe 2001.03.29
	if(mapp(user->query("qq"))
	   && sizeof(user->query("qq"))!=0
	   &&!user->query("env/invisibility")) {
	qqfriends = keys(user->query("qq"));
	 for(qqnum=0;qqnum<sizeof(qqfriends);qqnum++)
                {
				qqob=find_player(qqfriends[qqnum]);
				tell_object(qqob,BLINK HIG+"大唐信使通知您：你的好友"+user->query("name")+"["+capitalize(user->query("id"))+"]上线了！！\n"+NOR);
		}
         }
     ////////////////////////////////////////////////////////

      {
      	object caishen;
	if(objectp(caishen=find_object("/d/wiz/npc/caishen"))) {
	  caishen->check_one(user);
        }
      }
    // by canoe
    //  "/cmds/std/news"->check_news(user); // by canoe 修改上线新闻通知 
    // end
}

varargs void reconnect(object ob, object user, int silent)
{
        object old_link;
	
	// mon 9/15/98
	old_link=user->query_temp("link_ob");
	if(old_link && old_link!=ob)
	    destruct(old_link);

	user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
  
	// 5/11/98 mon
	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	user->reconnect();
	if( !silent && !user->query("env/invisibility")) {
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
		({user}));
		// By canoe ,wiz登陆通告
		CHANNEL_D->do_channel( this_object(),(wizardp(user)?"wiz" :"sys"),
			sprintf("%s由%s重新连线进入。", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_name(user)) );
	        // end
	}
	UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
	int i;
	string *legalid;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
		write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("对不起，你的英文名字只能用英文字母。\n");
			return 0;
		}
	legalid = explode(read_file(BANNED_ID), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( id == legalid[i] )   {
		  write("对不起，这种名字会造成其他人的困扰。\n");
		  return 0;
       }
	}
	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	
	if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
		write("对不起，你的中文名字必须是一到六个中文字。\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("对不起，你的中文名字不能用控制字符。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++) {
          ob=body[i];
	  if( clonep(ob) && getuid(ob) == name 
            && ob->query("max_gin")>0 ) return ob;
	    //check max_gin to avoid damaged user object.
        }

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
// by canoe
int do_counter()
{       
	int number;
	string file;
	file = read_file(FileName);
	sscanf(file,"%d",number);
	number++;
	file=sprintf("%d",number);
	write_file(FileName,file,1);
	return number;
}
int check_legal_password(object ob,string pass)
{
        int i;
	int bigletter=0;
	int smlletter=0;
	int number=0;
	string id;
        i = strlen(pass);
        if( strlen(pass) <= 6)   {
                write(WHT"对不起，你的管理密码必须最少七个字符。\n");
                return 0;
        }
	id= ob->query("id");	
	if ( strsrch(id, pass) != -1 || strsrch(pass,id) != -1)
	{
	write(WHT"对不起，你的管理密码和你的英文名字太象了。\n"NOR);
                return 0;
        }

        while(i--) {
                if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;

        }
	if( bigletter == 0 || smlletter == 0 || 
	bigletter+smlletter == strlen(pass))
{
        write(WHT"您的管理密码必需包含大写" + RED"和" + WHT"小写英文字母"
		+ RED"和" + WHT"其它特殊符号（数字，标点）。\n"NOR);
	return 0;
}
        return 1;
//end
}
