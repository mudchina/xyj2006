# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM"七"+HIR"彩"+HIC"水"+HIY"晶"+HIG"石"NOR, ({"jingshi", "shi", "shui jing"}));
	set_weight(1);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
	//	set("no_give",1);
		set("no_put",1);
		set("no_get",1);
		set("value",0);
		set("unit","颗");
		set("long",
"一颗七棱水晶，在阳光照射下散发着"+HIM"七"+HIR"彩"+HIC"光"+HIG"芒。\n"NOR);
	}
	set("is_monitored",1);
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
	object pearl;
        if( pearl=new("/d/npc/obj/jingshi"))
        	pearl->move(where);
	message_vision("$N手中的$n突发"HIM"七"HIC"彩"HIY"之"HIG"光，一道霞光过后便失去了颜色。\n"NOR,where,me);
	destruct(me);
}

