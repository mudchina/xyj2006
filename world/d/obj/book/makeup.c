#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM "檀香扇" NOR , ({"tanxiang shan", "shan"}));
        set_weight(600);
        set("no_give","这么珍贵的宝贝，哪能随便给人？\n");
        set("no_drop","这么好的宝贝，扔了多可惜呀！\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把香气扑鼻的檀香扇，扇面上密密麻麻写满了一笔娟秀的蝇头小楷。\n");
        set("material", "paper");
        set("skill", ([
                        "name": "makeup",
                        "exp_required": 5000,
                        "sen_cost": 10,
                        "difficulty": 25,
                        "max_skill": 150,
]) );
        }
}
