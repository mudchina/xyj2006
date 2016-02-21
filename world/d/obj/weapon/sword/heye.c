//Cracked by Roath
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("荷叶", ({ "he ye", "heye", "sword" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("value", 700);
                set("material", "steel");
                set("long", "一片碧绿的荷叶。\n");
                set("wield_msg", "$N拈起一片$n。\n");
                set("unwield_msg", "$N把$n放在一边。\n");
        }
        init_sword(40);
        setup();
}

