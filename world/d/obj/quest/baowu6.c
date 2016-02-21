//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;

void create()
{
        set_name("混元金斗", ({"hunyuan dou","dou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此斗开天长出来，内藏天地按叁才\n");
                set("unit", "件");
                set("lingtaibao","fake");
                 set("owner_name","痴梦仙姑");
                 set("owner_id","chi meng");
        }
}

