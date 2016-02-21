// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
 
void create()
{
  set_name("羊脂玉净瓶",({"jing ping", "jing", "ping", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100000);
    set("material","cloth");
    set("long","一只几乎透明的羊脂玉净瓶。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("unique", 1);
  set("no_sell", "羊脂玉净瓶乃法宝没人敢买也。\n");
  //set("no_drop", "羊脂玉净瓶乃法宝不可扔弃也。\n");
set("no_put",1);
   set("no_give", "羊脂玉净瓶乃法宝不可赠人也。\n");
  set("replace_file", "/d/qujing/pingding/obj/pingfake.c");
  set("is_monitored",1);
  setup();
} 

void init ()
{
  check_owner();
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
    tell_object (who, "你竭力挣扎着想爬出去，却挪动不了身子。\n");
    return 1;
  }
  tell_object (who, "你贴在光滑的净瓶壁上，一点点向外爬去。\n");
  if (room->is_character())
    room = environment (room);
  who->move(room);
  message_vision ("$N从羊脂玉净瓶里伸出头，昏昏沉沉地爬了出来。\n",who);
  return 1;
}

int ji_ob (object victim)
{
  object ping = this_object ();
  object me = environment(ping);
  string pingname = ping->query("name");
  int damage, ap, dp, myspells, myexp, victimspells, victimexp, duration;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "你无法忙中偷闲祭"+pingname+"。\n");
    return notify_fail("你正忙着呢。\n");
  }

  if (sizeof(all_inventory(ping))>0)
  {
    tell_object (me, pingname+"里有杂物，你无法再祭"+pingname+"。\n");
    return notify_fail("你祭"+pingname+"失败。\n");
  }

  if (!victim)
  {
    tell_object (me, "你想祭的人不在这里。\n");
    return notify_fail("你祭"+pingname+"失败。\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"已经毫无抵抗能力，不必祭了。\n");
    return notify_fail("你祭"+pingname+"失败。\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "只有战斗中才能祭"+pingname+"。\n");
    return notify_fail("你祭"+pingname+"失败。\n");
  }

  if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+pingname+"。\n");
    return notify_fail("你祭"+pingname+"失败。\n");
  }

  if( (int)me->query("sen") < 500)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭"+pingname+"失败。\n");
  }

  message_vision ("\n$N口中念着咒语，掏出"+pingname+"底儿朝上，冷不丁地对$n一喊：“"+
                  victim->query("name")+"！”\n",me,victim);
  if (ping->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("只听“砰”地一声，"+pingname+"突然爆了个粉碎。\n",me);
    destruct (ping);
    return notify_fail("你祭"+pingname+"失败。\n");
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
     int ratio;

     message_vision ("\n$n顺口答道：“在！”\n",me,victim);
     message_vision ("倾刻之间$n被"+pingname+"叭地一声活活吸了进去！\n",me,victim);
     victim->move(ping);
     duration = (50-victim->query("kar"))*10;
     if (duration < 60)
       duration = 60;
     victim->set_temp("no_move",1);
     victim->start_busy(duration,1);
     victim->set_temp("fabao/gin",victim->query("gin"));
     victim->set_temp("fabao/kee",victim->query("kee"));
     victim->set_temp("fabao/sen",victim->query("sen"));
     victim->set_temp("fabao/eff_gin",victim->query("eff_gin"));
     victim->set_temp("fabao/eff_kee",victim->query("eff_kee"));
     victim->set_temp("fabao/eff_sen",victim->query("eff_sen"));
     victim->unconcious();
     ratio=75;
     if(victim) {//sometimes victim maybe lost after unconcious().
     victim->set("gin",victim->query_temp("fabao/gin")*ratio/100);
     victim->set("kee",victim->query_temp("fabao/kee")*ratio/100);
     victim->set("sen",victim->query_temp("fabao/sen")*ratio/100);
     call_out ("reviving",1,victim);
     call_out ("releasing",duration,victim);
     }
     me->add("mana", -400);
  }
  else
  {
    message_vision ("\n$n知道有诈，闭口不语，结果什么都没发生。\n",me,victim);
    me->add("mana", -200);
  }
  if (victim)
    victim->kill_ob(me);
  if (interactive(me))
    ping->add("interactive_usage",1);
  return 1;
}

void reviving (object who)
{
  object me = this_object();

  if(!who) return;
  if (! who->query_temp("block_msg/all"))
    return;

  if (environment(who) != me)
  {
    who->revive();
    who->start_busy(1);
    return;
  }
  call_out ("reviving",1,who);
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
  message_vision ("$N从羊脂玉净瓶里伸出头，昏昏沉沉地爬了出来。\n",who);
}

int ji (string target)
{
  object ping = this_object ();
  object me = this_player();
  string pingname = ping->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+pingname+"？\n");

  victim=present(target,environment(me));
  ping->ji_ob(victim);
  return 1;
}

