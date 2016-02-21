// literate.c

inherit ITEM;

void create()
{
        set_name("〖拳经〗", ({"quan jing", "jing", "book"}));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 600);
	set("long", "一本薄薄的的小册子，画了些手法。
旁注小字：范青平惠存\n");
        set("material", "paper");
        set("skill", ([
                        "name": "unarmed",
                        "exp_required": 300,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 100,
]) );
        }
}

