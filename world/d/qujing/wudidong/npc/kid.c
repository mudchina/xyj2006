// kid.c
inherit NPC;
void create()
{
        set_name("小娃娃", ({ "kid", "wawa"}));
        if(random(10)<7)
	set("gender", "男性" );
        else
	set("gender", "女性" );
        set("age", 3+random(5));
        set("long", "一个可爱的小娃娃。爹娘都去干活了，自己在溪边捉鱼。\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15+random(35));
}