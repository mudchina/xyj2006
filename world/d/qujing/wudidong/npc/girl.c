// girl.c
inherit NPC;
void create()
{
	set_name("女孩", ({ "girl", "nu hai", "hai", "nu"}));
	set("gender", "女性" );
	set("age", 8+random(8));
	set("long",
		"女孩在家做了饭，喂了鸡，也就没什么事了。也跑到学堂来看看新鲜。\n");
	set("chat_chance", 2);
	set("chat_msg", ({
		"女孩对张秀才哭道：先生，我哥哥打我！\n",
		"女孩趁先生不注意，掏出一把小刀来，精心地刻一柄木梳子。\n",
		"女孩跟着哥哥起哄道：先生先，屁股尖，要吃豆腐自个儿煎！\n",
        }));
         set("combat_exp", 50+random(50));
        set("attitude", "friendly");
        set_skill("dodge", random(5));
        set_skill("unarmed", random(5));
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 70+random(100));
}