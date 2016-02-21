// worker.c

inherit NPC;
void create()
{
        set_name("樵夫", ({ "qiao fu", "fu" }) );
        set("gender", "男性" );
        set("age", 33);
	set("per", 30);
        set("long", "一位面色黝黑，喜气洋洋的樵夫．\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set("env/wimpy", 60);
	set_skill("axe", 20);
  	set("chat_chance",15);
  	set("chat_msg",({
        "只听樵夫唱道：云际依依认旧林，断崖荒草路难寻。\n",
        "樵夫唱道：西山望见朝来雨，南涧归时渡处深。\n",
	"樵夫唱道：观棋柯烂，伐木丁丁，云边谷口徐行，卖薪沽酒，狂笑自陶情。\n",
	"樵夫低声唱道：相逢处，非仙即道，静坐讲黄庭。\n",
        (:random_move:)
    	}));

        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "樵夫叫道：杀人哪！杀人哪！\n",
                "樵夫叫道：有土匪哪！光天化日下打劫哪！\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("coin", 50);
set("inquiry", ([
"name": "大家都叫我阿牛．平常上山打柴，有时也做些木器．\n",
"here": "此乃灵台方寸山．听说山上有个老神仙．\n",
"老神仙": "老神仙称名须菩提祖师．那祖师出去的徒弟，个个都是英雄．\n",
]) );
        carry_object("/d/lingtai/obj/axe")->wield();
}
int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="shuzhi") {

message_vision("阿牛笑道：要做木棍是吧？\n阿牛拿铁斧在树枝上左削削，右砍砍，好一根齐眉棍！\n阿牛给$N一根齐眉棍．\n",
who);
	m=new("/d/ourhome/obj/qimeigun");
        m->move(who);
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

