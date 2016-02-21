//Cracked by Roath
#include <weapon.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name( "绿如意", ({ "green ruyi", "ruyi", "dagger" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄墨绿色的如意，顺其纹理雕成波浪形状。\n");
                set("value", 0);
                set("no_sell",1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
				set("replace_file", "/d/obj/weapon/dagger/dagger");
                set("wield_msg", "$N拿出$n捧在手上。\n");
        	set("weapon_prop/karma", 5);
                set("material", "wood");
        }
        init_dagger(15);
        set("is_monitored",1);
        setup();
}
