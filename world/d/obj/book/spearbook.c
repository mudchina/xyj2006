// literate.c

inherit ITEM;

void create()
{
        set_name("〖枪法简介〗", ({"spear book", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 2000);
		set("no_sell", 1);
        set("long", "一本薄薄的小册子．画了些枪法的图解．\n");
        set("material", "paper");
        set("skill", ([
                        "name": "spear",
                        "exp_required": 10000,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 160,
]) );
        }
}


