#include <armor.h>
inherit EQUIP;

void create()
{
        set_name("亮银面具", ({ "silver mask" ,"mask"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 800);
                set("material", "silver");
                set("armor_type", "mask");
                set("armor_prop/id", ({"yesi"}) );
                set("armor_prop/name", ({"耶丝"}) );
                set("armor_prop/short", ({"耶丝(yesi)"}) );
                set("armor_prop/long", ({
                        "身份来历不明，法术通神，风流倜傥的耶丝。\n"
                }) );
        }
}
