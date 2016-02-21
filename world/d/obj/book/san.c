// literate.c

inherit ITEM;

void create()
{
        set_name("¡¼Èý×Ö¾­¡½", ({"book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±¾");
		set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 20,
]) );
        }
}

