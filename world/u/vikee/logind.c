// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>     // for GB_AND_BIG5 define.

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
	"Äã", "ÎÒ", "Ëû", "Ëı", "Ëü", "Ëü", "½­ÔóÃñ", "µËĞ¡Æ½", "ÀîÅô", "ÖìéÅ»ù",
	"×Ô¼º", "Ä³ÈË", "Ê¬Ìå", "ÎÒÃÇ","ÄãÃÇ", "ËûÃÇ", "´ó¼Ò",
	"ËûÂèµÄ", "È¥ÄãµÄ", "Ã«Ôó¶«", "Î×Ê¦", "ËûÄÌÄÌµÄ",
});

string *default_name=({"ºï×Ó","ºüÀê", "ÀÏÊó", 
	               "òßòÑ","¼×³æ","ºûµû","òåòå",
		       "ó«òë","Æ°³æ","»È³æ","ó¬ó°",
			"Å£", "ÀÏ»¢", "ÍÃ×Ó",
			"¹·","Ã¨ßä","Ñò","Öí",
			"ÂæÍÕ","ÎÚ¹ê","Éß","Óã¶ù",
			"Â¹","Âí","Ï¬Å£"});
string *default_prefix=({"Ğ¡","´ó","ÀÏ","°×","»Æ","ºÚ","»¨","»Ò",
	"Ö½","Ä¾Í·","Ê¯Í·","Äà"});


void logind_user_log(); // mon 11/5/98
int total_count;
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

void create() 
{
	seteuid(getuid());
	set("channel_id", "Á¬Ïß¾«Áé");
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
            "Î÷ÓÎ¼Ç2006\n");
    call_out("logind_user_log",600);
}

// added by snowcat Mar 11 1998


void logon(object ob)
{

#ifdef GB_AND_BIG5
    cat(BANNER);
    write("    [If there is no response after ENTER, please try Ctrl-ENTER]\n");
    write("        [[1;31mÌáÊ¾£º[0;37;0mÈç¹û°´ENTER¼üºóÏµÍ³Ã»ÓĞÏìÓ¦£¬ÇëÊÔ Ctrl-ENTER]\n\n");
    write("         Welcome to xlqy! Select GB or BIG5 (gb/big5):");
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
	    write("\n[1;38mSelect ¹ú±êÂë GB or ¤j¤­½X BIG5 (gb/big5):[0;37;0m");
	    input_to( (: encoding :), ob );
	    return;
	} else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\n[1;38mSelect ¹ú±êÂë GB or ¤j¤­½X BIG5 (gb/big5):[0;37;0m");
	    input_to( (: encoding :), ob );
	    return;
	}
	
	ob->set_encoding(encode);

	ip_name = query_ip_name(ob);
	ip_number = query_ip_number(ob);



// snowcat dec 10 1997
// try strict ban here...weiqi.

	if ("/adm/daemons/band"->is_strict_banned(query_ip_number(ob)) == 1) {
	   	write(HIR"ÄúµÄµØÖ·ÔÚ±¾ MUD Ö®ĞÅÓş±»ÈËÆÆ»µÁË¡£\nÇëE-MAIL:yangidl@mail.qdcatv.com.cnÉêÊö¡£\n"NOR);
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
	// snowcat Mar 11 1998
//   ttl_cnt = total_players();
   if (ttl_cnt == 0) 
     printf("Ä¿Ç°"); // info not available
   else 
     printf("Ä¿Ç°¹²ÓĞ[1;31m%d[0;37;0mÎ»Íæ¼ÒÔÚÏßÉÏ¡£±¾Õ¾", ttl_cnt );
   printf("¹²ÓĞ[1;31m%d[0;37;0mÎ»¹ÜÀíÈËÔ±¡¢[1;36m%d[0;37;0mÎ»Íæ¼Ò£¬ÒÔ¼°[1;33m%d[0;37;0mÎ»ÔÚ³¢ÊÔÁ¬Ïß¡£\n\n",
     wiz_cnt, ppl_cnt, login_cnt );

	// mon 11/7/98
	//check whether user_log still running.
	info = filter_array(call_out_info(), (: $1[1]=="logind_user_log" :));
	if(!sizeof(info)) logind_user_log();


      /* move this check to after user input id.
	 
// mon 4/19/98
// reduce number of pending login users.
#ifdef MAX_USERS
	if(sizeof(usr)>(MAX_USERS+10)) {
	    write("¶Ô²»Æğ£¬"+MUD_NAME+"µÄÍæ¼ÒÒÑ¾­Ì«¶àÁË£¬Çë´ı»á¶ùÔÙÀ´¡£\n");
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
	write("¼øÓÚÑ§ÉúµÄÖ÷ÒªÈÎÎñÊÇÑ§Ï°£¬±¾ÓÎÏ·²»»¶Ó­ÖĞĞ¡Ñ§ÉúÀ´Íæ¡£\n");
	write("ÄúÊÇ·ñÊÇÖĞĞ¡Ñ§Ñ§Éú»òÄêÁä¸üĞ¡£¿([1;31myes[0;37;0m/[1;33mno[0;37;0m)");
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
	    write("ÄúÊÇ·ñÊÇÖĞĞ¡Ñ§Ñ§Éú»òÄêÁä¸üĞ¡£¿(yes/no)");
	    input_to( (: if_young :), ob );
	    return;
	}

	if( arg[0..0] == "y" || arg[0..0] == "Y" )
	{
		write("\nºÃ£¬¸Ï½ôÈ¥Ñ§Ï°²ÅÊÇÕıµÀÀí¡£\n");
		destruct(ob);
		return;
	}

	if( arg[0..0] != "n" && arg[0..0] != "N" ) {
	    write("ÄúÊÇ·ñÊÇÖĞĞ¡Ñ§Ñ§Éú»òÄêÁä¸üĞ¡£¿(yes/no)");
	    input_to( (: if_young :), ob );
	    return;
	}

	cat(XYJ_SITES);
	write("\nÄúµÄÓ¢ÎÄÃû×Ö£º£¨ĞÂÍæ¼ÒÇë¼üÈë [1;31mnew[0;37;0m ×¢²á£©");
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
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
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
		  write("¶Ô²»Æğ£¬"+MUD_NAME+"µÄÍæ¼ÒÒÑ¾­Ì«¶àÁË£¬Çë´ı»á¶ùÔÙÀ´¡£\n");
		  destruct(ob);
		  return;
		} 
	}
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write("¶Ô²»Æğ£¬" + MUD_NAME + "Ä¿Ç°ÏŞÖÆÎ×Ê¦µÈ¼¶ " + WIZ_LOCK_LEVEL
			+ " ÒÔÉÏµÄÈË²ÅÄÜÁ¬Ïß¡£\n");
		destruct(ob);
		return;
	}
	
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
	      write(sprintf("¶Ô²»Æğ£¬´ÓÄãµÄIPµØÖ·²»ÄÜÍ¬Ê±µÇÂ¼%sÎ»ÈËÎï¡£\n",
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
                write("\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º");
		input_to("get_new_id",ob);
		return;
	} else if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
		if( ob->restore() ) {
			write("ÇëÊäÈëÏàÓ¦ÃÜÂë£º");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("ÄúµÄÈËÎï´¢´æµµ³öÁËÒ»Ğ©ÎÊÌâ£¬ÇëÀûÓÃ guest ÈËÎïÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
		destruct(ob);
		return;
	} 
	
        write("Ã»ÓĞÕâ¸öÍæ¼Ò£®£®£®\n");
	write("ÄúµÄÓ¢ÎÄÃû×Ö£º£¨ĞÂÍæ¼ÒÇë¼üÈë new ×¢²á£©");
	input_to("get_id", ob);
	return;
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
                write("\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º");
		input_to("get_new_id", ob);
		return;
        }

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
                write("\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º");
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
	    write("Õâ¸öÃû×ÖÒÑ¾­±»±ğµÄÍæ¼ÒÊ¹ÓÃÁË£®£®£®");
            write("\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º");
	    input_to("get_new_id",ob);
	    return;
	}

	if( file_size(ob->query_save_file() 
		    + __SAVE_EXTENSION__) >= 0 ) {
	    write("Õâ¸öÃû×ÖÒÑ¾­±»±ğµÄÍæ¼ÒÊ¹ÓÃÁË£®£®£®");
            write("\nÇëÄú¸ø×Ô¼ºÈ¡Ò»¸öÓ¢ÎÄÃû×Ö£º");
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
	if( crypt(pass, my_pass) != my_pass ||
	 !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
		write("ÃÜÂë´íÎó£¡");
		write("ÇëÖØĞÂÁ¬Ïß£¬¼üÈëÕıÈ·µÄÃÜÂë»òÁíÈ¡Ò»¸öĞÂµÄÓ¢ÎÄÃû×Ö¡£\n");
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
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
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
   write("ÇëÄúÖØĞÂ´´ÔìÕâ¸öÈËÎï¡£\n");
   confirm_id("y", ob);
}


private void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}	

	if( (yn[0]!='y' && yn[0]!='Y') || !user ) {
	    // user may be destructed during the process.
	    // so I put in this check. mon 4/15/98
		write("ºÃ°É£¬»¶Ó­ÏÂ´ÎÔÙÀ´¡£\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "ÓĞÈË´Ó±ğ´¦( " + query_ip_number(ob)
			+ " )Á¬ÏßÈ¡´úÄãËù¿ØÖÆµÄÈËÎï¡£\n");
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
		write("Ê¹ÓÃÕâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
		input_to("confirm_id", ob);
		return;
	}	

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("ºÃ°É£¬ÄÇÃ´ÇëÖØĞÂÊäÈëÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to("get_id", ob);
		return;
	}
	*/


	write( @TEXT

ÇëÄú¸ø×Ô¼ºÏëÒ»¸ö·ûºÏ¡¼Î÷ÓÎ¼Ç2006¡½Éñ»°ÊÀ½çµÄÖĞÎÄÃû×Ö¡£Õâ
¸öÃû×Ö½«´ú±íÄãÔÚÎ÷ÓÎ¼Ç2006ÖĞµÄÈËÎï£¬¶øÇÒÍùºó½«²»ÄÜÔÙ¸ü¸Ä¡£
Çë²»ÒªÈ¡Ò»Ğ©²»ÑÅ»òÊÇÈİÒ×Ôì³ÉËûÈËÀ§ÈÅµÄÃû×Ö¡£

TEXT
	);
	write("ÄúµÄÖĞÎÄÃû×Ö£º");
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

		write("ÒòÎªÄã²»ÄÜÊäÈëÊÊµ±µÄÖĞÎÄÃû×Ö£¬ÏµÍ³Ö¸¶¨ÄãµÄÃû×ÖÎª£º"+
			arg+"\n");
		write("ÇëÔÚ½øÈëÓÎÏ·ºóÇëÎ×Ê¦°ïÖúĞŞ¸Ä¡£\n");

	    } else {
		write("ÄúµÄÖĞÎÄÃû×Ö£º");
		input_to("get_name", ob);
		return;
	    }
	}

	printf("%O\n", ob);
	ob->set("name", arg);
	write("ÇëÉè¶¨ÄúµÄÃÜÂë£º");
	input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write("ÃÜÂëÖÁÉÙÒªÓÉÎå¸ö×Ö·û×é³É£¬ÇëÖØÉèÄúµÄÃÜÂë£º");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("ÇëÔÙÊäÈëÒ»´ÎÄúµÄÃÜÂë£¬ÒÔÈ·ÈÏÄúÃ»¼Ç´í£º");
	input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("ÄúÁ½´ÎÊäÈëµÄÃÜÂë²¢²»Ò»Ñù£¬ÇëÖØĞÂÉè¶¨Ò»´ÎÃÜÂë£º");
		input_to("new_password", 1, ob);
		return;
	}

	write("ÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
	input_to("get_email",  ob);
}

private void get_email(string email, object ob)
{
	object user;

	ob->set("email", email);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) ) {
	    if(ob) destruct(ob);
	    return;
	}

	write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{
	if( gender=="" ) {
		write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "ÄĞĞÔ");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Å®ĞÔ" );
	else {
		write("¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÄĞĞÔ(m)»òÅ®ĞÔ(f)µÄ½ÇÉ«£º");
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
		write("ÏÖÔÚ¿ÉÄÜÓĞÈËÕıÔÚĞŞ¸ÄÍæ¼ÒÎï¼şµÄ³ÌÊ½£¬ÎŞ·¨½øĞĞ¸´ÖÆ¡£\n");
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
	    user->set("title", "ÆÕÍ¨°ÙĞÕ");
	    user->set("birthday", time() );
	    user->set("potential", 99);
	    user->set("food", user->max_food_capacity());
	    user->set("water", user->max_water_capacity());
	    user->set("channels", ({ "chat","rumor","xyj","sldh","es" }) );
	    log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_number(ob), ctime(time()) ) );

	    ob->set("last_from",query_ip_number(ob));
	    ob->set("last_on",time());

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

       reset_eval_cost();

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
            
      // 5/11/98 mon
	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	write("Ä¿Ç°È¨ÏŞ£º[1;33m" + wizhood(user) + "[0;37;0m\n");
	user->setup();
       //11/2000 by cnd
        
	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	"/adm/daemons/toptend"->topten_checkplayer(user);
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
		if(!wizardp(user) || !user->query("env/invisibility"))
		tell_room(startroom, user->query("name") + "Á¬Ïß½øÈëÕâ¸öÊÀ½ç¡£\n",
			({user}));
	     }
		 
   		if(file_size("/log/notice")>0){
			write(CYN"     ¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô"HIR"Î÷ÓÎ¼Ç2006Á¬ÏßÍ¨Öª"NOR CYN"¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n");
          		write("     "+read_file("/log/notice"));
   	  		write(CYN"     ¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n"NOR);        }
		mbx=ob->query_temp("mbox_ob");
		if (!mbx) {
		  mbx=new(MAILBOX_OB);
		  mbx->set_owner(ob->query("id"));
                }
		num=mbx->query_new_mail();
		if( num>0 ) {
	          write( GRN + "\nÇ§ÀïÑÛ¸æËßÄã£ºÓĞÄú"
		    +chinese_number(num)+
		    "·âĞÅ£¡Çëµ½ÄÏ³Ç¿ÍÕ»À´Ò»ÌË£®£®£®\n\n" + NOR);
		}
		destruct(mbx);
	      	ip_from="/adm/daemons/ipd"->seek_ip_address(query_ip_number(user));
	        CHANNEL_D->do_channel( this_object(), "sys",
		sprintf(NOR WHT "%sÓÉ " HIG "%s" NOR WHT "Á¬Ïß½øÈë,IPÀ´×Ô£º"HIG"%s"NOR,user->name()+"("+capitalize(user->query("id")) + ")", query_ip_number(user), ip_from));  
		}

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

	user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
  
	// 5/11/98 mon
	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	user->reconnect();
	if( !silent && !user->query("env/invisibility")) {
		tell_room(environment(user), user->query("name") + "ÖØĞÂÁ¬Ïß»Øµ½Õâ¸öÊÀ½ç¡£[1;32mGood Luck![2;37;0m\n",
		({user}));
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%sÓÉ%sÖØĞÂÁ¬Ïß½øÈë¡£", user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_name(user)) );
	}
	UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
	int i;
	string *legalid;

	i = strlen(id);
	
	if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×Ö±ØĞëÊÇ 3 µ½ 8 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×ÖÖ»ÄÜÓÃÓ¢ÎÄ×ÖÄ¸¡£\n");
			return 0;
		}
	legalid = explode(read_file(BANNED_ID), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( id == legalid[i] )   {
		  write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
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
		write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö±ØĞëÊÇÒ»µ½Áù¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×Ö·û¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) {
		write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
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
