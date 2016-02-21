// pa_book.c

inherit ITEM;

void create()
{
        set_name("〖格斗秘诀〗", ({"parry book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("long", "一个小册子，划了些小人比武的招式．\n");
        set("material", "paper");
        set("skill", ([
    			"name": "parry",
			"exp_required": 5000,
			"sen_cost": 20,
			"difficulty": 25,
			"max_skill": 100,
]) );
        }
}

