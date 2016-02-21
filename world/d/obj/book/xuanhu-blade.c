// literate.c

inherit ITEM;

void create()
{
        set_name("〖玄狐长恨刀法〗", ({"xuanhu book", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 0);
		set("no_sell", 1);
		set("no_put", 1);
		set("no_give", 1);
	set("long","一本玄狐长恨刀法的画册。\n");
        set("material", "paper");
        set("skill", ([
                        "name": "xuanhu-blade",
                        "exp_required": 100000,
                        "sen_cost": 40,
                        "difficulty": 40,
                        "max_skill": 200,
]) );
        }
}

