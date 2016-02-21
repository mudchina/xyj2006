#include <ansi.h>

#include <dbase.h>
#include <armor.h>

inherit NECK;
#include <flowers.h>

int DEBUG=1;

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
  if (this_object()!=present(arg,me)) return 0;
   message_vision(HIC"$N吃下一朵"+query("name")+HIC"，只觉得香气扑鼻，齿颊芬芳。\n"NOR,me);
  if (query("target")==me && score>0) {
     if (me->query("family/family_name")!="月宫") score=random(score);
    me->add("daoxing",score);
  qn=score*(20+random(10))/100;
  me->add("potential",qn);
  tell_object(me,HIC"你得到了"+chinese_daoxing(score)+"道行，"+qn+"点潜能。\n"NOR);

  MONITOR_D->report_system_object_msg(me," got "+score+" daoxing "+qn+" pots from baihua-gu.\n" );
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

