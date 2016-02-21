#include <ansi.h> 

inherit ITEM;

void create()
{
        set_name(HIY"金旨"NOR, ({"paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
HIY"                        金   旨                        　　\n"
"\n"
"         特令泾河龙王于次日辰时布云，巳时发雷，午时下雨，未\n"
"     时雨足，共降雨水三尺三寸零四十八点．不得有误．        \n"
"\n"
"                                             　　　　　嵚此\n"NOR);
				set("material", "paper");
		}
  setup();
}
