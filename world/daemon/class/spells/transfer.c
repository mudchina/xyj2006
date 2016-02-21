// transfer.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
  int neiligain, manacost, diff;
  int eff, forcelev, spellslev, mymaxmana, mymaxforce;
  int myforce, mymana, temp;
  
  if(!target) target=me;    
  if( target != me ) return notify_fail("你只能以法力恢复自己的真气。\n");
  
  forcelev=me->query_skill("force");
  if (forcelev > 300) forcelev=300;
  spellslev=me->query_skill("spells");
  if (spellslev > 300) spellslev=300;
  if( spellslev < 20 ) return notify_fail("你的法术修为太低。\n");
  if( forcelev < 20 ) return notify_fail("你的内功修为太低。\n");
  mymana=me->query("mana");
  if( mymana< 50 ) return notify_fail("你的法力不够了。\n");
  
  mymaxforce=me->query("max_force");
  myforce=me->query("force");
  diff = mymaxforce - myforce;
  if( diff<1 ) return notify_fail("你现在真气充盈。\n");
  
  manacost = diff;
  if( manacost>mymana) manacost = mymana;
  
  me->add("mana", -manacost);
  mymaxmana=me->query("max_mana");
  neiligain = manacost*mymaxmana/(1+mymaxforce);
  if (neiligain>manacost) neiligain=manacost;
  //here, the more the max_force, the less the neili gain.
  eff=forcelev;
  if (eff>spellslev) eff=spellslev; // max eff is 300 right now
  eff=eff/3; // max eff is 100 now
  temp=100-eff; // temp ranges also from 0 to 100
  temp=temp*temp/100; // now still 0 to 100, but curved with the square.
  eff=(100-temp)*80/100; // rescale to max 80%
  neiligain=neiligain*eff/100;
  me->add("force", neiligain);
  if(wizardp(me) && me->query("env/combat")=="verbose")
    tell_object(me,GRN "用 "+manacost+" 法力，得到 "+neiligain+" 内力，有效率为 "+eff+"。\n"NOR);
  if(me->query("force")>mymaxforce)
    {
      me->set("force", mymaxforce);
      //to prevent possible bug, set neili always smaller than max neili.
    }
  
  message_vision("$N嘴里嘀咕了几句，觉得真气充盈多了。\n", me);
  
  
  return 1;
}



