
#include <armor.h>
#include <ansi.h>


inherit SURCOAT;


void create()
{
	set_name(HIC"白狐披风"NOR, ({"baihu pifeng","pifeng","cloth"}) );
	set("long", "据说此件披风是收集了几千只白狐狸腋下的小块皮毛缝制而成。\n");
	set_weight(1000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
		
                set("unit", "件");
                set("long","白狐披风。\n");
                set("no_put",1); 
                set("value",0);      
                set("no_sell",1);
//                set("no_give",1);
                set("no_zm",11);
          	set("material", "leather");
		set("armor_prop/armor", 100);
		set("armor_prop/dodge", 50);
             }
 		setup();
}

