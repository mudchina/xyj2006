
inherit NPC;
inherit F_VENDOR;
void create()
{
       set_name("竹小弟", ({"bamboo kid", "kid"}));
       set("long", "他是竹老大捡来养大的，人人都叫他小弟。\n");
       set("gender", "男性");
        set("combat_exp", 2000);
	set("per", 18);
       set("age", 16);
	set("max_kee", 300);
	set("max_sen", 300);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 10);
	set_skill("dodge", 15);
        set("vendor_goods", ([
                "kuang": "/d/obj/misc/kuang",
        ]) );

        setup();
       add_money("coin", 20);
        carry_object("/d/obj/cloth/linen")->wear();
}
int accept_fight(object me)
{	me=this_player();
	if((int)this_player()->query("combat_exp") < 10000) {
	this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+500);
	}
        return 1;
}
void init()
{
        add_action("do_vendor_list", "list");
}

