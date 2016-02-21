#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("桃核", ({ "tao he", "taohe","he" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枚啃的精光的桃核。\n");
                set("unit", "枚");
        }
//         set("no_give","吃完了桃子给人桃核？当心人家打你。\n");
        set("no_get","要吃桃板店里去买，这个桃核不干净。\n");
        setup();
}

