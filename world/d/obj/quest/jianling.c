//Cracked by Roath

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("凤尾箭翎", ({"fengwei jianling", "jianling"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这就是当初后裔射日时剩下的一个凤尾箭翎。\n");
                set("unit", "只");
//               set("owner_name","后羿");
//               set("owner_id","houyi");
	 	set("owner_name","孔雀公主");
		set("owner_id","kongque gongzhu");
        }
}
