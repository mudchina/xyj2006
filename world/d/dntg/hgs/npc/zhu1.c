
inherit NPC;
inherit F_VENDOR;
void create()
{
       set_name("竹老大", ({"bamboo man", "man"}));
       set("long", "竹老大从小编竹，靠竹器谋生。
附近的人都叫他竹老大，把他的真名倒忘了。\n");
       set("gender", "男性");
        set("combat_exp", 5000);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
	set("max_kee", 400);
	set("max_sen", 400);
       set("shen_type", 1);
       set_skill("unarmed", 15);
	set_skill("dodge", 15);
        set("vendor_goods", ([
                "kuang": "/d/obj/misc/kuang",
        ]) );

        setup();
       add_money("silver", 1);
        carry_object("/d/obj/cloth/linen")->wear();
}
int accept_fight(object me)
{	me=this_player();
	if((int)this_player()->query("combat_exp") < 15000) {
	this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+500);
	}
        return 1;
}

void init()
{
        add_action("do_vendor_list", "list");
}

