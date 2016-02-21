#include <weapon.h>

inherit FORK;

void create()
{
        set_name("月牙铲", ({ "moon fork", "fork" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把相当漂亮的月牙铲，铲锋如月牙般，看起来锋利的很。\n");
                set("value", 7000);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然后握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
        }
        init_fork(65);
        setup();
}

