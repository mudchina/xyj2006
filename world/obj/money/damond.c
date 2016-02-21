// gold.c

inherit MONEY;

void create()
{
          set_name("钻石", ({"damond", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                 set("money_id", "damond");
set("long", "晶莹剔透的大钻石！\n");
set("unit", "克拉");
                set("base_value", 5000000 );
                set("base_unit", "克拉");
		set("base_weight", 37);
	}
	set_amount(1);
}

