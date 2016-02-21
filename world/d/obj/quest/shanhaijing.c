//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("〖山海经〗", ({"shanhai jing", "jing"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 200);
        set("long",
"一本薄薄的小册子．唐国黎民人皆喜读的神仙鬼怪刊物．\n．．．．\n");
        set("material", "paper");
        set("owner_name", "青髯老人");
          set("owner_id", "lao ren");
        set("skill", ([
                        "name": "literate",
                        "sen_cost": 45,
                        "difficulty": 40,
                        "max_skill": 60,
]) );
        }
}
