// jinchuang.c 金创药

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("跌打丸", ({"dieda wan", "wan", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "颗");
                set("unit", "些");
                set("long", "这是一颗治伤的跌打药。\n");
                set("value", 150);
				set("drug_type", "良药");
        }
    set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
//        if ((int)this_player()->query("eff_kee") == 
//            (int)this_player()->query("max_kee"))
//                return notify_fail("你现在不需要用跌打药。\n")
        else {
                this_player()->receive_curing("kee", 30);
                message_vision("$N吃下一颗跌打丸，气色看起来好多了。\n",this_player());
           if (query_amount()>1)
	    add_amount(-1);
	   else destruct(this_object());
                return 1;
        }
}

