#include <ansi.h>
inherit F_CLEAN_UP;

string *msgs = ({
  "你眼露惭色，不好意思地说：“其实我不该骂人的！”",
  "你突然觉得浑身发抖：怎么这里这么多鬼？！",
  "你想起自己的骂人言行，不由惭愧得汗流浃背。",
  "天空中一个声音说道：“这就是骂人的下场!”",
});

int update_condition(object me, int duration)
{       
if(duration>1) 
{
me->apply_condition("maren", duration-1);  
   if(environment(me)->query("short")!=HIR"拔舌地狱"NOR)
         {
                message_vision(HIR"突然，地下冒出些小鬼把$N团团围住！\n"NOR,me);
                message_vision(HIW"$N被小鬼倒拖着拉回拔舌地狱了！\n"NOR,me);
                me->move("/d/city/prison");
         }
        else 
        {
            tell_object(me,HIR+msgs[random(sizeof(msgs))]+"\n"+NOR);
        }
}
else    {
              me->move("/d/city/kezhan");
	      me->save();
             message_vision(HIW"$N刑满释放！$N灰溜溜地从拔舌地狱爬了出来。\n"NOR,me);
             return 0;
        }
    return 1;
}
