inherit NPC;
string teach_me(object me);
void create()
{

        set_name("东方博玉", ({ "dongfang boyu", "dongfang", "boyu"}) );
        set("gender", "男性" );
	set("per", 23);
        set("age", 42);
        set("long", "东方博玉是东方武馆的馆主，手上很有两下功夫。
城里的少年莫不以做他的徒弟为荣。\n");
        set("combat_exp", 80000);
	set("title", "武馆馆主");
	set("max_kee", 500);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
	set_skill("force", 70);
set("inquiry", ([
"name": "老夫东方博玉，是这里的当家。\n",
"here": "这便是傲来国最有名的武馆了，来学艺的人很多呢。\n",
"学艺": (: teach_me :),
]) );

        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/choupao")->wear();
}

string teach_me(object me)
{
	if((int)this_player()->query("combat_exp") < 10000 ) {
	message_vision("东方博玉对$N哈哈一笑，说道：打你一进来，我就知道你要学艺。\n", this_player());
	this_player()->set("newbie/learn", 1);
	return "以后就跟我儿子女儿学吧。\n";
	}
	command("look " + this_player()->query("id"));
	return "你太大了，还是另拜明师去吧！\n";
}
