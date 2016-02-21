// haiwan
// mon 6/18/98

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青瓷大海碗", ({"hai wan", "wan", "bowl"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个盛满白开水的青瓷大海碗。\n");
		set("unit", "个");
		set("max_liquid", 20);
		set("no_get","留给大家喝不好吗？：）\n");
		set("drink_msg", "$N端起$n咕嘟咕嘟地灌下几大口$l。\n");
	}

	set("liquid", ([
		"type": "water",
		"name": "白开水",
		"remaining": 20,
	]));
}

int do_drink(string arg)
{
    mapping table;

    if( !this_object()->id(arg) ) return 0;

    if(!environment(this_object())->in_table(this_player())) {
	write("这是留给拱猪的仙长们喝的：（\n");
	return 1;
    }
    
    table=environment(this_object())->query_TABLE();
    if(undefinedp(table["cond"]) ||
	    table["cond"]=="等人" ||
	    table["cond"]=="等发牌") {
	write("拱猪还没开始呢，先灌水？\n");
	return 1;
    }

    set("liquid/remaining",20);
    return ::do_drink(arg);
}
