// who.c

#include <net/dns.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string str, *option;
	object *list;
	int i, j, ppl_cnt;
	int opt_long, opt_id, opt_wiz;

	if( arg ) {
		string verbose="", rwho="";

		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1;verbose+="-l ";continue;
				case "-i": opt_id = 1;verbose+="-i ";continue;
				case "-w": opt_wiz = 1;verbose+="-w ";continue;
				default:
				   if(option[i][0]=='@' ) {
				       rwho=option[i][1..sizeof(option[i])];
                                   } else return notify_fail("指令格式：who [-l|-i|-w]\n");
                        }
                if(strlen(rwho)>0) {
		   RWHO_Q->send_rwho_q(rwho, me, verbose);
		   write("网路讯息已送出，请稍候。\n");
	 	   return 1;
		}
	}

	if( opt_long && !remote ) {
		if( (int)me->query("sen") < 20 )
			return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
		me->receive_damage("sen", 1);
	}

	if(remote) {
	    opt_long=0; // disable -l for remote because too long.
#ifdef INTERMUD_NAME
	    str = "■ " + INTERMUD_NAME + "\n";
#else
	    str = "■ " + MUD_NAME + "\n";
#endif
	} else
	    str = "■ " + MUD_NAME + "\n";

	str += "─────────────────────────────────────\n";
	
        list = users();

	ppl_cnt = 0;
	if( opt_long || opt_wiz ) {
		j = sizeof(list);
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( me && 
				wizardp(list[j]) && !me->visible(list[j]) ) 
			    continue;
			if( remote && 
			  list[j]->query("env/invisibility") ) continue;
			if( opt_wiz && (!wizardp(list[j]) || (string)wizhood(list[j])=="(elder)") ) continue;//here won't show "elder" as wiz, added by weiqi.
			str = sprintf("%s%12s %s\n",
				str,
				RANK_D->query_rank(list[j]),
				list[j]->short(1)
			);
			ppl_cnt++;
		}
	} else {
		j = sizeof(list);
		while( j-- ) {
			// Skip those users in login limbo.
			if( !environment(list[j]) ) continue;
			if( me && wizardp(list[j]) &&
				!me->visible(list[j]) ) continue;
			if( remote &&
			  list[j]->query("env/invisibility")) 
				continue;

			str = sprintf("%s%-15s%s",
				str,
				opt_id ? capitalize(list[j]->query("id")): list[j]->name(1),
				(ppl_cnt%5==4? "\n": "")
			);
			ppl_cnt++;
		}
		if( ppl_cnt%5 ) str += "\n";
	}
	
//	if(!remote || strlen(str)<1024) {
	//don't add last two lines for remote who if it is too long.
	//small packets maybe arrived to remote machine out of order.
	  str += "─────────────────────────────────────\n";
	  str = sprintf("%s共有 %d 位玩家连线中，系统负担：%s\n", str, ppl_cnt,
		query_load_average() + "\n");
//        }

	if( remote ) return str;

	me->start_more(str);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;

	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("daoxing")+(int)ob2->query("combat_exp") - (int)ob1->query("daoxing")-(int)ob1->query("combat_exp");
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w] 或
           who [-l|-i|-w] @mud_name

这个指令可以列出所有在线上的玩家及其等级。

-l        选项列出较长的讯息。
-i        只列出玩家的英文代号。
-w        只列出线上所有的巫师。
@mud_name 列出其它站点的玩家讯息，可用mudlist查看联线站点。

相关指令： finger, mudlist
HELP
    );
    return 1;
}
