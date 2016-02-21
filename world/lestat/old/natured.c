// Modified by vikee
// 2001-2-15 13:12
// Natured.c

#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
int current_day_phase, current_month;
void auto_save(object *user, int size, int i);
mapping *day_phase;
int online_user();
string ppl;

string *month_time = ({
	"春天悄悄地走来了，",
	"春风轻轻地拂过你的脸庞，",
	"天气逐渐变暖了，",
	"已经是初夏时节了，",
	"知了的叫声让你感觉到了盛夏的气息，",
	"天气变得非常闷热，",
	"虽然是秋天了，天气还是有些热，",
	"中秋佳节快到了，",
	"一阵秋风吹来，卷起了地上的落叶，",
	"秋去冬来，",
	"寒风凛冽，",
	"快到年关了，",
});

string *month_desc = ({
	HIW"隆冬的"NOR,
	HIW"寒冬的"NOR,
	HIG"初春的"NOR,
	HIG"早春二月的"NOR,
	HIG"阳春三月的"NOR,
	HIC"初夏的"NOR,
	HIC"盛夏的"NOR,
	HIR"仲夏的"NOR,
	HIY"初秋的"NOR,
	HIY"秋高气爽的"NOR,
	YEL"深秋的"NOR,
	WHT"初冬的"NOR,
});

int query_current_day_phase() { return current_day_phase; }
mapping *read_table(string file);
void init_day_phase();

void create()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "三":
		case "四":
		case "五":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "六":
		case "七":
		case "八":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "九":
		case "十":
		case "十一":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "零":
		case "二":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "一":
		        if(get_day=="一")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		        
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}
void auto_save(object *user, int size, int i)
{
    int j;
    
    for(j=i;j<i+5;j++) {
	if(j>=size) return;
	if(!user[j]) continue;
	if(!environment(user[j])) continue; // skip those still in login.
	if(user[j]->save())
	    tell_object(user[j], "〖"HIY"档案储存"NOR"〗: "HIY"您的档案已经自动存储。\n"NOR);
    }
    
    call_out("auto_save", 10, user, size, i+5);
}
void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];           // hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];

	// MUD 运行时间久了，时间会有偏差，这里是调整程序，每小时执行一次
	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.
	remove_call_out("update_day_phase");	

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	int i,j;
	object *inusers,envroom;
	string str;
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
        i=0;
        // here is modified by vikee 2001-2-15 13:15
        str=HIW"【"+HIG"窗外"+HIW"】："NOR+day_phase[current_day_phase]["time_msg"];
        inusers=users();
        for (i;i<(j=sizeof(inusers));i++)
        {
            envroom=environment(inusers[i]);
            if (envroom)
           {
            if ( intp(envroom->query("outdoors")))
             {
               if (envroom->query("outdoors")<1)
             	tell_object(inusers[i],str+"\n");
               else 
               tell_object(inusers[i],day_phase[current_day_phase]["time_msg"]+"\n");
             }
            else
             {
             	tell_object(inusers[i],day_phase[current_day_phase]["time_msg"]+"\n");
             }
          }     
       }
       call_out("update_day_phase", day_phase[current_day_phase]["length"]);

}


void event_midnight()
{       
	
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "三":
		case "四":
		case "五":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "六":
		case "七":
		case "八":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "九":
		case "十":
		case "十一":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "零":
		case "二":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     
		     case "一":
		        if(get_day=="一")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:		
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

int online_user()
{ int i,ppl_cnt;
object *usr = users();
for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) ) continue;
		ppl_cnt++;
	}
	return ppl_cnt;
}
void event_sunrise()
{
            int avg_num,record_num,online_num,total_num,times;
            string avg_temp,total_temp,times_temp;
            object *user=users();
            online_num = online_user();
            times = atoi(read_file(__DIR__"record_times",1));
            times++;
            record_num = atoi(read_file(__DIR__"total_num",1));
            total_num = online_num + record_num;
            avg_num = total_num / times;
            total_temp = sprintf("%d",total_num);
            times_temp = sprintf("%d",times);
            avg_temp = sprintf("%d",avg_num);
            write_file(__DIR__"total_num",total_temp,1);
            write_file(__DIR__"record_times",times_temp,1);
            write_file(__DIR__"avguser",avg_temp,1);
            
            
	    remove_call_out("auto_save");
	    call_out("auto_save", 10, user, sizeof(user), 0);
}
void event_evening()
{
        object area,who;
        mixed file,dir;
        int amount,i;
          dir=get_dir("/data/city/");
       if(!dir) return; 
 	
	for(i=0;i<sizeof(dir);i++)
      if( sscanf(dir[i], "%s.o", file) ) {
      area=new("/obj/area1.c");
      area->create(file);
      if(area->query("no_use"))
   {
      destruct(area);

      continue;
    } 

     if(area->query("owner"))  
{
amount=area->query("people")*(area->query("farm")+area->query("trade"))*area->query("tax")/1000;
if(amount <=0) return;

    who=find_player(area->query("owner"));
    if(who) {
	who->add("balance",amount);
	if(!who->save()) {
	    log_file("city_log","Failed to return "+amount+
		    " coin to "+area->query("owner")+"\n");
	    return;
	}
	log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
 tell_object(who,area->query("short")+"税收"+MONEY_D->money_str(amount)+",已经存入你的户头。\n");

    } else {
	who=new(USER_OB);
	who->set("id",area->query("owner"));
	if(!who->restore()) {
	    log_file("city_log","Failed to return "+amount+
		    " coin to "+area->query("owner")+"\n");
	    destruct(who);
	    return;
	} else {
	    who->add("balance",amount);
	    if(!who->save(1)) { // save(1) will not erase autoload.
		log_file("city_log","Failed to return "+amount+
			" coin to "+area->query("owner")+"\n");
		destruct(who);
		return;
	    } 
	    log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
	    destruct(who);
	    }
    }

}
}
        return;
}
void event_noon()
{
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "你觉得一阵晕眩，好像有一股能量从身上被人吸走了。\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "随着太阳升到天空的正中央，你觉得你的法力开始消失了。\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
                month_desc[current_month]) + "。\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }
