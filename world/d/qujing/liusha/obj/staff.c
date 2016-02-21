//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>

inherit STAFF;
#include <ansi.h>

void create()
{
        set_name(HIY"降魔杖"NOR, ({"xiangmo zhang", "zhang", "staff"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 300);
                set("material", "steel");
                set("long", "这是卷帘大将特制的兵器．\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰后．\n");
        }
        init_staff(55);
        setup();
}

