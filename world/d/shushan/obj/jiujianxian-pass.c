#include <ansi.h> 
inherit F_UNIQUE;

inherit ITEM;
//inherit F_LIQUID;

void create()
{
        set_name(MAG"紫葫芦"NOR, ({"jiujianxian xinwu","xinwu","hulu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "酒剑仙随身带着装酒的葫芦。\n");
                set("unit", "个");
                set("value", 10);
                set("replace_file", "/d/ourhome/obj/hulu");
        }


}
