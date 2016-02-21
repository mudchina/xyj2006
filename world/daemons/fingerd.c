//Cracked by Roath
// fingerd.c

#include <net/dns.h>

void create() { seteuid( getuid() ); }
string *exclude =({});
string age_string(int time)
{
	int month, day, hour, min, sec;

	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?chinese_number(month) + "月":"") + (day?chinese_number(day) + "天":"") + 
	(hour?chinese_number(hour) + "小时":"") + chinese_number(min) + "分钟";
}

string finger_all()
{
	object *ob;
	string msg, fip;
	int i;

	ob = users();
	msg = "";
	if ( !wizardp(this_player()) )  // player finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-14s%-14s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				query_idle(ob[i]) + "s");
		}
		return "■ 西游记 \n" + 
		"——————————————————\n"
		+ "姓名          帐号          发呆\n" +
		"——————————————————\n"
		+ msg +
		"——————————————————\n";
	} else  	// wizard finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-10s%-4s%-14s%-7s%s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				ob[i]->query_encoding()?"B5":"GB",
				 chinese_number(ob[i]->query("age")), 
				query_idle(ob[i]) + "s", query_ip_name(ob[i]));
		}
		return "■ 西游记   \n" + 
"—————————————————————————————————————\n"
+ "姓名          帐号          年龄          发呆   连线\n" +
"—————————————————————————————————————\n"
+ msg +
"—————————————————————————————————————\n";
	}
}
	
string finger_user(string name)
{
	object ob, body;
	string msg, mud;
	int public_email,public_webpage,public_icq;

	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_gfinger_q(mud, name, this_player(1));
		return "网路指令传送过程可能需要一些时间，请稍候。\n";
	}

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) {
	  destruct(ob);
	  return "没有这个玩家。\n";
        }	
	
	if ((!this_player() || !wizardp(this_player())) )  // player finger
	// !this_player() is used for inter-mud finger.
	// in that case, this_player() is not defined, so treat as player.
	// mon 8/27/97
	{
	
		if( objectp(body = find_player(name)) && geteuid(body)==name )
		{
			public_email = body->query("env/pub_email")?1:0;
			public_webpage = body->query("env/pub_webpage")?1:0;
			public_icq = body->query("env/pub_icq")?1:0;
		} else 
		{
			body = LOGIN_D->make_body(ob);
			if( !body || !body->restore() ) {
			  destruct(body);
			  destruct(ob);
			  return "没有这个玩家。\n";
                        }
			public_email = body->query("env/public")?1:0;
			public_webpage = body->query("env/pub_webpage")?1:0;
			public_icq = body->query("env/pub_icq")?1:0;
			destruct(body);
		}		
		if(this_player()==body)
		  msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件地址：\t%s\n个人主页地址：\t%s\n[ICQ/OICQ]号码：%s\n上次连线地址：\t%s( %s )\n\n%s\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("webpage"),
			ob->query("icq"),
			ob->query("last_from"),
			ctime(ob->query("last_on")),
			stringp(ob->query("profile"))?(ob->query("profile")):"",
		);
		else 
		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n电子邮件地址：\t%s\n个人主页地址：\t%s\n[ICQ/OICQ]号码：%s\n上次连线：\t%s\n\n%s\n",
			ob->query("id"),
			ob->query("name"),
member_array(ob->query("id"),exclude)==-1?SECURITY_D->get_status(name):"(immortal)",
			public_email?ob->query("email"):"不告诉你",
			public_webpage?ob->query("webpage"):"不告诉你",
			public_icq?ob->query("icq"):"不告诉你",
			ctime(ob->query("last_on")),
			stringp(ob->query("profile"))?(ob->query("profile")):"",
		);
		// !body->query("env/invisibility") added by snowcat
		if( objectp(body = find_player(name)) 
			&& geteuid(body)==name 
			&& interactive(body)
			&& (!wizardp(body) || 
				!body->query("env/invisibility")) ) {
		    // can only query_idle on an interactive player.
		        int idle=query_idle(body);

			msg += sprintf("%s目前正在连线",body->name(1));
			if(idle>59) 
			    msg+=sprintf("，已发呆 %d 秒钟。\n", idle);
			else 
			    msg+="中。\n";
		}
	} else  	// wizard finger
	{
		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件地址：\t%s\n个人主页地址：\t%s\n[ICQ/OICQ]号码：%s\n上次连线地址：\t%s( %s )\n\n%s\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("webpage"),
			ob->query("icq"),
			ob->query("last_from"),
			ctime(ob->query("last_on")),
			stringp(ob->query("profile"))?(ob->query("profile")):"",
		);
		// !body->query("env/invisibility") added by snowcat, removed by mon
		if( objectp(body = find_player(name)) 
			&& interactive(body)
			&& geteuid(body)==name ) {
			msg += sprintf(
				"%s（%s）目前正在从 %s 连线，已发呆 %d 秒钟。\n", 
				body->name(1),
				age_string( (int)body->query("mud_age")),
				query_ip_name(body), query_idle(body));
		}
	}	
	
	destruct(ob);
	return msg;
}

//this function is not used.  remote finger still use finger_user.
//mon 3/7/98
varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) {
	        destruct(ob);
		return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
        }
	if( chinese_flag ) msg =  sprintf(
		"\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "目前正在线上。\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	if(ob->restore()) return ob;
	else {
	  destruct(ob);
	  return 0;
        }
}

