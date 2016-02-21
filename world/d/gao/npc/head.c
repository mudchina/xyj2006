// head.c 赵老大

inherit NPC;

void create()
{
       set_name("夏鹏展", ({"xia pengzhan", "xia"}));
       set("title", "清风寨强盗头领");
       
set("long","夏鹏展原是长安城中一名捕头，因贼性难改，落草作了强盗．
使一路雁歌刀法，手中雁云刀阴狠无比．\n");
       set("gender", "男性");
       set("age", 37);
	set("str", 25);
       set("attitude", "aggressive");
       set_skill("blade",60);
        set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set_skill("yange-blade", 40);
	set_skill("yanxing-steps", 40);
	map_skill("dodge", "yanxing-steps");
	map_skill("blade", "yange-blade");
	map_skill("parry", "yange_blade");
       set("max_kee", 700);
	set("bellicosity", 5000);
       set("max_sen", 600);
       set("force", 350);
       set("max_force", 300);
       set("force_factor", 20);
       set("combat_exp", 60000);
setup();
carry_object("/d/obj/weapon/blade/yanblade")->wield();
carry_object("/d/obj/armor/yinjia")->wear();
carry_object("/d/obj/book/parry_book");
carry_object("/obj/dust");
add_money("silver", 50);
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
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "夏鹏展喝道：那里来的" + RANK_D->query_rude(ob) +
"，我看你不想活了！\n");
}
