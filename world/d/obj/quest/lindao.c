//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("砍林刀", ({ "lindao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 60);
                set("jungle",1);
                set("material", "iron");
                set("owner_name", "砍柴道士");
          set("owner_id", "taoist");
                set("long", "这是一寻常的砍林刀，专门用来砍小树和灌木．\n");
                
        }
        
        setup();
}
