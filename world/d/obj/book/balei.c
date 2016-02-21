
//芭蕾
inherit ITEM;
void create()
{
        set_name("〖芭蕾入门〗", ({"ba lei", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
       set("unit", "本");
       set("value", 100);
  set("long",
"一本薄薄的小册子．\n上面画满了跳舞的小人．\n．．．．\n");
        set("material", "paper");
        set("skill", ([
                        "name": "balei",
                        "sen_cost": 10,
                        "difficulty": 10,
                        "max_skill": 100,
]) );
        }
}

