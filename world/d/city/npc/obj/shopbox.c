// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// this object is put in hockshop to hold items.
// by mon. 2/28/98

#include <ansi.h>

inherit ITEM;

void create()
{
     set_name("聚宝盒",({"treasure box", "box"}));     
     set("short", "聚宝盒");
     set("env/invisibility",10);
     set_max_encumbrance(5000000000);
     set_max_items(100000);
     set_weight(100);
     set("no_get",1);
     set("no_magic", 1);
     set("no_fight", 1);
     set("no_clean_up",1);
     seteuid(getuid());
     setup();

}

int clean_up()
{
    return 0;
}    
