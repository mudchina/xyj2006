
#include <ansi.h>;
inherit BULLETIN_BOARD;

string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
          "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "年";
        c_month  = c_month + "月";
        c_week = " 星期"+c_week;

        c_time = chinese_number(day) + "日";
        c_time += chinese_number(hour) + "点";
        c_time += chinese_number(minute) + "分";
        // maybe not need srcond to show
        c_time += chinese_number(second) + "秒";
        if (type) {
                switch( type ) {
                        case 5: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 1: return year+"年"+(member_array(month, month_name) + 1)+
                          "月"+day+"日"+hour+"点"+minute+"分"+second+"秒";
                        case 6: return (member_array(month, month_name) + 1)+
                          "月"+day+"日"+hour+"点"+minute+"分";
                        case 7: return year+"/"+(member_array(month, month_name) + 1)+
                          "/"+day+"";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}
// create part和普通的BOARD差不多
void create()
{
  set_name(HIG"西游记2006--莱芜站新闻版"NOR, ({ "newsboard"}) );

  set("location", "/d/wiz/newsroom"); 
  set("board_id", "news_b");            
  setup();
  set("capacity", 1000);
}
// 这个部份是用来在login时调用的。
int check_news(object me)
{
  int num,i,last_time_read;
  mapping *notes, last_read_time;
  string myid,msg="";
  
  notes = query("notes");
  last_read_time = me->query("board_last_read");
  myid = query("board_id");
  
  if( !pointerp(notes) || !sizeof(notes) ) return 1;

  if(userp(me))
  {
          i=sizeof(notes)-me->query("LastReadNews");

          if(i < 6 && i > 0) // 小于6条新闻才显示标题，不然会FLOOD
          {
                  msg = HIY"\n\n ━━━━━━━━━━━━━━━ "HIR"西游记2006--莱芜站最新消息"HIY" ━━━━━━━━━━━━━━━    \n\n"NOR;
                  
                  if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                          num = 1;
                          
                  else
                          for(num = 1; num<=sizeof(notes); num++)
                                  if( notes[num-1]["time"] > last_read_time[myid] ) break;
                                  
                  if (mapp(last_read_time)) last_time_read = last_read_time[myid];
                  for(i=sizeof(notes)-1 ; i>num-2 ; i--)
                  {
                          msg += sprintf("<%3d>"NOR,i+1);
                          msg += sprintf("     %-=36s %18s (%s)\n",
                                  notes[i]["title"], notes[i]["author"],
  //                              CHINESE_D->chinese_time(5, ctime(notes[i]["time"])));
                      chinese_time(7,(string)localtime(time()) ));
                          //By waiwai@mszj 2000/11/13 
                  }
                  
                  msg += HIY"    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    \n\n"NOR;
  me->start_more(msg);
          }
          
          i=sizeof(notes)-me->query("LastReadNews");
          
          write("\n从您上次阅读到现在"+((i==0)? "没有任何":"共有"+HIY+chinese_number(i)+NOR"条")+"新闻。\n\n");
          if(i>10) write("你可以 Help news 来查看西游记2006--莱芜站新闻系统的使用方法。\n"); //i>10 提醒不知道有NEWS系统的玩家使用news
  }
}

int main(object me, string arg)
{
  int num,i,last_time_read;
  mapping *notes, last_read_time;
  string myid,msg;

  last_read_time = me->query("board_last_read");
  myid = query("board_id");
  notes = query("notes");
  i=sizeof(notes)-me->query("LastReadNews");
  if( !pointerp(notes) || !sizeof(notes) )
          return notify_fail(HIC"「西游记2006--莱芜站」目前没有任何新闻发布。\n"NOR);
          
 if( !arg ) 
  {
          if(i>10) write(HIC"你可以"HIR" Help news "HIC"来查看西游记2006--莱芜站新闻系统的使用方法。\n"NOR); //10
                  return notify_fail(
"「西游记2006--莱芜站」目前共有"+HIW+chinese_number(sizeof(notes))+NOR"条新闻"+((i==0)? "。":"，您有"+HIY+chinese_number(i)+NOR"条新闻尚未阅读。")+"\n"); }
                          
          if( arg=="all") // 显示所有新闻
          {
                  msg = "\n\n ━━━━━━━━━━━━━━━ "HIW"西游记2006--莱芜站新闻一览"NOR" ━━━━━━━━━━━━━━━   \n\n";
                  notes = query("notes");
                  
                  if (mapp(last_read_time)) last_time_read = last_read_time[myid];
                  for(i=sizeof(notes)-1 ; i>-1 ; i--)
                  {
                          msg += sprintf("%s<%3d>" NOR,
                          notes[i]["time"] > last_time_read ? HIY: "", i+1);
                          msg += sprintf("     %-=36s %18s (%s)\n",
                                  notes[i]["title"], notes[i]["author"],
          //                      CHINESE_D->chinese_time(5, ctime(notes[num]["time"])));
          chinese_time(7,(string)localtime(time())) );
                          //By waiwai@mszj 2000/11/13 
                  }
                  msg += "\n";
                  me->start_more(msg);
                  return 1;
                  
          }
          else
          if ( arg=="new" )  // 显示最新新闻
          {
                  if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                          num = 1;
                  else
                          for(num = 1; num<=sizeof(notes); num++)
                                  if( notes[num-1]["time"] > last_read_time[myid] ) break;
                                  
          } else if( !sscanf(arg, "%d", num) )
          
  return notify_fail("你到底要看第几条新闻呀？\n");
  
  if( num < 1 || num > sizeof(notes) )
          return notify_fail(HIC"看清楚点，好像没有这条新闻耶。\n"NOR);
          
  num--;
//        me->start_more( sprintf("\n\n%s\n"HIR"新闻主题："HIY"%s\n"HIW"新闻巫师："NOR"%s\n"HIG"新闻时间：%s\n"NOR
  me->start_more( sprintf("\n\n%s\n"HIR"新闻主题："HIY"%s\n"HIW"新闻发布：%s\n"HIG"新闻时间：%s\n"NOR

  CYN"-------------------------------------------------------------------------------\n"NOR,
          BBLU HIG"「"HIG"西游记2006--莱芜站"HIG"」第"+chinese_number(num + 1)+"条新闻 "NOR, 
          notes[num]["title"], notes[num]["author"],
//                CHINESE_D->chinese_time(5, ctime(notes[num]["time"])))
          chinese_time(7,(string)localtime(time())) )
                          //By waiwai@mszj 2000/11/13 

          + notes[num]["msg"]+
  CYN"-------------------------------------------------------------------------------\n\n"NOR, );

  if( !mapp(last_read_time) )
          me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
  else 
          if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                  last_read_time[myid] = notes[num]["time"];

  if(me->query("LastReadNews") < num + 1)
          me->set("LastReadNews",num+1);

  return 1;

}

void init()
{
  object me=this_player();
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(wizard)") )
  {
          add_action("do_post", "post");
          add_action("do_discard", "discard");
      }   
}

int do_post(string arg)
{
  mapping note;

  if(!arg) return notify_fail("新闻要个加题目。\n");

  note = allocate_mapping(4);
  note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
  note["id"] = this_player()->query("id"); 
  this_player()->edit( (: done_post, this_player(), note :) );
  return 1;
}

void done_post(object me, mapping note, string text)
{
  mapping *notes;

  note["time"] = time();
  note["msg"] = text;
  notes = query("notes");
  if( !pointerp(notes) || !sizeof(notes) )
          notes = ({ note });
  else
          notes += ({ note });

  if( sizeof(notes) > query("capacity"))
          notes = notes[query("capacity")/2 .. query("capacity")];

  set("notes", notes);
  save();
  restore();
// 使用channel显示提示有了最新新闻
message("channel:rumor", HIR"【新闻发布】："HIG"「西游记2006--莱芜站」"HIY"有了最新更新新闻，请用 "HIR"news"NOR HIY" 查看！！！ \n"NOR, users());
                          //By waiwai@mszj 2000/11/13 

  tell_object(me, HIY"新闻发表完毕。\n"NOR);

  return;
}

int help(object me)
{
    write(@HELP
「西游记2006--莱芜站」新闻系统指令 

指令格式 :
news                    查看共有的和最新发布的新闻。
news all                西游记2006--莱芜站新闻一览。 
news new                阅读最新的新闻。 
news <新闻编号>         查看此编号新闻的详细内容。 
HELP
    );
    return 1;
}

