// literate.c

inherit ITEM;

void create()
{
        set_name("〖基本耙法〗", ({"rake book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 100);
        set("material", "paper");
        set("skill", ([
                        "name": "rake",
                        "exp_required": 1000,
                        "sen_cost": 30,
                        "difficulty": 20,
                        "max_skill": 180,
]) );
        }
}