//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("ÆßÐÇ²Ý", ({ "qixing cao", "cao"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Å");
        }
}

