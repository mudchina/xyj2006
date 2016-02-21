//yitianjian.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
//inherit F_UNIQUE;
void create()
{
    set_name(HIW"仙剑"NOR, ({ "xian jian", "sword","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
//                set("unique", 1);
        	set("no_drop",1);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
        
         set("material", "iron");
        	set("long", "上古十二神兵之一：仙剑");
        	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n");
//            set("is_monitored",1);
	}
        init_sword(100+random(100));
	setup();
}
