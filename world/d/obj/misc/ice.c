// ice.c...weiqi, 970925

#include <ansi.h>

inherit ITEM;

int do_make(string);
int do_add(string);

void create()
{
	seteuid(getuid());
	set_name(HIW "冰块" NOR, ({ "bing kuai", "bingkuai", "bing", "ice" }) );
	set("long", "这是一片长长的，弯弯的，冷飕飕的冰块。\n");
	set("unit", "片" );
	set("value", 8);
	set("material", "ice");
}


void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
	object env;

        if(!this_object()) return;

	env=environment(this_object());

	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("ningxie-force", 1) < 20 )
		{
			message_vision("$N觉得身上凉凉的，湿湿的，原来是冰块化了。\n", env);
			destruct(this_object());
			return;
		}
	}

	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "xueshan" )
		{
			tell_object(env,"冰块终于化成了一滩水，流得到处都是。\n");
			destruct(this_object());
			return;
		}
	}

}

void init()
{                                             
        remove_call_out("do_melt");
        call_out("do_melt", 1);
	add_action("do_make", "make");
	add_action("do_make", "zuo");
	add_action("do_chi", "chi");
	add_action("do_chi", "eat");
	add_action("do_add", "add");
	add_action("do_add", "put");
}

int do_make(string arg)
{
	object ob, me;

	me = this_player();

	if( !arg || (arg != "blade" && arg != "dao" && arg != "sword" && arg != "jian" ) )
		return notify_fail("你要做什么？\n");
	if( arg == "sword" || arg =="jian" )
		return notify_fail("这片冰是弯的，做不了剑。\n");

	if( (int)me->query("force") < 200 || (int)me->query_skill("ningxie-force", 1) < 20 )
	{
		message_vision("$N拿起冰块捏来捏去，结果冰块很快就化掉了。\n", me);
		destruct(this_object());
		return 1;
	}	

	ob=new("/d/obj/weapon/blade/iceblade");
	ob->move(me);
	me->add("force", -100);
	message_vision("$N拿起冰块捏来捏去，居然做出了一把弯弯的冰刀！\n", me);
	destruct(this_object());

	return 1;
}

int do_chi(string arg)
{	
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");

	if(!arg) return notify_fail("你要吃什么？\n");

	message_vision( "$N拿起冰块使劲一咬，只听嘎哒！一声，牙甭了。\n" , this_player());
	if( (int)this_player()->query("kee") > 20 )
		this_player()->add("kee", -20);
	else this_player()->unconcious();

	return 1;
}

int do_add(string arg)
{//allow this poison to be added to a jiudai...
	string target, item;
	object destination;
	object me = this_player();

	if(!arg) return notify_fail("你要将什么东西加进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("用法：add <> in <>。\n");

	if( !this_object()->id(item) ) return notify_fail("你要加什么？\n");

	destination = present(target, me);
	if( !destination ) destination = present(target, environment(me));
	if( !destination) return notify_fail("这里没有这样东西。\n");

	if( !destination->query("liquid") ) return notify_fail("没必要吧？\n"); 
	
	//now, time to change it to poison...
	//destination->set("liquid/type", "ice_poison");
	message_vision( "$N偷偷摸摸地把一块"+ this_object()->query("name") +"加到"+ destination->query("name") +"中，傻乎乎地笑了几声。\n" , me);
	destruct(this_object());
	return 1;
}
