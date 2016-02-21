//Cracked by Roath
// by happ@YSZZ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("大桃子", ({"tao", "tao zi"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个水灵新鲜的水蜜桃。\n");
                set("unit", "个");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}
