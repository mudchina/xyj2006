// worker.c

inherit NPC;

void create()
{
        set_name("晨月", ({"chen yue"}));
        set("gender", "男性" );
        set("age", 13);
	set("title", "山门迎客");
        set("long", "一个小道士，每天负责在山门迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
	&& !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "晨月说道：这位" + RANK_D->query_respect(ob) +
"，欢迎到我们斜月三星洞来！\n");
}

