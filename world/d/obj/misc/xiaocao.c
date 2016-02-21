// xiaocao.c...weiqi, 970926
//used to make ice_poison.

#include <ansi.h>
inherit ITEM;

void init();

void create()
{
	set_name(HIB "蓝色小草" NOR,({"xiao cao", "xiaocao", "cao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这种草叶尖圆润，色泽幽蓝，的确好看。 \n");
		set("unit", "朵");
		set("value", 300);
	}
	
	setup();
}

void init()
{
	add_action("do_chi", "eat");
	add_action("do_mix", "mix");
}


int do_chi(string arg)
{	
	if( !this_object()->id(arg) ) return 0;

	if(!arg) return notify_fail("你要吃什么？\n");

	return notify_fail("别毒死了...\n");
}

int do_mix(string arg)
{	
	object mixob, ice, me;
	int type;

	me=this_player();

	if(!arg || !(mixob=present(arg, me)) ) 
		return notify_fail("你要跟什么混合？\n");

	if( arg == "xue lian" ) type = 1;
	else if( arg == "qiong cao" ) type = 2;
	else return notify_fail("它们不象能混合的样子。\n");

	//now I have a xue lian...
	if( (int)me->query("force") < 100 )
		return notify_fail("你得有足够的内力才能把它们融合起来。\n");
	me->add("force", -100);

	message_vision("$N把"+mixob->query("name")+"和"+this_object()->query("name")+"放到一块，运气使劲一挤...\n", me);

	if( !(ice=present("bing kuai", me)) )
	{
		message_vision("结果挤得满手都是汁。\n", me);
		destruct(mixob);
		destruct(this_object());
		return 1;	
	}
	
	//if I have an ice...
	message_vision("然后将汁水滴到了冰块上，结果汁水很快被冰块吸了进去。\n", me);

	destruct(ice);
	if ( type == 1 ) ice=new("/d/obj/misc/blueice");
	else if( type == 2 ) ice=new("/d/obj/misc/redblueice");
	else ice=new("/d/obj/misc/ice");
        	ice->move(me);
	//now ice becomes blueice...
	//anyone who has >100 force can make blueice, however those who have
	//no ningxie-force > 20 will 中毒 if this blueice melts...hehe:)

  	destruct(mixob);
	destruct(this_object());

	return 1;
}

