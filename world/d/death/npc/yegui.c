//puti.c
inherit NPC;

void create()
{
       set_name("孤魂野鬼", ({"ye gui", "gui"}));
       set("gender", "男性");
       set("age", 60);
	set("long", "一个看起来相当可怜的老头．\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 10);
       set("combat_exp", 600+random(100));
	set_skill("unarmed", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
set("chat_chance", 10);
set("chat_msg", ({
(: random_move :)
}) );


setup();

//        carry_object("/d/diyu/obj/shoupi")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/diyu/obj/tielian")->wield();
}

int accept_fight(object me)
{
        command("say 我已沦落到这个地步了，就可怜可怜我吧！");
        return 0;
}

