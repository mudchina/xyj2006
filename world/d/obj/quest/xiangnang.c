//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
                set_name(HIR "香囊" NOR, ({"xiang nang" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                        set("long", "百花仙子平日用的香囊。\n");
                      set("unit", "个");
                     set("owner_name","百花仙子");
                     set("owner_id","baihua xianzi");
        }
}
