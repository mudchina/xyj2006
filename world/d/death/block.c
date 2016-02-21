
// Room: /d/death/block.c
inherit ROOM;


void create ()
{
	set ("short", "鸿蒙之外"); 
	set ("long", @LONG

诗曰：
	混沌未分天地乱，茫茫渺渺无人见。
	自从盘古破鸿蒙，开辟从兹清浊辨。

盘古开天，万物纷华。可惜你形神俱灭，已是渺茫鸿蒙之外，无存天地
之间了。趁着一点灵光未灭，赶紧投胎(suicide/reborn)吧。

LONG);

	set("valid_startroom",1);

	setup();
}

void init()
{
	if( !wizardp(this_player()) )   
	{
		this_player()->set("startroom", "/d/death/block");
		add_action("block_cmd", "", 1);
	}   
}

int block_cmd(string args)
{
	string verb;
   
	verb = query_verb();
	if(verb == "quit" || verb == "look" || verb == "suicide") return 0;
   
	return 1;
}


