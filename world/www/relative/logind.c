// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>     // for GB_AND_BIG5 define.

inherit F_DBASE;

//int wiz_lock_level = WIZ_LOCK_LEVEL;
int wiz_lock_level = 1;
string BBSVISITOR = "/data/bbsvisitor";
//#define FJ "/d/hen/play/pic15"
//#define NY "/obj/gift/ny1"

string *banned_name = ({
        "你", "我", "他", "她", "它", "它", "江泽民", "邓小平", "李鹏", "朱榕基"
,
        "自己", "某人", "尸体", "我们","你们", "他们", "大家",
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
int total_count,bjtime,user_num;
int howmany_visitor();
void set_visitor();
private void encoding(string arg, object ob);
//private void if_young(string arg, object ob);
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
string ip_from;
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
private void confirm_gift(string yn,object ob,object user);
private void judge_freeze(object ob); //函数原形 用来判断账号是否被冻

void create()
{
        seteuid(getuid());
        set("channel_id", "连线精灵");
        set("id", "logind");
}
int howmany_visitor()
{
int num;
string content,format;
content=read_file(BBSVISITOR);
if (sscanf(content,"%s %d", format, num)==2)
{
if(format!="VISITOR" && wizardp(this_player()))
  write("巫师请注意，访问者的数目有可能不对，"+"请察看logind.c中的howmany_visitor函数。\n");
return num;
}

return 0;
}
void set_visitor()
{
int user_num=1;
user_num=howmany_visitor()+1;
rm(BBSVISITOR);
    write_file(BBSVISITOR,"VISITOR "+user_num);
return;
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
            "西游记\n");
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998

void logon(object ob)
{

#ifdef GB_AND_BIG5
     cat(BANNER);
//    cat(FJ);
write("         Welcome to Y S Z Z! Select GB or BIG5 (gb/big5):");
    input_to( (: encoding :), ob );
#else
    encoding("gb",ob);
#endif

}

private void encoding(string arg, object ob)
{
        object *usr;
        int i, ttl_cnt, wiz_cnt, ppl_cnt, login_cnt;
        string ip_name, ip_number;
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
                write(HIR"您的地址在本 MUD 之信誉被人破坏了。\n"NOR);
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
                        log_file( "ALLCONT", sprintf("kicked out, Non_number\n")
);
                        return;
                }
        }

        write(CLR);

   switch ( random(6))
    {
   case 0:
   cat(WELCOME);
   break;
   case 1:
   cat(WELCOME2);
    break;
    case 2:
   cat(WELCOME3);
   break;
   case 3:
   cat(WELCOME4);
   break;
   case 4:
   cat(WELCOME5);
    break;
    case 5:
   cat(WELCOME6);
   break;
   }
//      MUDLIST_CMD->main(ob);
        UPTIME_CMD->report();

        // children will show both netdead and interactive users.
        usr = children(USER_OB);
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")
&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
                else ppl_cnt++;
        }
bjtime = time();
user_num=0;
user_num=howmany_visitor();
if (user_num>0)
write(HIR"№"WHT"『"HIG+MUD_NAME+WHT"』"NOR" 自一九九八年十月一日起共被访问"+HIW+chinese_number(user_num+1)+NOR"人次.\n");
set_visitor();

        // snowcat Mar 11 1998
//   ttl_cnt = total_players();
	write(HIR"№"WHT"『"HIG+MUD_NAME+WHT"』"NOR" 最大支持人数："HIR
	      +chinese_number(MAX_USERS)+NOR"人。\n");
	printf(HIR"№"WHT"『"HIG"妖神之争"WHT"』"NOR" 目前共有"HIY" %s"NOR
	      " 位巫师、"HIW"%s"NOR" 位玩家在线上，以及 "HIC"%s"NOR" 位使用者尝试连线中。\n",
              chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
/*
   added by ammy@YSZZ 
   在web 上面显示在线情况
   此方法可能会产生一定延时　
   特别在有人退线后但没人登陆的情况下会产生较大误差
   但是这样可以节省很多资源 
   如果愿意　也可以修改quit.c来使得数据准确 
 */
	rm("/log/counter_for_web");
	log_file("counter_for_web",
		sprintf("目前共有%s位巫师、%s位玩家在线上，以及%s位使用者尝试连线中",
                chinese_number(wiz_cnt), chinese_number(ppl_cnt)
                , chinese_number(login_cnt) )); // end  count_for_web
	
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
            write("对不起，"+MUD_NAME+"的玩家已经太多了，请待会儿再来。\n");
            destruct(ob);
            return;
        }
#endif


*/

        if (ob) ob->set_temp("id_count",0);
        //mon 10/15/97 to prevent flooding illegal ID after login.

#ifndef GB_AND_BIG5
#endif

        write(HIR"№"WHT"『"HIG" 您的英文名字 "WHT"』"NOR"（新玩家请键入 new 注册）");
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
                  write("对不起，"+MUD_NAME+"的玩家已经太多了，请待会儿再来。\n");

                  destruct(ob);
                  return;
                }
        }
#endif
/*
        if( wiz_level(arg) < wiz_lock_level ) {
                write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
                        + " 以上的人才能连线。\n");
                destruct(ob);
                return;
      }
*/
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
//              confirm_id("Yes", ob);
//              return;

} else if (arg=="new") { // new player login
                write("\n请您给自己取一个英文名字：");
                input_to("get_new_id",ob);
                return;
        } else if( file_size(ob->query_save_file()
                    + __SAVE_EXTENSION__) >= 0 ) {
                if( ob->restore() ) {
                        judge_freeze(ob);
                        write(HIR"№"WHT"『"HIG"请输入相应密码"WHT"』"NOR"");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("您的人物储存档出了一些问题，请利用 guest 人物通知巫师处理。\n");
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
write ("对不起，这个账号已经被冻结,还有"+(freeze_time+3600-time())/3600 +"小
时才能使用");
             destruct(ob);
             return;
        }
}        
 

private void get_new_id(string arg, object ob)

{
        object ppl;
        int id_count;

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
        }

        confirm_id("Yes", ob);
        return;
}

private void get_passwd(string pass, object ob)
{
        string my_pass,id;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass
||         !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
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

//      if( old_link ) {
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

请您给自己想一个符合〖西游记〗神话世界的中文名字。这
个名字将代表你在西游记中的人物，而且往后将不能再更改。
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

        printf("%O\n", ob);

        ob->set("name", arg);
        write("请设定您的密码：");
        input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("密码至少要由五个字符组成，请重设您的密码：");
                input_to("new_password", 1, ob);
                return;
        }
        if(strsrch(pass,ob->query("id")) !=-1) {
                write(" [31m:P"HIY"你的密码不太好耶 \n [0m");
                input_to("new_password",1,ob);
                return;
        }

        ob->set("password", crypt(pass,0) );
        write("请再输入一次您的密码，以确认您没记错：");
        input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");

        if( crypt(pass, old_pass)!=old_pass ) {
                write("您两次输入的密码并不一样，请重新设定一次密码：");
                input_to("new_password", 1, ob);
                return;
        }

        write("您的电子邮件地址：");
        input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
        object user;
        string id,addr;
        if (email=="" || strsrch(email,".")==-1 
        || sscanf(email,"%s@%s",id,addr) !=2)
        {        
        write (HIY"请确实填写您的Email地址！\n"NOR);
        write ("您的电子邮件地址：");
        input_to("get_email",ob);
        return;
        }        
        ob->set("email", email);
       
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

        int n;

   if(!ob || !user) {
            if(user) {
         destruct(user);
         return;
       }
            if(ob) destruct(ob);
       return;
        }

        if (yn!="") {
          if (yn[0]=='y' || yn[0]=='Y') {
       CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
       user->set("title", "普通百姓");

       user->set("birthday", time() );
       user->set("potential", 299);
       user->set("combat_exp",500);
       user->set("food", user->max_food_capacity());
       user->set("water", user->max_water_capacity());
       user->set("channels", ({ "chat","rumor","es","new","sldh" }) );
       log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
     query_ip_number(ob), ctime(time()) ) );

       return enter_world(ob, user);

          } else if (yn[0]=='q' || yn[0]=='Q') {
            destruct(user);
            destruct(ob);
            return;
          }
        }

        user->set("kar",0);
   while(user->query("kar")<10 || user->query("kar")>30){
   user->set("str", 10 + random(21));
   user->set("cps", 10 + random(21));
   user->set("int", 10 + random(21));
   user->set("cor", 10 + random(21));
   user->set("con", 10 + random(21));
   user->set("spi", 10 + random(21));
   user->set("per", 10 + random(21));
        n = user->query("str") + user->query("cps") + user->query("int");
        n = n + user->query("cor") +  user->query("con") +  user->query("spi") +
 user->query("per");
        if(n>168)
           user->set("kar",0);
           else
           user->set("kar",168-n);
        }

        write("\n");
        printf(" 膂力：[%s]  胆识：[%s]  悟性：[%s]  灵性：[%s]\n"
               " 定力：[%s]  容貌：[%s]  根骨：[%s]  福缘：[%s]\n\n",
               dis_attr(user->query_str()),
               dis_attr(user->query_cor()),
               dis_attr(user->query_int()),
               dis_attr(user->query_spi()),
               dis_attr(user->query_cps()),
               dis_attr(user->query_per()),
               dis_attr(user->query_con()),
               dis_attr(user->query_kar()));
        write("您同意这组天赋数值吗？[n|y|q]");
        input_to("confirm_gift",ob,user);
        return;
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
        int num,bug;
        object login_ob;

        reset_eval_cost();
        user->set_temp("temp_time",time());

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);

        // 5/11/98 mon
        user->set_encoding(ob->query_encoding());

        exec(user, ob);

        write("目前权限：" + wizhood(user) + "\n");
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
//             if(user->query("no_gift")) {
  //             user->move("/d/wiz/init",1);
    //         } else {
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( strlen(startroom = user->query("startroom"))<2 )
                        startroom = START_ROOM;

                if(!wizardp(user) && startroom[0..2]=="/u/") {

                  startroom = START_ROOM;
                  user->set("startroom",startroom);
                }

                if ( wizardp(user) 
&& user->query("startroom") != "/d/wiz/wizroom" ) {
                   startroom="/d/wiz/wizroom";
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
                if(!wizardp(user) || !user->query("env/invisibility"))
                tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                        ({user}));

             }

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
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf(WHT "%s由 " HIG "%s" NOR WHT "连线进入,
IP来自："HIG"%s"NOR,
user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user), ip_from) );  

//        }
/*■■■■■■■■■■■■■■  bug of pantu ■■■■■■■■■■■■*/

	if( user->query("soldier_amount") > 1000000 )
	{
	tell_object(user,"您的一部分士兵叛变了!!\n");
	user->set("soldier_amount",1000000+random(100));
	}

/*■■■■■■■■■■■■■■  bug of pantu ■■■■■■■■■■■■*/
/*

       if(!user->query("env/no_status") )
      "/feature/frozen.c"->show_two_screen(user);
        tell_object(user,HIY"要关闭状态栏,请help stat \n"NOR);
*/
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
        write(HIW"你上次连线是从" + HIR +login_ob->query("last_from") + HIW + " on " + HIR +ctime(login_ob->query("last_on"))+ NOR + "\n");
        destruct(login_ob);

       TOPTEN_D->topten_checkplayer(user);

        UPDATE_D->check_user(user, 0);

      {object caishen;
        if(objectp(caishen=find_object("/d/wiz/npc/caishen"))) {
          caishen->check_one(user);
        }
      }
}

varargs void reconnect(object ob, object user, int silent)
{
        object old_link;

        // mon 9/15/98
        old_link=user->query_temp("link_ob");
        if(old_link && old_link!=ob)
            destruct(old_link);
        user->set_temp("temp_time",time());
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
       
        // 5/11/98 mon
        user->set_encoding(ob->query_encoding());

        exec(user, ob);

        user->reconnect();
        if( !silent && !user->query("env/invisibility")) {
                tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
                ({user}));
               CHANNEL_D->do_channel( this_object(), "sys",
                        sprintf("%s由%s重新连线进入。", user->query("name")+"("
+ capitalize(user->query("id")) + ")", query_ip_name(user)) );
      }
/*
       if(!user->query("env/no_status") )

      "/feature/frozen.c"->show_two_screen(user);
        tell_object(user,HIY"要关闭状态栏,请help stat \n"NOR);
*/ 
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

