// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/yumi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ÓñÃ×", ({"yu mi", "yumi"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ëë¿ÅÁ£±¥ÂúµÄÓñÃ×¡£\n");
                set("unit", "Ëë");
                set("value", 100);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
}

