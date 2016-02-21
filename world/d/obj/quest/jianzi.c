//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ITEM;
void create()
{
    set_name( "鸡毛毽子", ({ "jian zi","jian"  }) );
    set_weight(5);
    if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","
一个用花花绿绿的鸡毛插成的毽子。
\n");
    set("unit", "个");
    
    set("long","
一个用花花绿绿的鸡毛插成的毽子。
\n");
    
    set("owner_name", "农家女");
    set("owner_id", "girl");
}

}
