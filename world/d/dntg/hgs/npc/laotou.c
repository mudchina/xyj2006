
inherit NPC;

void create()
{
       set_name("老头", ({"laotou"}));
       set("long", "一个慈眉善目的老大爷。\n");
       set("gender", "男性");
        set("combat_exp", 3000);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
        setup();
       add_money("silver", 1);
}
void init()
{
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
	object m,n,mm;
	message_vision("$N向老头问道：老大爷，开饭了吗？\n", this_player());

	if((int)this_player()->query("food") >= (int)this_player()->max_food_capacity()*90/100 )
	return notify_fail("老头笑道：等开饭时再来吧！\n");

	if((int)this_player()->query("water") >= (int)this_player()->max_water_capacity()*90/100 )
        return notify_fail("老头笑道：等开饭时再来吧！\n");
            
	if((present("bao", this_player())))
	return notify_fail("老头笑道：你还没吃完呢，怎么又要？\n");

        if((present("teapot", this_player())))
        return notify_fail("老头笑道：你还没吃完呢，怎么又要？\n");


	m=new("/d/obj/food/baozi");
        mm=new("/d/obj/food/baozi");

	n=new("/d/obj/food/chahu");
	
	m->set("value", 0);
	mm->set("value", 0);
	n->set("value", 0);

	m->move(this_player());
	mm->move(this_player());
	n->move(this_player());

	message_vision("老头对$N笑道：饿了吧，慢点吃。\n", this_player());
return 1;	
}
