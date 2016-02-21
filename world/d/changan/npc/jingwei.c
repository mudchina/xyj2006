//Cracked by Roath

#include <ansi.h>

inherit NPC;

/*
static int DP_DAWN = 0;
static int DP_SUNRISE = 1;
static int DP_MORNING = 2;
static int DP_NOON = 3;
static int DP_AFTERNOON = 4;
static int DP_EVENING = 5;
static int DP_NIGHT = 6;
static int DP_MIDNIGHT = 7;
*/
// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

string seashore="/d/changan/eastseashore";
string beach="/d/changan/beach";

void flyaway();

/*
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

*/
void create() {
  set_name("精卫",({"jing wei","wei","bird"}));
  set("long","一只可爱的小小鸟，白喙赤足，色彩斑斓，相传是炎帝的小女儿。\n");
  set("gender","女性");
  set("age",5);
  set("per",999);
  set("str",30+random(10));
  set("cor",40);
  set("cps",30);
  set("max_sen",400);
  set("sen",400);
  set("max_kee",400);
  set("kee",400);

  set("combat_exp", 3000);
  set("daoxing",3000);
  set_skill("unarmed", 10);
  set_skill("baihua-zhang", 10);
  map_skill("unarmed", "baihua-zhang");
  set_skill("dodge", 20);
  
  set("limbs", ({
               "头部", "颈部", "胸口", "后心", "尾巴","喙部",
               "左脚", "右脚", "左翅", "右翅",}) );

  setup();
/*
  set("chat_msg", ({
            (: flyaway :),
             
        }) );
  set("chat_chance",30);
*/
  set("inquiry", ([
     "name" : "我是炎帝的女儿，叫女娃，在东海游泳时淹死了，就化成现在的样子。",
     "here" :"这里就是淹死我的东海(sea)，我一定要把它填(fill)平！",
     "填海" : "填海是件很危险的事，你要是觉得本领够了，可以随(sui)我一起去。",
  ]) );
  call_out("flyaway",10+random(10));

}

void flyaway() {
  object *all;
   string dest;
  int phase = NATURE_D->query_current_day_phase();
   object me=this_object();
//   command("say hi.");

   call_out("flyaway",10+random(10));
  if (!living(me)) return;
  if (!environment()) return;
  all=all_inventory(environment(me));
   if (environment()->query("short")=="东海之滨") {
     if (random(2)) {
         message_vision("$N从地上叼起一些石块。\n",me);
         return;
     }
     dest=beach;
   } else if (environment()->query("short")=="东海海滩") {
       if (random(2)) {
          message_vision("$N将嘴里衔着的石块投入海中。\n",me);
          return;
       }
       dest=seashore;
   } else {
//     command("say where am i?");
     return;
   }
   message_vision("$N拍着翅膀飞走了。\n",me);
   me->move(dest);
   message_vision("$N飞了过来。\n",me);
   if (!all) return;
   if (phase<6) return;
   for (int i=0;i<sizeof(all);i++)
     if (userp(all[i]) && all[i]->query_temp("follow_jingwei")) {
        all[i]->move(dest);
        all[i]->delete_temp("follow_jingwei");
     }
}

void init() {
   add_action("do_gen","sui");
}

int do_gen(string arg) {
  int phase = NATURE_D->query_current_day_phase();
   object me=this_player();
   object jignwei=this_object();

  if (!arg && arg!="jing wei" && arg!="bird" && arg!="wei")
    return notify_fail("你要跟谁？\n");
  if (me->query_temp("follow_jingwei"))
    return notify_fail("你已经在跟着精卫了。\n"); 
  if ((phase >0) && (phase<6)) 
    return notify_fail("精卫对你说：“白天天气太热了，晚上我再带你去吧。”\n");

  me->set_temp("follow_jingwei",1);
  message_vision("$N决定跟随精卫一起去填海！\n",me);
  return 1;
}
