inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("香酥", ({ "xiangsu"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个香酥，好象已经不大新鲜了，但还能吃。\n");
                set("unit", "个");
                set("value", 10);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
        setup();
}


