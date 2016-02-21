//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("定海珠", ({"dinghai zhu","zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此宝祭於空中，有五色毫光，纵然神仙，观之不明，应之不见。\n");
                set("unit", "件");
                set("lingtaibao","fake");
                set("owner_name","镇元大仙");
                set("owner_id","zhenyuan daxian");
        }
}

