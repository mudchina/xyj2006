
inherit NPC;

void create()
{
       set_name("阿七婆", ({"aqi po", "po"}));
       set("long", "一个看起来六七十岁，满脸神神秘秘的老太婆。\n");
       set("gender", "女性");
        set("combat_exp", 5000);
	set("per", 18);
       set("age", 66);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
	set_skill("dodge", 20);
        setup();
       add_money("silver", 7);
        carry_object("/d/gao/obj/ao")->wear();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "阿七婆神秘地说道：这位" +
RANK_D->query_respect(ob)
                                + "，紫斗摇光，不祥之兆呐！\n");
                        break;
		case 1:
                        say( "阿七婆嘴里嘟嘟囔囔不知说了些什么！\n");
                        break;
		case 2:
                        say( "阿七婆抬头看了看你。\n");
                        break;
		case 3:
                        say( "阿七婆阴笑了几声。\n");
                        break;
                case 4:
                        say( "阿七婆自言自语道：天阴，要多喝鸡汤。\n");
                        break;


        }
}

int accept_object(object me,object ob)
{
        object m;
        if (ob->query("id")=="old hen") {
                command("hehe " + this_player()->query("id") );
                m=new("/d/obj/book/windwater");
                m->move(this_player());
                message_vision("阿七婆偷偷塞给$N一本书。\n", this_player());
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

