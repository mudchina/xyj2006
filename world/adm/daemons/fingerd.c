// fingerd.c
#include <ansi.h>
#include <net/dns.h>
int query_only_ip(object *ob);
int sort_user(object ob1, object ob2);

void create() { seteuid( getuid() ); }

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
	return (month?month + "月":"") + (day?day + "天":"") + 
	(hour?hour + "小时":"") + min + "分";
}

string finger_all()
{
	object *ob;
	string msg, fip;
	int i,ips;

	ob = users();
	msg = "";
	reset_eval_cost();
	if ( !wizardp(this_player()) )  // player finger
	{
		reset_eval_cost();
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
                ob = sort_array(users(), "sort_user", this_object());
                reset_eval_cost();
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-10s%-4s%-20s%-7s%s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				ob[i]->query_encoding()?"B5":"GB",
				age_string( (int)ob[i]->query("mud_age")), 
				query_idle(ob[i]) + "秒", 
(i<1?query_ip_name(ob[i]):
(query_ip_name(ob[i])==query_ip_name(ob[i-1])?HIR+query_ip_name(ob[i])+NOR:
                                query_ip_name(ob[i]))));
//query_ip_name(ob[i]));
		}
                ips=query_only_ip(ob);

		return "■ 西游记   \n" + 
"—————————————————————————————————————\n"
+ "姓名          帐号          年龄                发呆   连线\n" +
"—————————————————————————————————————\n"
+ msg +
"—————————————————————————————————————\n"
                +"注：排除由同一IP连线，实际登陆有 "+ips+" 人。\n";

	}
}
	
string finger_user(string name)
{
	object ob, body;
	string msg, mud;
	int public_flag;

	reset_eval_cost();
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
	
   if (!this_player()->query_temp("do"))
      {
         this_player()->set_temp("ob",name);
         this_player()->set_temp("do",1);
      }  else
      this_player()->delete_temp("ob");
	if (!this_player() || !wizardp(this_player()) )  // player finger
	// !this_player() is used for inter-mud finger.
	// in that case, this_player() is not defined, so treat as player.
	// mon 8/27/97
	{
	
		if( objectp(body = find_player(name)) && geteuid(body)==name )
		{
			public_flag = body->query("env/public")?1:0;
		} else 
		{
			body = LOGIN_D->make_body(ob);
			if( !body || !body->restore() ) {
			  destruct(body);
			  destruct(ob);
			  return "没有这个玩家。\n";
                        }
			public_flag = body->query("env/public")?1:0;
			destruct(body);
		}		
		
		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件地址：\t%s\n上次连线：\t%s\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			public_flag?ob->query("email"):"不告诉你",
     (wiz_level(SECURITY_D->get_status(name))>wiz_level("(player)"))?"不告诉你":ctime(ob->query("last_on"))
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
			"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("last_from"),
			ctime(ob->query("last_on"))
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

int query_only_ip(object *ob)
{       
        int i,j,k,count,total;

        total=sizeof(ob);
        reset_eval_cost();
        for ( i=0; i<sizeof(ob); i++)
        {
                count=1;k=sizeof(ob);
                for (j=0; j<k;j++)
                        if (j!=i&&query_ip_name(ob[i])==query_ip_name(ob[j]) )
                        {
                                ob=ob-({ob[j]});
                                count++;
                                k=sizeof(ob);
                        }
                total=total-count+1;
        }
        return total;
}
int ip_name(object ob1, object ob2)
{
        string name1, name2;
        
        name1 = query_ip_name(ob1);
        name2 = query_ip_name(ob2);

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int sort_user(object ob1, object ob2)
{
        reset_eval_cost();
        if( wizardp(ob1) && !wizardp(ob2) ) return 1;
        
        if( wizardp(ob2) && !wizardp(ob1) ) return -1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob1) 
                        - (int)SECURITY_D->get_wiz_level(ob2);
        if( ob1->query("id") && !ob2->query("id") )
                return 1;

        reset_eval_cost();
        if( ob2->query("id") && !ob1->query("id") )
                return -1;

        if( !ob1->query("id") && !ob2->query("id") )
                return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");

        return strcmp(query_ip_name(ob1),query_ip_name(ob2));
}


