//chunyang.c

inherit ITEM;

void create()
{
	set_name("【纯阳心得】", ({"chunyang xinde","xinde","book", "shu"}));
	set_weight(1000);
	if( clonep() ) 
		set_default_object(__FILE__);
	else 
	{
		set("unit", "本");
		set("long", "一本小册子。几个龙飞凤舞的大字【纯阳心得】下还有一行小字：吕洞宾著。\n");
		set("material", "paper");
		set("value", 1000);
		set("skill", ([
			"name": "taiyi",
			"dx_required": 1000,
			"sen_cost": 10,
			"difficulty": 10,
			"max_skill": 140,
		]) );
	}
}

