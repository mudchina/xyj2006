// jftou.c 轿夫头
#include <ansi.h>

inherit NPC;

int do_kill(string);
int do_enter(string);
int do_say(string);
int do_look(string);

void create()
{
	set_name("轿夫头", ({ "jiaofu tou", "tou" }));
	set("long", "他是轿夫头，除了抬花轿外，他负责办理雇佣手续。\n"
		"他看起来精明强干，有点生意头脑的样子，力气也不小。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("str", 80);
	set("int", 10);
	set("max_kee", 600);
	set("combat_exp", 10000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set("inquiry", ([
		"name" : "小的是这帮人的头儿，生意上的事儿，小的一手负责，您有何吩咐？",
		"here" : "这儿向东去就是月老亭了，所有的婚姻都在那儿办理，所以这儿的生意好极了。",
		"婚礼" : "呵呵，小的就负责这个，瞧，花轿，轿夫，吹鼓手，一应俱全，包您满意。您要不要风光风光？",
		"价钱" : "花轿加轿夫，一百两银子。要是加吹鼓手，另加一百两。现钱交易，先付银子。",
       ]) );

	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
	add_action("do_enter", "enter");
	add_action("do_say", "say");
	add_action("do_look", "look");
}

int do_look(string arg)
{
	if ((arg=="jiaozi"
		|| arg=="huajiao"
		|| arg=="jiao")
		&& query("on_way")) {
		tell_object(this_player(),
"这是一顶漂亮的花轿，大红的缎子布包着，四角扎着大红花，四根杆子都用彩带绕着。\n"
"两个轿夫正抬着它走，里面显然坐着个新娘子。\n");
		return 1; }
	return 0;
}

int do_kill(string arg)
{
	if ((arg=="jiaofu tou"
		|| arg=="tou"
		|| arg==query("groom"))
		&& environment()!=find_object("/d/moon/yltw")) {
		write("你想坏人好事，太不道德了吧。\n");
		return 1; }
	return 0;
}

int do_enter(string arg)
{
	object me, jiao, tou;
	me=this_player();
	tou=present("jiaofu tou", environment(me));

	if ((arg=="jiaozi" || arg=="huajiao" || arg=="jiao")
		&& getuid(me)==query("bride")) {
		message_vision("新娘子$N羞羞答答地坐进了花轿里，轿夫马上把轿帘放了下来。\n",me);
		me->move("/d/moon/jiaoli");
		set_leader(find_player(query("groom")));
		command("say 一切就绪，新郎官您请前面带路，我们跟着，到了地方跟小的说一声就行了。");
		set_leader(find_player(query("groom")));
		jiao=present("jiaozi",environment(tou));
		jiao->move(tou);
		message_vision("$N和另一个轿夫一起，忽悠一下把轿子抬了起来。\n",tou);
		tell_object(me, "你感到轿子被人抬了起来，看来是上路了。\n");
		set("on_way",1);
		return 1; }
	return 0;
}

int do_say(string arg)
{
	object me, tou, jiao, worker1;
	me=this_player();

	if ((arg=="到了" || arg=="here") && getuid(me)==query("groom") && query("on_way")) {
		message_vision("$N告诉轿夫头到地方了。\n", me);
		message_vision("轿夫把轿子放了下来，撩起轿帘，新娘子站了出来。\n", me);
		find_player(query("bride"))->move(environment(me));
		me->delete_temp("marrying");
		me->delete_temp("bride");
		command("say 多谢您老照顾小的的生意，恭喜二位新人，祝二位白头偕老，小的告辞了。");
		message_vision("轿夫一行人抬着空轿子离开了。\n",me);
		if (present("jiaofu tou", find_object("/d/moon/yltw"))) {
			if (objectp(tou=present("jiaofu tou",environment(me))))
				destruct(tou);
			if (objectp(worker1=present("jiaofu",environment(me))))
				destruct(worker1);
			if (objectp(worker1=present("luogu shou",environment(me))))
				destruct(worker1);
			if (objectp(worker1=present("suona shou",environment(me))))
				destruct(worker1);
			return 1; }
		if (objectp(tou=present("jiaofu tou",environment(me)))) {
			tou->move("/d/moon/yltw");
			tou->set_leader(0);
			tou->delete("in_job");
			tou->delete("on_way");
			tou->delete("groom");
			tou->delete("bride");
			tou->delete_temp("no_return");
			if (objectp(jiao=present("jiaozi",tou)))
				jiao->move("/d/moon/yltw");
		}
		if (objectp(worker1=present("jiaofu",environment(me)))) {
			worker1->move("/d/moon/yltw");
			worker1->set_leader(0);
			worker1->delete_temp("no_return"); }
		if (objectp(worker1=present("luogu shou",environment(me)))) {
			worker1->move("/d/moon/yltw");
			worker1->set_leader(0);
			worker1->delete_temp("no_return"); }
		if (objectp(worker1=present("suona shou",environment(me)))) {
			worker1->move("/d/moon/yltw");
			worker1->set_leader(0);
			worker1->delete_temp("no_return"); }
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	object worker1, worker2, worker3;

	if (query("in_job")) {
		command("say 十分抱歉，我现在刚好有桩生意，请您待会儿再来好吗？");
		return 1; }

	if (!ob->query("money_id")) {
		command("say 哎哟，您跟小的开什么玩笑，这东西小的哪儿敢收啊。");
		return 1; }

	if (!who->query_temp("marrying")
		|| !present(who->query_temp("bride"), environment(who))) {
		command("say 哎呀，您老太客气了，没事儿就打赏，等您成亲的时候，小的一定尽心服务。");
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1; }

	if (ob->value()==10000)	{
		if (!objectp(worker1=present("jiaofu",environment()))) {
			command("say 哎哟，我这儿人手不齐，没法儿给您办了，太对不起了，您老多包含。");
			return 1; }

		command("say 好的好的，多谢您老的银子，花轿这就备好，请新娘子上轿。");
		set("in_job",1);
		set("bride",who->query_temp("bride"));
		set("groom",getuid(who));
		set_temp("no_return",1);
		worker1->set_leader(this_object());
		worker1->set_temp("no_return",1);
		message_vision("轿夫头把轿帘撩了起来，新娘可以进去了。\n",who);
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}

	if (ob->value()==20000) {
		if (!objectp(worker1=present("jiaofu",environment()))
			|| !objectp(worker2=present("luogu shou",environment()))
			|| !objectp(worker3=present("suona shou",environment()))) {
			command("say 哎哟，我这儿人手不齐，没法儿给您办了，太对不起了，您老多包含。");
			return 1; }

		command("say 好的好的，多谢您老的银子，花轿这就备好，请新娘子上轿。");
		command("say 您老放心，吹鼓手随队跟着吹打，保证您一路风光。");
		set("in_job",1);
		set("bride",who->query_temp("bride"));
		set("groom",getuid(who));
		set_temp("no_return",1);
		worker1->set_leader(this_object());
		worker1->set_temp("no_return",1);
		worker2->set_leader(worker1);
		worker2->set_temp("no_return",1);
		worker3->set_leader(worker1);
		worker3->set_temp("no_return",1);
		message_vision("轿夫头把轿帘撩了起来，新娘可以进去了。\n",who);
		message_vision("唢呐手大声地吹起了唢呐，锣鼓手用力地敲锣打鼓，好不热闹。\n",who);
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	}
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
