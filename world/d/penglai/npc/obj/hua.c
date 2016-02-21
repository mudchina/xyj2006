//modified by vikee for xlqy
//2000-11-24 8:30

#include <ansi.h>

#include <dbase.h>
#include <armor.h>

inherit NECK;
#include <flowers.h>

string chinese_daoxing(int);
void create() {
    set_name(flowers[random(sizeof(flowers))], ({ "flower"}));
  set_weight(100);
  set("unit", "朵");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  setup();
}

void init() {
    add_action("do_eat","eat");
}

int do_eat(string arg) {
  object me=this_player();
   int qn=0;
  int score=query("score");
  if (!arg) return 0;
if (me->query("family/family_name")=="月宫")
score=random(score)*2;
//added by vikee if the player belong to moon,get the double reward
  if (this_object()!=present(arg,me)) return 0;
   message_vision(HIC"$N吃下一朵"+query("name")+HIC"，只觉得香气扑鼻，齿颊芬芳。\n"NOR,me);
  if (query("target")==me && score>0) {
    me->add("daoxing",score);
  qn=score*(20+random(10))/100;
  //as followed added by vikee, when the potential is higher than 1000,do not added.
  if (me->query("potential")-me->query("learned_points")<1000) 
  me->add("potential",qn);
  
  tell_object(me,HIC"你得到了"+chinese_daoxing(score)+"道行，"+qn+"点潜能。\n"NOR);
//   message("system",HIG"【蓬莱仙岛】百花仙子(Baihua xianzi)："+me->query("name")+"与花仙子切磋武艺，得到"+chinese_daoxing(score)+"道行和"+chinese_number(qn)+"点潜能!\n"NOR,users());
MONITOR_D->report_system_object_msg( me,HIG"与花仙子切磋武艺，得到"+chinese_daoxing(score)+"道行和"+chinese_number(qn)+"点潜能!\n"NOR);
  log_file("baihuagu",me->query("id")+" got "+score+" daoxing "+qn+" pots on "+ctime(time())+".\n");
  }
  destruct(this_object());
  return 1;
}
string chinese_daoxing(int gain) {
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"年";
             if(day) str=str+chinese_number(day)+"天";
             if(hour) str=str+chinese_number(hour)+"时辰";
             return str;
}
