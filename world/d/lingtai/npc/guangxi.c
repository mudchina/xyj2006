// guang.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int borrow_me(object ob);
int borr_me(object ob);
void create()
{
        set_name("广羲子", ({"guang xizi", "guang"}));
        set("title", "经阁总管");
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个看起来慈眉善目的道士，正拿着一本经书读着．\n");
	set("class", "toaist");
        set("combat_exp", 180000);
	set("daoxing", 250000);

        set("attitude", "friendly");
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 40);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 30);
	set("max_kee", 800);
	set("max_sen", 800);

        set("eff_dx", 60000);
        set("nkgain", 250);

	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("puti-zhi", 80);
	set_skill("jindouyun", 80);
	set_skill("unarmed", 80);
	set_skill("jindouyun", 80);
	set_skill("literate", 100);
	map_skill("dodge", "jindouyun");
	map_skill("unarmed", "puti-zhi");
        set("per", 30);
	set("str", 25);
        create_family("方寸山三星洞", 2, "弟子");

	set("inquiry", ([
                "book": "这里大多是我们道教经典，也有些平常书籍。",
		"千字文": (: borrow_me :),
		"道德经": (: borr_me :),
        ]) );
	set("chat_msg", ({
		"广羲子笑道：我这人最爱吃松果了！\n",
}));
	set("chat_chance", 5);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
	carry_object("/d/lingtai/obj/daoguan")->wear();
}

void init()
{
       object me,ob;
    me=this_player();
	ob=this_object();

        ::init();
        
		if (me->query_temp("fangcun/qiansi_gongxi")==1) 
		{
                remove_call_out("greeting");
                call_out("greeting", 1, me);
                call_out("destroy", 60, ob);
        }
        
}

int borr_me(object ob)
{       object m;
        ob = this_player();
        if ((string)this_player()->query("family/family_name")=="方寸山三星洞") {
                if ( this_player()->query("pending/book")) {
			message_vision("$N对$n说：上次借的还没还，怎么好再借给你呢？\n", this_object(), ob);
                	return 1;
		}
		if( (int)this_player()->query_skill("literate", 1) < 10 ) {
			message_vision("$N对$n说：你读书写字太差，借给你恐怕也看不懂啊。\n", this_object(), ob);
			return 1;
		}
		if ( (int)this_object()->query("daode") ) {
			message_vision("$N一拱手，说：刚借出去，明天再来吧！\n", this_object());
			return 1;
		}
                m=new("/d/obj/book/daode");
                m->move(ob);
                ob->set("pending/book", 1);
		this_object()->set("daode", 1);
		message_vision("$N从架上拿下本书来递给$n，说：记住要还唷！\n", this_object(), ob);
                return 1;
        }
	message_vision("$N说：我们这里的书不外借！\n", this_object());
	return 1;
}

int borrow_me(object ob)
{	object m;
	ob = this_player();
        if ((string)this_player()->query("family/family_name")=="方寸山三星洞") {
                if ( this_player()->query("pending/book")) {
                        message_vision("$N对$n说：上次借的还没还，怎么好再借给你呢？\n", this_object(), ob);
                        return 1;
                }
		if( (int)this_player()->query_skill("literate", 1) < 10 ) {
                        message_vision("$N对$n说：你读书写字太差，借给你恐怕也看不懂啊。\n", this_object(), ob);
                        return 1;
                }

                if ( (int)this_object()->query("qian") ) {
                        message_vision("$N一拱手，说：刚借出去，明天再来吧！\n", this_object());
                        return 1;
                }
                m=new("/d/obj/book/qian");
                m->move(ob);
                ob->set("pending/book", 1);
                this_object()->set("qian", 1);
                message_vision("$N从架上拿下本书来递给$n，说：记住要还唷！\n", this_object(), ob);
                return 1;
        }
        message_vision("$N说：我们这里的书不外借！\n", this_object());
        return 1;

}

int accept_object(object who,object ob)
{
       	if (ob->query("id")=="qian") {
 		if ( this_player()->query("pending/book") ){
		say("广羲子哈哈笑了几声，好借好还，再借不难！\n");
		who->set("pending/book", 0);
		this_object()->delete("qian");
       		call_out("destroy", 1, ob);
        	return 1;
		}
		else 
		say("广羲子笑道：多谢，多谢！\n");
	        call_out("destroy", 1, ob);
		return 1;
		}
	if (ob->query("id")=="daodejing") {
        	if ( this_player()->query("pending/book") ){
               	say("广羲子哈哈笑了几声，好借好还，再借不难！\n");
       		who->set("pending/book", 0); 
		this_object()->delete("daode");
        	call_out("destroy", 1, ob);
        	return 1;
		}
		else
		say("广羲子笑道：多谢，多谢！\n");
                call_out("destroy", 1, ob);
                return 1;
		}
	if (ob->query("id")=="songguo") {
		say("广羲子笑道：多谢，多谢！我最爱吃了！\n");
		who->set("pending/book", 0);
      		call_out("destroy", 1, ob);
               	return 1;
		}
	else return 0;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;

message_vision("\n"NOR,ob);
command ("jump");
command ("say " + "好,好,好,我灵台方寸山自孙师叔引来神龙后,千年来未曾再现,如今再见有如故友重逢啊！\n" );

}
