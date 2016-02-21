inherit ITEM;

void create()
{
        set_name("小驴车", ({ "che" }));
	set_weight(500000);
        set_max_encumbrance(1000000);
	set("unit", "辆");
	set("value", 1);
        set("no_get", 1);
        set("long", "运货的小驴车，等着装货(load)。\n");
}

void init()
{
        add_action("do_load", "load");
	add_action("do_get", "get");
	add_action("do_put", "put");
}

int do_load(string arg)
{
        object ob;

        if( !arg ) return 0;

	if( (arg!="box") && (arg!="big box"))
		return
notify_fail("车把式对你说：我只装货行里的货柜！\n");

        ob = present(arg, this_player());
        if( !ob ) return notify_fail("你要装什么上小驴车？\n");

        message_vision("$N将$n装上了小驴车。\n", this_player(), ob);
        ob->move(this_object());
        this_player()->add_temp("wage_deserved", 1);

        if( sizeof(all_inventory()) >= 10 ) {
                write("车把式小鞭子一扬，敢着小驴车走了。\n");

                destruct(this_object());
        }

        return 1;
}
int put(string arg)
{	        
	if( sscanf(arg, "%s in che"))
		return notify_fail("什么？\n");
	return 1;
}

int get(string arg)
{	if( sscanf(arg, "%s from che"))
  		return notify_fail("什么？\n");
	return 1;
}

