#include <weapon.h>

inherit STAFF;

void create()
{
        set_name( "龙头拐杖", ({ "dragon staff", "zhang", "staff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根红色龙头拐杖，上下画了些祥云飞凤之类的花纹。
入手沉重，一看就知不是凡物。\n");
                set("value", 0);
                set("no_sell",1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_put", 1);
				set("replace_file", "/d/obj/weapon/staff/shugan");
                set("wield_msg", "$N拿出$n拄在手里，嘴里还咳嗽了几声！\n");
                set("unwield_msg","$N将手中的$n别到腰后。\n");
        	set("weapon_prop/intelligence", 5);
                set("material", "wood");
        }
        init_staff(30);
        set("is_monitored",1);
        setup();
}

