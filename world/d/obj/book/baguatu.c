// literate.c

inherit ITEM;

void create()
{
        set_name("¡¼·üôË°ËØÔÍ¼¡½", ({"bagua tu", "tu", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±¾");
		set("value", 0);
		set("no_sell", 1);
		set("no_put", 1);
		set("no_give", 1);
	set("long","Ò»ÕÅ»­ÓĞ·üôË°ËØÔµÄ½õÂÚ¡£\n");
        set("material", "paper");
        set("skill", ([
                        "name": "baguazhou",
                        "dx_required": 40000,
                        "sen_cost": 10,
                        "difficulty": 10,
                        "max_skill": 180,
]) );
        }
}

