
inherit ITEM;

void create()
{
        set_name("竹筐", ({ "kuang" }) );
        set_weight(1000);
        set_max_encumbrance(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个编制精细的竹筐，用来装一些杂物。\n");
                set("value", 50);
        }
}

int is_container() { return 1; }

