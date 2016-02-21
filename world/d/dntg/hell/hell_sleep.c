
//inherit ROOM;
#include <ansi.h>

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

int is_drunk(object me) {
  int limit = me->query("con")*6+(int)me->query("max_force")/50;
  int duration=me->query_condition("drunk");
  if  (duration > limit/10 ) return 1;
  return 0;
}

void init()
{
  add_action ("do_sleep","sleep");
}

int do_sleep (string arg)
{
  object me = this_player();
  int phase = get_current_day_phase();

  if (me->query("combat_exp")<50000) return 0;
  if (phase > 0 && phase < 5) {tell_object(me,"大白天的睡什么觉？\n");return 1;}
  if (!is_drunk(me)) {tell_object(me,"你精神十足，不需要睡觉。\n");return 1;}
  if (me->query("dntg/hell")=="done") return 0;
//  if(!me->query("HellZhenPass")) return 0
  if (me->query_temp("dntg_hell/next")) return 0;

  message_vision ("$N喝得酩酊大醉，倚在在铁板桥边松阴之下，霎时间睡着了。\n",me);
  remove_call_out ("go_hell");
  call_out ("go_hell",2+random(5),me);
  return 1; 
}

void go_hell(object me) {
  object env;
  object hei,bai;
  object piwen;
  string *wang=({"qingguang","songdi","chujiang","chuguan","pingdeng",
                 "dushi","taishan","lunzhuan","biancheng","yanluo",
               });

  mapping name=(["qingguang":"秦广王","songdi":"宋帝王","chujiang":"楚江王",
    "chuguan":"仵官王","pingdeng":"平等王","dushi":"都市王","taishan":"泰山王",
    "lunzhuan":"轮转王","biancheng":"卞城王","yanluo":"阎罗王" ]);

  string wang1=wang[random(10)];
  me->set_temp("dntg_hell/next",wang1);
  
  tell_object(me,HIB"\n睡梦中忽见两人走了过来，大声喝道：“"+me->query("name")+
               "，汝阳寿已尽，吾等奉冥王之命，特来勾你。”\n"
                +"说罢不容分说，拿根铁索往你颈上一套，拉了就走。\n\n"NOR);
  me->move("/d/death/new-zhaopo");
  env=environment(me);
  if (!bai=present("bai wuchang",env)) {
     bai=new("/d/death/npc/baiwuchang");
     bai->move(env);
  }
  if (!hei=present("hei wuchang",env)) {
     hei=new("/d/death/npc/heiwuchang");
     hei->move(env);
  }

  piwen=new("/d/dntg/hell/piwen");
  if (random(2)) piwen->move(hei);
   else piwen->move(bai);
  piwen->set("long","    查"+me->query("name")+
             "阳寿已尽，着令黑白无常将其魂魄勾拿归案。\n\n"+
             "                            "+name[wang1]+"  谕\n\n\n");

  piwen->set("target",me->query("name"));
}
