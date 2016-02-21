#include <skill.h>
#include <ansi.h>

//inherit ITEM;
inherit COMBINED_ITEM;
void create()
{
        set_name("神霄雷法符", ({"thunder seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸，中央有个大大的“雷”字。\n");
         set("base_unit","张");
        set("unit", "张");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	set_amount(1);
	setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N手中的$n突发红光，符咒渐渐淡去不见了。\n",where,me);
        destruct(me);
}

void invocation(object who)
{
	int i,a,b,c;
	
	a=who->query("combat_exp");
	b=(int)who->query_skill("spells")*(int)who->query_skill("spells");
	c=(int)who->query("mana_factor")*(int)who->query("mana_factor")*(int)who->query("mana_factor");
	i=a+b+c;

	this_object()->set("ap",i);
	return;
}
int ji_ob(object victim)
{
	object seal=this_object();
	object me=this_player();
	object where=environment(me);

        int success_adj, damage_adj;
	success_adj = 75;
	damage_adj = 75;

	if(me->is_busy())
		return notify_fail("你正忙着呢，无法祭神霄雷法符。\n");
	if( !victim)
		return notify_fail("你想祭的人不在这里。\n");
	if( where->query("no_magic"))
		return notify_fail("这里不能祭神霄雷法符。\n");
	if( !me->is_fighting())
		return notify_fail("只有战斗中才能祭神霄雷法符。\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不能控制神霄雷法符。\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，很难驾驭神霄雷法符。\n");

        me->add("mana", -50);
	SPELL_D->attacking_cast(
		me, 
			//attacker 
		victim, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "\n$N大喊一声“着”，手一挥，祭出了一张神霄雷法符！\n神霄雷法符「呼」地一下飞到半空，只见风云突变，几声闷雷在$n耳边乍起。\n" NOR,
			//initial message
		HIR "\n$n被雷声震的眼冒金星，心神不定，差点跌倒在地！\n" NOR, 
			//success message
		HIC "\n谁知$n毫无反应。\n" NOR, 
			//fail message
		HIC "但是$n伸指一弹，雷声消隐，神霄雷法符反向$N贴去！\n" NOR, 
			//backfire initial message
		HIR "结果扑！地一声神霄雷法符在$n身上烧了起来！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

        me->start_busy(2+random(2));
	add_amount(-1);
	//destruct(seal);  
	return 1;
}

int ji (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+name+"？\n");

  victim=present(target,environment(me));
  seal->ji_ob(victim);
  return 1;
}

