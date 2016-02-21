#include <ansi.h>

inherit ITEM;

void init();

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
	me->set("asdfghj", 0);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }

}

void create()
{
        set_name(YEL "佛宝舍利子" NOR, ({ "tooth" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗淡黄色的珠子，象有种神奇的力量孕育其中。\n");
                set("material", "silver");
                set("unit", "颗");
		set("no_sell", 1);
		set("no_drop", 1);
		set("asdfghj", 1);
        }
        setup();
	set("is_monitored", 1);
}

