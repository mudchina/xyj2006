// pao.c

inherit EQUIP;

void create()
{
        set_name("灰羽鹤氅", ({"leather coat", "coat"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件鹤羽织就的大氅。\n");
                set("value", 500);
		set("no_sell", 1);
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/spells", 15);
		set("armor_prop/dodge", 5);
             }
}
