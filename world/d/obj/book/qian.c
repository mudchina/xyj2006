// literate.c

inherit ITEM;

void create()
{
        set_name("〖千字文〗", ({"qian", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 100);
	set("long",
"一本薄薄的小册子．\n天地玄黄，宇宙洪荒．日月盈昃，星辰列张．\n．．．．\n");
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        //"exp_required": 1000,
                        "sen_cost": 25,
                        "difficulty": 30,
                        "max_skill": 110,
]) );
        }
}

