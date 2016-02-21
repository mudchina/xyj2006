// literate.c

inherit ITEM;

void create()
{
        set_name("棒法纲要", ({"stick book", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long", "一幅一尺见方的染布，前后画着些基础棒法的图解．\n");
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        "exp_required": 1000,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 30,
]) );
        }
}

