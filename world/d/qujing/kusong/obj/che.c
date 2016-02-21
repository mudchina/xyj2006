//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("漆金小车", ({ "che"}) );
        set_weight(10000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一辆漆金红木小车。\n");
                set("unit", "辆");
        }
}

