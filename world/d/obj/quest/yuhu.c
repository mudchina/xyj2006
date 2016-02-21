//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("白玉奏笏",({"yuhu"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","这是大唐国大臣杜如晦的玉笏。\n");
                set("unit", "件");
          set("owner_name", "杜如晦");
          set("owner_id", "du ruhui");
        }
}
