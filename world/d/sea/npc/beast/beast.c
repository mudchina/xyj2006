#include <ansi.h>

inherit NPC;

int reset_status();

void init()
{
	::init();
	add_action("do_train", "train");
}

int do_train(string arg)
{
	object me, where;
	me=this_player();
	where=environment(me);
/*
	if( where->query("no_fight") )
		return notify_fail("安全区内不能训兽！\n");
*/
	if( !arg )
		return notify_fail("你要驯服什么？\n");
	if( arg != (string)this_object()->query("id") )
		return notify_fail("你要驯服什么？\n");
	if( this_object()->query_temp("rider") )
		return notify_fail("这匹坐骑上已经有人了。\n");
	if( (string)this_object()->query("owner")==(string)me->query("id") )
		return notify_fail("这匹坐骑已经是你的了。\n");
	if( this_object()->is_fighting() )
		return notify_fail("这匹坐骑已经分身不暇了。\n");
	if( !living(this_object()) )
		return notify_fail("现在耍什么威风？\n");
	if( where->query("no_fight") ) {
		random_move();
		return 1;
	}


	message_vision(HIM"$N冲上前去和$n扭打成一团。\n"NOR, me, this_object());

       	this_object()->set_temp("owner",me->query("id"));
	reset_status();
	this_object()->kill_ob(me);
	me->fight_ob(this_object());

	return 1;
}

void unconcious()
{
        string owner;
        object owner_ob;
        owner = query_temp("owner");	
	if( owner ) {
	
	owner_ob= find_player(owner);
	
	if( objectp(owner_ob = find_player(owner)) ) {
	        if( (object)query_temp("last_damage_from") == owner_ob ) {
			set("owner", owner_ob->query("id"));
			delete_temp("owner");
			reset_status();
			this_object()->remove_all_killer();
			this_object()->set("attitude", "heroism");
			message_vision(HIY"\n$N低头缩尾，以示降服。\n"NOR, this_object());
			return;
        	}
	}
	}
//	message_vision(HIY"$N run away!\n"NOR, this_object());
	die();
//	::unconcious();
}


int reset_status()
{
	object me=this_object();
	me->set("eff_kee", (int)me->query("max_kee"));
	me->set("kee", (int)me->query("max_kee"));
	me->set("eff_sen", (int)me->query("max_sen"));
	me->set("sen", (int)me->query("max_sen"));

	return 1;
}
