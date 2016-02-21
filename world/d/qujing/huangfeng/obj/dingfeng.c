//Cracked by Roath
#include <ansi.h>
inherit ITEM;
void create()
{
		set_name(HIM"定风丹"NOR, ({"dingfeng dan", "dan"}) );
                set("long","如来赐予灵吉菩萨两件宝物之一，有定风之神效。\n");

		set_weight(100);
        	if( clonep() )
 	 set_default_object(__FILE__);
  	else {
	  set("unit", "颗");
  	set("material", "crystal");
  	set("value",1);
  	set("no_sell",1);
  	set("no_give",1);
  	set("no_drop",1);
	set("no_get",1);
 	}
 	setup();
}
