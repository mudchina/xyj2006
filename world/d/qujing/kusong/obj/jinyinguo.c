//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("½ğÒø»¨", ({ "jinyin hua", "hua"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Å");
        }
}

