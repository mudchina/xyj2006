inherit ITEM;

void create()
{
        set_name("Ô¿³×", ({ "key", "yaoshi"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
        }
}

