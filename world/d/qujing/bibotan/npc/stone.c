inherit ITEM;

void kick();

void create()
{
        set_name("顽石",({"stone"}));
        set_weight(500000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "一块丈余高的顽石。\n");
                set("unit", "块");
    }

        setup();
}

void init()
{
        add_action("do_kick", "kick");
}


int do_kick(string arg)
{
	object ob;
	
	if(arg=="stone") {
		message_vision("$N一脚踢到大石头上，痛的哇哇乱叫！\n\n", this_player());
		message("vision", "顽石动了动，竟站了起来！\n\n", environment());
		seteuid(getuid());
		if(ob=new("/d/qujing/bibotan/npc/shitoujing"))
		ob->move(environment(this_object()));
		message_vision("石头精瞪了$N一眼，说到：你怎么这么小的劲，还不够给我挠痒痒的呢！\n",this_player());
		call_out("destroy", 1, this_object());
		return 1;
	}
	return 1;
}
void destroy(object me)
{
        destruct(me);
        return;
}

