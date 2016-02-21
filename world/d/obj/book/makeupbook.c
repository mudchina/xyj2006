//Cracked by Roath


#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;
void create() {
        set_name(HIM"檀香扇"NOR, ({"tanxiang shan","shan","book"}));
    set("long","一把香气扑鼻的檀香扇，扇面上密密麻麻写满了一笔娟秀的蝇头小楷。");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100000);
//              set("no_sell",1);
        set("material", "paper");
        set("skill", ([
                        "name": "makeup",
                        "sen_cost": 15,
                        "difficulty": 20,
                        "max_skill": 150,
]) );
        }
}
