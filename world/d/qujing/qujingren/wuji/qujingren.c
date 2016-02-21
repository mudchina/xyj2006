// 取经人-乌鸡模块

#include "/d/qujing/qujingren/qujingren.c"

static int DP_DAWN = 0;
static int DP_SUNRISE = 1;
static int DP_MORNING = 2;
static int DP_NOON = 3;
static int DP_AFTERNOON = 4;
static int DP_EVENING = 5;
static int DP_NIGHT = 6;
static int DP_MIDNIGHT = 7;

// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

void wakeup(object me,object where);
int to_meng();

void me_init()
  {
  set("redef_wake",1);
  set("redef_accept_obj",1);
  }

void init()
{
        object ob;

        ::init();
	 
       if( interactive(ob = this_player()) && !is_fighting() ) {
          if( ob->query_temp("obstacle/have_gui")==1) 
   	    {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
 	    }
        }
}

int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
	if (t>=day_phase[i]["length"])
	    t -= (int)day_phase[i]["length"];
	else
	    break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}


int wakeup1 (object me,object where)
{
  object who = this_player();
  int phase = get_current_day_phase();

  if (random(5))
    {
    wakeup(me,where);
    return 0;
    }
  if (phase > 0 && phase < 5)
    {wakeup(me,where);
    return 0;
   }

  me->enable_player();
  while( environment(me)->is_character() )
	me->move(environment(environment(me)));
  me->set_temp("block_msg/all", 0);
  message_vision ("$N大叫一声，醒了过来。连忙叫：徒弟！徒弟！\n",me);
  set("inquiry/meng" , (: to_meng :) );
  set("inquiry/梦",  (: to_meng :) );
  set_temp("have_dream",1)		;
  return 1; 
}

int to_meng()
  {
  object me=this_object();
  object where=environment(me);

  message_vision("取经人说道:“我梦见乌鸡国王要我救他，还留下个"
 		+"金厢白玉圭为证”。\n",me);
  if (where->query("short")!="西厢房") return 1;

  set("inquiry/金厢白玉圭", "已经留下了，四处找找吧" );
  where->set("leave_gui",1);
  return 1;
  }

int accept_object1(object who,object ob)
  {
  object me=this_object();

  if (who->query("obstacle/qujing")!="ren")return 0;
  if (ob->query("id")!="yu gui")return 0;
  message_vision("$N点了点头说道：你去把太子引过来吧。\n",me);
  who->set_temp("obstacle/have_gui",1);
  return 1;
  }

void greeting(object ob)
{
   object me=this_object();
   mixed name;
   object room;
   object taizi;

   if( !ob || !visible(ob) || environment(ob) != environment() ) return;
   if( taizi=present("tai zi",environment()))
     {
     ob=taizi->query_leader();
     ob->delete_temp("have_gui");
     command_function("give yu gui to tai zi"); 
     command_function("whisper zi 如此,这般..");
     message_vision("$N说道:“我不信,且待我回宫问我娘亲去。”\n",taizi);
     message_vision("说罢遂往东离去\n",ob);
     room = load_object("/d/qujing/wuji2/zym");
     taizi->set_leader(0);
     taizi->move(room);
     taizi->set("idle",2);
     delete_temp("have_dream");

     }
}


