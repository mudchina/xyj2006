// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
inherit HEAD;

void create()
{
          set_name("黑绿丝", ({ "heilu si", "si" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
       set("long", "一顶黑丝和绿丝制成的丝带，用来束发。\n");
                set("value", 300);
                set("material", "cloth");
                set("armor_prop/armor", 1);
     set("armor_prop/personality", 1);
        }
        setup();
}

