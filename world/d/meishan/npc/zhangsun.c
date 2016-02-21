inherit NPC;
void create()
{
       set_name("张顺", ({"zhang shun", "zhang"}));
	set("long", "一位强壮的渔夫，愁眉苦脸，象是遇到了什么难事。\n");
       set("gender", "男性");
       set("age", 36);
       set("title", "渔夫");
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 10000);
        set_skill("unarmed", 35);
        set_skill("dodge", 30);
        set_skill("parry", 35);

        setup();
       add_money("coin", 3+random(5));
        carry_object("/obj/cloth")->wear();
}
int accept_object(object who,object ob)
{
        object m;

        int val;
        val = ob->value();
        if( !val )
                return notify_fail("张顺难过的说：我只要钱！\n");
        else if( val >= 5000 ) {
		command("jump");
		say("张顺说到：" + RANK_D->query_respect(who) + "就把阿花牵走吧！\n");
		say("张顺跑到后院牵出头老母猪来。\n");
		m=new("/d/meishan/npc/pigg");
		seteuid(getuid());
		m->move(environment(who));
	        call_out("destroy", 1, ob);
		call_out("leave", 1);
	        return 1;

        }
	say("张顺说到：多谢，多谢！\n");
	call_out("destroy", 1, ob);
        return 1;

}
void leave()
{
        message("vision",
               name() + "说：在下还要打鱼，不陪了。\n张顺走了出去。\n",environment(),
                this_object() );
        destruct(this_object());
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

