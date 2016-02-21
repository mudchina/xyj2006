// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <armor.h>

inherit CLOTH;

void create()
{
          set_name("锦绒褊衫", ({"jinshan"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
     set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}


