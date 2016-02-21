#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("霓虹羽衣", ({"nihong yuyi", "yuyi", "skirt"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
            set("long",
"一件采集百禽羽毛一片片的穿成的衣裳，黑的是鹰毛，白的是雁翎，\n
衣长齐膝，不知用了几千几万根鸟羽。每根羽毛的根部都穿了一个细\n
孔，是用头发上的金钗刺出，孔中穿了淡黄的丝线。\n");
                set("value", 3000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
		set("armor_prop/dodge", 20);
                set("armor_prop/personality", 3);
                set("female_only", 1);
             }
        setup();
}

