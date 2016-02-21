// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/wangshan.c

inherit F_VENDOR_SALE;

void create()
{
        reload("huangfeng_wangshan_huangfeng");
         set_name("王安", ({"wang an", "wang","lao ban"}));
        set("title", "店老板");
        set("gender", "男性");
        set("age", 25);
        set("long", "一条精壮的汉子，剑眉星目
当他目光射到你的脸上，你发现他眼中竟精光闪动，不可直视！\n");

        set("combat_exp", 70000);
	set_skill("kaishan-chui", 30);
        set_skill("hammer", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	set_skill("jindouyun", 50);
	map_skill("dodge", "jindouyun");
	map_skill("hammer", "kaishan-chui");
	map_skill("parry", "kaishan-chui");
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

        set("vendor_goods", ([
                "shield": "/d/obj/armor/niupi",
                "sword": "/d/obj/weapon/sword/changjian",
                "blade": "/d/obj/weapon/blade/blade",
                "spear": "/d/obj/weapon/spear/tieqiang",
                "staff": "/d/obj/weapon/staff/chanzhang",
                "hammer": "/d/obj/weapon/hammer/tongchui",
        ]) );

        setup();
        carry_object("/d/obj/cloth/hei")->wear();
        carry_object("/d/obj/weapon/hammer/tongchui")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
		call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
}

int accept_fight(object me)
{
        command("say 好吧，就比划两下子，但不能多耽，还有好多活没干呢！\n");
        return 1;
}

