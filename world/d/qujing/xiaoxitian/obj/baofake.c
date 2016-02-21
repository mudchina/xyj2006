// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("旧白布搭包",({"da bao", "bao", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100000);
    set("material","cloth");
    set("long","一只破旧的白布搭包。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("fake", 1);
  set("no_sell", "旧白布搭包乃法宝没人敢买也。\n");
  //set("no_drop", "旧白布搭包乃法宝不可扔弃也。\n");
  set("no_give", "旧白布搭包乃法宝不可赠人也。\n");
  set("is_monitored",1);
  setup();
} 

void init ()
{
  add_action ("do_out", "out");
}

int do_out ()
{
  object me = this_object ();
  object who = this_player();
  object where = environment (who);
  object room = environment (me);

  if (where != me)
    return 0;

  if (who->query_temp("no_move") ||
      who->is_busy())
  {
    tell_object (who, "想出去？可惜你现在动都动不了。\n");
    return 1;
  }
  tell_object (who, "你掀开旧白布搭包口，慢慢爬了出去。\n");
  if (room->is_character())
    room = environment (room);
  who->move(room);
  message_vision ("$N从旧白布搭包口里拱了出来。\n",who);
  return 1;
}

int ji_ob (object victim)
{
  object bao = this_object ();
  object me = environment(bao);
  string baoname = bao->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "你无法忙中偷闲祭"+baoname+"。\n");
    return notify_fail("你正忙着呢。\n");
  }

  if (sizeof(all_inventory(bao))>0)
  {
    tell_object (me, baoname+"里有杂物，你无法再祭"+baoname+"。\n");
    return notify_fail("你祭"+baoname+"失败。\n");
  }

  if (!victim)
  {
    tell_object (me, "你想祭的人不在这里。\n");
    return notify_fail("你祭"+baoname+"失败。\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"已经毫无抵抗能力，不必祭了。\n");
    return notify_fail("你祭"+baoname+"失败。\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "只有战斗中才能祭"+baoname+"。\n");
    return notify_fail("你祭"+baoname+"失败。\n");
  }

  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+baoname+"。\n");
    return notify_fail("你祭"+baoname+"失败。\n");
  }

  if( (int)me->query("sen") < 500)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
  }

  message_vision ("\n$N口中念着咒语，唰地扔起"+baoname+"。\n",me,victim);
  if (bao->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("只见"+baoname+"突然在半空中变成碎片如天女散花般飘落。\n",me);
    destruct (bao);
    return notify_fail("你祭"+baoname+"失败。\n");
  }
  message_vision (baoname+"腾起在半空中，只见一股白气狂风一般倒吸进去。\n",me,victim);
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

  if(random(ap+dp)>dp ||
     (!interactive(me) && 
      (!victim->query_temp("obstacle/xiaoxitian_entered") ||
       strsrch(victim->query("nickname")+" ","禁")==-1)))
  {
     message_vision ("$n顿感头重脚轻，身不由己地飘了起来！\n",me,victim);
     message_vision ("一瞬间，$n已被"+baoname+"装了进去！\n",me,victim);
     victim->move(bao);
     if (! interactive(me))
     {
       object room;
       object nao;

       victim->move("/d/qujing/xiaoxitian/chanfang");
       room = environment(victim);
       message_vision ("$N被拖了过来。\n",victim);
       nao = present ("jin nao",room);
       if (nao)
       {
         message_vision ("锵地一声，$N被关进了一只巨大的金铙。\n",victim,nao);
         victim->set_temp("obstacle/xiaoxitian_entered", 1);
         victim->move(nao);
       }
     }
     duration = (50-victim->query("kar"))*10;
     if (duration < 60)
       duration = 60;
     victim->set_temp("no_move",1);
     victim->start_busy(duration,1);
     victim->unconcious();
     call_out ("releasing",duration,victim);
     me->add("mana", -400);
  }
  else
  {
    message_vision ("$n一转身避开了"+baoname+"的致命一招！\n",me,victim);
    me->add("mana", -200);
  }
  if (victim)
    victim->kill_ob(me);
  if (interactive(me))
    bao->add("interactive_usage",1);
  return 1;
}

void releasing (object who)
{
  object me = this_object();
  object room = environment(me);

  if (room->is_character())
    room = environment(room);

  if (! who)
    return;

  who->set_temp("no_move",0);
  who->interrupt_me();
  if (! who ||
      interactive (who))
    return;
  if (environment(who) != me)
      return;
  who->move(room);
  message_vision ("$N从旧白布搭包口里拱了出来。\n",who);
}

int ji (string target)
{
  object bao = this_object ();
  object me = this_player();
  string baoname = bao->query("name");
  object victim;

  if (interactive (me))
  {
    tell_object (me, baoname+"什么动静也没有，看来是个假货。\n");
    return notify_fail("你祭"+baoname+"失败。\n");
  }

  if (!target)
    return notify_fail("你想对谁祭"+baoname+"？\n");

  victim=present(target,environment(me));
  bao->ji_ob(victim);
  return 1;
}

