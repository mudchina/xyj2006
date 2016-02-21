// by gslxz@mhsj 1/7/2001
inherit ITEM;
inherit F_SAVE;

void create(string banghui)
{
	if( banghui)	set("banghui",banghui);
	if(! restore())	{
		set_name("Œﬁ–ß¡Ó≈∆",({"lingpai"}));
		set("no_use",1);
	}
	else	{
		set_name(banghui+"¡Ó≈∆",({"lingpai"}));
		set("no_use",0);
	}
	set("unit","øÈ");
        seteuid(getuid());
}

string query_save_file() { return DATA_DIR + "guild/" + query("banghui"); }
// by gslxz@mhsj 1/7/2001

void init()
{
	add_action("add_bangzhu","add");
}

int add_bangzhu(string arg)
{
	mapping data;
	string id,name;
	if(! arg)	return notify_fail("add ID npcid NAME npcname\n");
	if(sscanf(arg,"ID %s NAME %s",id,name)==2)	{
		data=query("npc");
		if(! mapp(data))	data=([]);
		set("bangzhu_id",id);
		set("bangzhu",name);
		data[id]=name;
		set("npc",data);
		write("data add ok\n");
		return 1;
	}
	else	return notify_fail("add ID npcid NAME npcname\n");
}

