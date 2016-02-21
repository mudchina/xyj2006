// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tongjia.c
#include <armor.h>

inherit ARMOR;

void create()
{
          set_name("乌金铠甲", ({"gold armor","jia","armor"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
         set("long", "一件金灿灿的乌金铠甲。\n");
                set("value", 5000);
                set("material", "steel");
                set("armor_prop/armor", 45);
     set("armor_prop/dodge", -15);
             }
         setup();
}

