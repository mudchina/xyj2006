 
inherit NPC;
int give_horse();
void create()
{
	set_name("监丞", ({"jian cheng"})); 
        set("gender", "男性" );
	set("long", "御马监监丞。\n");
        set("age",40);
        set("str", 30);
	set("title", "御马监");
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 8500);
	set("max_kee", 1000);
	set("max_sen", 1000);
        set("inquiry", ([
                "horse": (: give_horse :),
		"天马":(: give_horse :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 
int give_horse()
{
	object me, who, horse;
	me=this_object();
	who=this_player();
	if( member_array("zengzhang tianwang", who->parse_command_id_list())==-1
		&& member_array("huguo tianwang", who->parse_command_id_list())==-1) {
		message_vision("$N很疑惑的看着$n说：我不认识你！\n", me,who);
		return 1;
	}
	if( me->query("no_horse")){
		message_vision("$N低头哈腰的对$n说：天王，小人实在是抽不出一匹啊。\n", me, who);
		return 1;
	}
	message_vision("$N低头哈腰的说：好说，好说。\n", me);
	seteuid(getuid());
	horse=new("/d/sky/npc/horse");
	horse->move(environment(me));
	tell_room(environment(me), "旁边的典簿到马圈里牵出匹天马来。\n");
	me->set("no_horse", 1);
	call_out("reg", 3600);
	return 1;
}
int reg()
{
	delete("no_horse");
	return 1;
}
