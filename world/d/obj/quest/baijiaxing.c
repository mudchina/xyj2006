//Cracked by Roath
// literate.c

inherit ITEM;
#include <task.h>

void create()
{
        set_name("〖百家姓〗", ({"baijiaxing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 100);
        set("long",
"一本薄薄的小册子．\n赵钱孙李，周吴陈王．\n．．．．\n");
        set("material", "paper");
        set("owner_name", "匡文正");
          set("owner_id", "kuang wenzheng");
        set("skill", ([
                        "name": "literate",
                        "sen_cost": 25,
                        "difficulty": 30,
                        "max_skill": 40,
]) );
        }
}
