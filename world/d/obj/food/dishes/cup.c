inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("°×Óñ¾ÆÕµ", ({"jiu zhan","zhan", "cup"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¸öµ­°×ÓñµÄÐ¡¾ÆÕµ¡£\n");
                set("unit", "¸ö");
                set("value", 500);
                set("max_liquid", 10);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "Å®¶ùºì",
                "remaining": 10,
                "drunk_apply": 5,
        ]));
}

