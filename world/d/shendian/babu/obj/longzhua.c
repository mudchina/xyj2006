#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
  set_name(HIB"修罗"+HIR"之爪"NOR, ({ HIR"xiuluo zhua"NOR, "zhua" }) );
  init_dagger(25);
  set("unit", "根");
  set_weight(300);
 set("no_sell", 1);
 set("no_drop", 1);
 set("no_put",1);
   set("no_give",1);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 0);
    set("material", "bone");
  }
   set("wield_msg","$N拿起$n握在手里，感觉到阿修罗的力量。\n");
  setup();
}
int init()
{
        add_action("do_wield","wield");
        add_action("do_unwield", "unwield");
        unique::init();
        return 1;
}
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;
        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wield (string arg)
{
  object me = this_player();
  object zhua = this_object();
  string name = zhua->query("name");
  string msg;

if (arg = "zhua" ||  arg = "xiuluo zhua" )
  {
  msg = "$N装备上"+name+"，不由的心跳加速。\n"; 
  zhua->set("wield_msg",msg);
  // remove_call_out("longzhua");
 call_out("longzhua",5,me,zhua);
  }
  return 0;
}
int do_unwield (string arg)
{
  object me = this_player();
  object zhua = this_object();
  string name = zhua->query("name");
  string msg;

if (arg = "zhua" || arg = "long zhua")
{
  msg = "$N将"+name+"放了下来，心中顿时轻松许多……\n"; 
  zhua->set("unequip_msg",msg);
  remove_call_out("longzhua");
}
  return 0;
}

void longzhua(object who,object ob)
{
     object target;
        string msg;
        object thing,*inv;
        target = offensive_target(who);
     if( who->is_fighting() &&target) 
     {
  if( ! target || random(5)>1) return ;      
 if( ! present( target,environment(who)) ) return ;    
        inv=all_inventory(target);
        if(!sizeof(inv))        {
 message_vision(HIR"\n$N"+HIY"身上已经没有东西啦！\n"NOR,target);
    }
        else    {
                thing=inv[random(sizeof(inv))];
                thing->move(who);
message_vision(HIB"\n修罗"+HIR"之爪"+HIW"飞了出去，从"+HIR"$N"+HIW"身上搜到"+thing->query("unit")+HIY+" " +thing->query("name")+HIW" "+"！\n"NOR,target);
        }
call_out("longzhua",7,who,ob);
}
}
