//Cracked by Roath

inherit ITEM;

void create()
{
        set_name("蚯蚓", ({"qiu yin"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一只用来钓鱼的蚯蚓，蜷缩成一团，已经没有什么生命力了。\n");
        set("unit", "条");
        set("value", 0);
	set("no_sell", 1);
        }
        setup();
}


