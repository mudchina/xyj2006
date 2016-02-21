#include <ansi.h>

inherit ITEM;

void init()
{
    set("no_get", "你拿不起来这样东西。试试挖挖(dig)。\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+
	    "的价值？还是自己留着吧。\n");

    add_action("do_dig", "dig");
    add_action("do_eat", "eat");
}

void create()
{
  set_name(RED "琼草嫩芽" NOR, ({"qiong cao","cao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗紫红色的小草。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  
  // the following line is added by snowcat
  set("is_monitored",1);
  setup();
}
int do_dig(string arg)
{
	object baihe, who, me, where;
	who=this_player();
	me=this_object();
	where=environment(me);

	if( me->query("can_eat"))
		return notify_fail("什么？\n");

	if( !arg || (arg!="qiong cao" && arg!="cao"))
		return notify_fail("你要挖什么？\n");

	if(who->is_fighting() && who->is_busy())
		return notify_fail("你很忙，没时间挖草。\n");

	if( baihe=present("bai he")){
		message_vision("白鹤长鸣一声，对$N发起了攻击。\n", who);
		baihe->kill_ob(who);
		who->fight_ob(baihe);
		return 1;
	}

		message_vision("$N轻轻将$n挖了起来。\n", who, me);
		me->set("can_eat", 1);
		remove_call_out("grow_a");
		remove_call_out("grow_b");
                remove_call_out("grow_c");
                remove_call_out("grow_d");
                remove_call_out("grow_e");
                remove_call_out("grow_f");
                remove_call_out("grow_g");
		where->delete("grow_grass");

	if( !baihe && me->query("eatable")){
		seteuid(getuid());
		baihe=new("/d/penglai/npc/baihe");
		baihe->move(where);
	tell_room(environment(who), "忽听一声鹤鸣，半空中冲下一只白鹤来。\n");
	baihe->kill_ob(who);
	who->fight_ob(baihe);
	}

		if(!me->move(who)) { // mon
		    destruct(me);
		}
	return 1;
}

int do_eat(string arg)
{
	object me=this_object();
	object who=this_player();
	int force_add, mana_add, howold;
	
  	if (!id(arg))
    		return notify_fail("你要吃什么？\n");
	if( !me->query("can_eat"))
		return notify_fail("你要吃什么？\n");


	howold = (int)who->query("mud_age") + (int)who->query("age_modify");

	who->set("food", (int)who->max_food_capacity());
  	who->set("water", (int)who->max_water_capacity());

	if( !me->query("eatable")){
		message_vision("$N狼吞虎咽般地将一颗$n吃了下去。\n", who, me);
		destruct(me);
		return 1;
	}

	force_add=5;
	mana_add=5;
	
	message_vision("$N将一颗$n轻轻嚼着咽下了肚，脸上泛起阵红晕。\n", who, me);
	tell_object(who, "你觉得一阵热气直通七窍，浑身上下好象有使不完的力气。\n");

  who->set("eff_sen", (int)who->query("max_sen"));
  who->set("sen", (int)who->query("max_sen"));
  who->set("eff_gin", (int)who->query("max_gin"));
  who->set("gin", (int)who->query("max_gin"));
  who->set("eff_kee", (int)who->query("max_kee"));
  who->set("kee", (int)who->query("max_kee"));
	
	    	who->add_maximum_force(force_add);
                who->add_maximum_mana(mana_add);

  	if( howold > 1382400 ) {
    		who->add("age_modify", -3600);
    		who->add("age_modify_time", 3);
  	}
  	destruct(me);
  	return 1;
}



void invocation()
{
	object me=this_object();
	int i=200+random(200);
	call_out("grow_a", i, me);
}

int grow_a(object me)
{
	int i=400+random(400);
	tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
	set_name(RED "一叶琼草" NOR, ({"qiong cao","cao"}));
	call_out("grow_b", i, me);
	return 1;
}

int grow_b(object me)
{
        int i=600+random(600);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "二叶琼草" NOR, ({"qiong cao","cao"}));
        call_out("grow_c", i, me);
        return 1;
}

int grow_c(object me)
{
        int i=800+random(800);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "三叶琼草" NOR, ({"qiong cao","cao"}));
        call_out("grow_d", i, me);  
        return 1;
}

int grow_d(object me)
{
        int i=1000+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "四叶琼草" NOR, ({"qiong cao","cao"}));
        call_out("grow_e", i, me);  
        return 1;
}

int grow_e(object me)
{
        int i=1200+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "五叶琼草" NOR, ({"qiong cao","cao"}));
        call_out("grow_f", i, me);  
        return 1;
}

int grow_f(object me)
{
        int i=1500+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
        set_name(RED "六叶琼草" NOR, ({"qiong cao","cao"}));
        call_out("grow_g", i, me);  
        return 1;
}

int grow_g(object me)
{
        int i=2000+random(1000);
        tell_room(environment(me), me->name()+"慢慢地长出了一个小叶。\n", ({me, me}));
	tell_room(environment(me), me->name()+"周围渐渐笼起一股红光。\n", ({me, me}));
        set_name(RED "七叶琼芝草" NOR, ({"qiong cao","cao"}));
	set("eatable",1);
        return 1;
}

