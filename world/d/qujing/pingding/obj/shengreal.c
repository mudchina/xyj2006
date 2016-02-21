// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
 
void create()
{
  set_name("幌金绳",({"huangjin sheng", "sheng", "fabao"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","根");
    set("value", 100000);
    set("material","cloth");
    set("long","一根可长可短的幌金绳。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("unique", 1);
  set("no_sell", "幌金绳乃法宝没人敢买也。\n");
  set("no_drop", "幌金绳乃法宝不可扔弃也。\n");
  set("no_give", "幌金绳乃法宝不可赠人也。\n");
  set("replace_file", "/d/qujing/pingding/obj/shengfake.c");
  set("is_monitored",1);
  setup();
} 

void init()
{ check_owner();
}

int ji_ob (object victim)
{
  object sheng = this_object ();
  object me = environment(sheng);
  string shengname = sheng->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "你无法忙中偷闲祭"+shengname+"。\n");
    return notify_fail("你正忙着呢。\n");
  }

  if (!victim)
  {
    tell_object (me, "你想祭的人不在这里。\n");
    return notify_fail("你祭"+shengname+"失败。\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"已经毫无抵抗能力，不必祭了。\n");
    return notify_fail("你祭"+shengname+"失败。\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "只有战斗中才能祭"+shengname+"。\n");
    return notify_fail("你祭"+shengname+"失败。\n");
  }

  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+shengname+"。\n");
    return notify_fail("你祭"+shengname+"失败。\n");
  }

  if ((int)me->query("sen") < 500)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭"+shengname+"失败。\n");
  }

  if (sheng->query_temp("being_used"))
  {
    object ob = sheng->query_temp("victim");

    if (ob &&
        environment(me) == environment(ob))
    {
      tell_object (me, shengname+"已经捆了出去。\n");
      return notify_fail("你祭"+shengname+"失败。\n");
    }
  }

  message_vision ("\n$N口中念着咒语，掏出"+shengname+"对$n抛将过去！\n",me,victim);
  if (sheng->query("interactive_usage") > (me->query("kar")/3))
  {
    message_vision ("只见"+shengname+"在天上松散成一股股麻絮，被风吹散了。\n",me);
    destruct (sheng);
    return notify_fail("你祭"+shengname+"失败。\n");
  }
  me->start_busy(60/mykar);
  victimkar=victim->query("kar");
  myspells=me->query_skill("spells")/10;
  myexp=me->query("combat_exp")/1000;
  victimspells=victim->query_skill("spells")/10;
  victimexp=victim->query("combat_exp")/1000;
  ap=(myexp+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
  ap=ap*mykar/1000;
  dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
  dp=dp*victimkar/1000;
  if (wizardp(me) && me->query("env/combat")=="verbose")
    tell_object(me, GRN "进攻："+ap+"，防守："+dp+"。\n" NOR);

  if(random(ap+dp)>dp)
  {
     message_vision ("\n突然之间$n一个措手不及，连忙闪身可惜已晚。\n",me,victim);
     message_vision ("$n被"+shengname+"整个地捆了起来，几乎动弹不得！\n",me,victim);
     duration = (50-victim->query("kar"))/2;
     if (duration < 10)
       duration = 10;
     victim->set_temp("no_move",1);
     victim->start_busy(duration,1);
     sheng->set_temp("being_used",1);
     sheng->set_temp("victim",victim);
     call_out ("releasing",duration,me,victim,sheng);
     me->add("mana", -400);
  }
  else
  {
    message_vision ("\n$n向后一闪，躲了过去。\n",me,victim);
    me->add("mana", -200);
  }
  victim->kill_ob(me);
  if (interactive(me))
    sheng->add("interactive_usage",1);
  return 1;
}

void releasing (object me, object who, object sheng)
{
  object victim = sheng->query_temp("victim");

  if (victim && who && me &&
      victim == who &&
      environment(me) == environment(who))
    message_vision ("\n$N一松手，将绳子收了回来。\n",me);
  if (who)
  {
    who->set_temp("victim",0);
    who->set_temp("no_move",0);
    who->interrupt_me();
  }
  if (sheng)
    sheng->set_temp("being_used",0);
}

int ji (string target)
{
  object sheng = this_object ();
  object me = this_player();
  string shengname = sheng->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+shengname+"？\n");

  victim=present(target,environment(me));
  sheng->ji_ob(victim);
  return 1;
}

