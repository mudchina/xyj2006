//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "皮衣", ({ "pi yi", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long", "一件用兽皮制成的衣服。\n");
                set("unit", "件");
                set("value", 400);
                set("material", "leather");
                set("armor_prop/armor", 6);
        }
        setup();
}

