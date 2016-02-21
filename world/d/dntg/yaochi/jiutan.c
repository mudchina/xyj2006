
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("¾ÆÌ³", ({"jiu tan", "jiutan", "tan"}));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("value", 2000);
                set("max_liquid", 50);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "ÏÉ¾Æ",
                "remaining": 50,
                "drunk_apply": 5,
        ]));
}
