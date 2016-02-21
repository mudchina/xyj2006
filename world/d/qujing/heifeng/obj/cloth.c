//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("锦绒褊衫", ({"cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long",
"用翡翠色的毛皮制成，上面还镶了一道金边。．\n");
                set("material", "cloth");
                set("unit", "件");
                set("value", 400);
                set("armor_prop/armor", 85);

        }
        setup();
}

