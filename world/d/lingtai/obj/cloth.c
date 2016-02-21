// pao.c

inherit EQUIP;

void create()
{
        set_name("Ì«¼«µÀÅÛ", ({"cloth", "pao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 500);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 2);
             }
}
