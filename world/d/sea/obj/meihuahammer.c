#include <weapon.h>

inherit HAMMER;
int do_read(string arg);

void create()
{
        set_name("八瓣梅花锤", ({ "meihua hammer", "hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把分八瓣成梅花状的铜锤，上面刻了些符篆。\n");
                set("value", 5000);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(60);
        setup();
}

void init()
{
 object me = this_object();
  object where = environment();

  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
	me->set("transferred", 1);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }

        add_action("do_read", "read");
}

int do_read(string arg)
{	int gain;
	object me=this_player();
	object ob=this_object();
	
	if(! ob->query("OK_to_STUDY"))
		return notify_fail("你无法从这样东西上学到任何东西。\n");
	if( ob->query("transferred"))
		return notify_fail("你无法从这样东西上学到任何东西。\n");
    	if(environment(me)->query("no_fight") || 
       	environment(me)->query("no_magic") )
          return notify_fail("安全区内禁止练功。\n");

	if( (int)me->query_skill("hammer", 1) >= 60)
		return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了。\n");
	if( (int)me->query_skill("spells", 1) < 20)
		return notify_fail("可能是你法术不精，无法领会上面的符咒。\n");

	if( (int)me->query_skill("spells", 1) < (int)me->query_skill("hammer", 1) )
		return notify_fail("可能是你法术领会还不深，暂时还领悟不出更深一层的锤法。\n");

	if( (int)me->query("kee") < 30)
		return notify_fail("你太累了，歇歇再来吧。\n");
	if( (int)me->query("sen") < 30)
		return notify_fail("你太疲劳了，歇歇再来吧。\n");

	gain= (int)me->query_skill("spells", 1)/3 + 1 + random((int)me->query_int());

	me->improve_skill("hammer", gain);
	me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

	write("你认真揣摩着八瓣梅花锤上的盘龙符影，似乎对「基本锤法」又有所了解。\n");
	tell_room( environment(me), me->name() +"双眼盯着八瓣梅花锤，手里还不知在比划什么。\n", ({me}));
	return 1;
}

