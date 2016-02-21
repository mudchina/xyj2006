// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("金刚琢",({"jingang zhuo", "jinggang", "zhuo", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(5000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100000);
    set("material","jade");
    set("long","一只白森森的圈子。\n");
  }
  set("fake", 1);
  set("no_sell", "金刚琢乃法宝没人敢买也。");
  set("no_drop", "金刚琢乃法宝不可扔弃也。");
  set("no_give", "金刚琢乃法宝不可赠人也。");
  set("is_monitored",1);
  setup();
} 

int ji_ob (object victim)
{
  object zhuo = this_object ();
  object me = environment(zhuo);
  string zhuoname = zhuo->query("name");
  object ob;
  int damage, ap, dp, myspells, myexp, victimspells, victimexp;
  int mykar=me->query("kar"), victimkar;

  if (me->is_busy())
  {
    tell_object (me, "你无法忙中偷闲祭"+zhuoname+"。\n");
    return notify_fail("你正忙着呢。\n");
  }

  if (sizeof(all_inventory(zhuo))>0)
  {
    tell_object (me, zhuoname+"里有杂物，你无法再祭"+zhuoname+"。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  if (!victim)
  {
    tell_object (me, "你想祭的人不在这里。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"已经毫无抵抗能力了。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "只有战斗中才能祭"+zhuoname+"。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  if ((int)me->query("mana") < 300)
  {
    tell_object (me, "你的法力不足，祭不了"+zhuoname+"。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  ob = victim->query_temp("weapon"); 
  if(!ob)
  {
    tell_object (me, "对方没有使用武器盔甲。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  message_vision ("\n$N忽地抛起"+zhuoname+"，口中念念有词。\n",me,victim);
  if (zhuo->query("interactive_usage") > (me->query("kar")/2))
  {
    message_vision ("只听“咔嚓”一声，"+zhuoname+"在半空扭了一扭，跌了个粉碎。\n",me);
    destruct (zhuo);
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }
  message_vision ("刹那间"+zhuoname+"在空中一晃，卷起一股白雾。\n",me,victim);
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
     message_vision ("\n$n手中的"+ob->name()+"把持不定！\n",me,victim);
     message_vision ("说时迟那时快，"+ob->name()+"已被"+zhuoname+"收去！\n",me,victim);
     ob->unequip();
     if (ob->query_weight()>zhuo->query_max_encumbrance())
     {
        message_vision (ob->name()+"在"+zhuoname+"里化作一股烟散了！\n",me,victim);
        destruct(ob);
      }
      else ob->move(zhuo);
      me->add("mana", -250);
  }
  else
  {
    message_vision ("$n一纵身，绕开了空中的"+zhuoname+"。\n",me,victim);
    me->add("mana", -125);
  }
  victim->kill_ob(me);
  if (interactive(me))
    zhuo->add("interactive_usage",1);
  return 1;
}

int ji (string target)
{
  object zhuo = this_object ();
  object me = this_player();
  string zhuoname = zhuo->query("name");
  object victim;

  if (interactive (me))
  {
    tell_object (me, zhuoname+"什么动静也没有，看来是个假货。\n");
    return notify_fail("你祭"+zhuoname+"失败。\n");
  }

  if (!target)
    return notify_fail("你想对谁祭"+zhuoname+"？\n");

  victim=present(target,environment(me));
  zhuo->ji_ob(victim);
  return 1;
}

