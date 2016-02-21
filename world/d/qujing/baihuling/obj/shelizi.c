// mon@xyj 10/18/98

inherit COMBINED_ITEM;

void create()
{
        set_name("舍利子", ({"sheli zi","sheli"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枚舍利子，常在有道高僧的骨殖中发现。\n");
                set("unit", "些");
                set("base_unit", "枚");
                set("base_weight", 50);
                set("value", 10000);
		set("no_sell",1);
        }
        set_amount(1);
        setup();
}

