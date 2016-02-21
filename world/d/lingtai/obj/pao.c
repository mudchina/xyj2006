// pao.c

inherit EQUIP;

void create()
{
        set_name("ÔíÂÞÅÛ", ({"purple cloth", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 10000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", 8);
                set("armor_prop/spells", 10);
             }
}
