inherit NPC_SAVE;
 
 
void create()
{
        set_name("Ｔｅｓｔ", ({"test"}));
        set("long", "大诗人李白，清高飘逸，剑术通神。\n");
        set("gender","男性");
	set("title", "(隐身)");
	set("class", "scholar");
	set("hide", 1);
	set("env/invisibility", 1);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",100000);
        set("attitude","heroism");

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("literate", 120);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);

        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 40);
	       reload("test");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1,ob);
        }
}

void greeting(object ob)
{

        if( !ob || !visible(ob) || environment(ob) != environment() )return;
        if( (int)ob->query("balance") > 5000000 ) {
                this_object()->set("account/"+ob->query("id"), (int)ob->query("balance"));
                this_object()->save();
                return;
                }
        return;

}

