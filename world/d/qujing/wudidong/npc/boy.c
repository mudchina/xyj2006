// boy.c
inherit NPC;
void create()
{
	set_name("男孩", ({ "boy", "nan hai", "hai", "nan"}));
	set("gender", "男性" );
	set("age", 10+random(8));
	set("long",
		"穷人的孩子早当家。这男孩虽然不大，但挑水磨磨的，倒也身强体壮。\n");
	set("chat_chance", 2);
	set("chat_msg", ({
		"男孩道：唉，读书真烦。不过还是比脊背朝天除草好玩些。\n",
		"男孩趁先生不注意，把手里的树枝朝着妹妹扔了过去。\n",
		"男孩拍手唱道：先生先，屁股尖，要吃豆腐自个儿煎！\n",
        }));
        set("combat_exp", 100+random(100));
        set("attitude", "friendly");
        set_skill("dodge", random(10));
        set_skill("unarmed", random(10));
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 70+random(100));
}