
// Joy  06/26/98
// mm.c  Ｍ＆Ｍ＇ｓ

inherit ITEM;
inherit F_FOOD;


void create()
{
        set_name("Ｍ＆Ｍ＇ｓ", ({"mms", "chocolate"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一捧五颜六色的Ｍ＆Ｍ＇ｓ巧克力豆，●○●○●○●○～～ 只溶在口不熔在手。\n");
                set("eat_msg", "$N拿起一颗Ｍ＆Ｍ＇ｓ巧克力豆放进嘴里，嘻嘻地笑着说：“我还要！” \n");
                set("unit", "捧");
                set("value", 50);
                set("food_remaining", 8);
                set("food_supply", 2);
        }
}

