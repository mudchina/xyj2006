// sevenstar.c
// 1996/10/03 by none

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("二十八星瓢虫小姐", ({ "28star bug", "28star", "bug" }) );
	set("title", "电信局接待员");
	set("gender", "女性" );
	set("age", 18);
	set("long",
		"二十八星瓢虫小姐，俗称花大姐，喜欢在害虫们中间穿针引线。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
		"电信局" : "是啊... 这里就是电信局，你要寄信吗？",
		"寄信" : (: send_mail :),
		"收信" : (: receive_mail :),
		"mail" : "您讲的是外国话吧？我听不懂耶~~~~~~~~",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
	carry_object("/d/ourhome/obj/pink_cloth")->wear();
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到电信局来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到电信局来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
