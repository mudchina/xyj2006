// By Canoe 2001-06-21
inherit F_VENDOR_SALE;
string give_map();
void create()
{
       set_name("铁匠老陈", ({"tie jiang","lao chen","tiejiang laochen",}));
       set("shop_id",({"laochen","tiejiang"}));
       set("shop_title","老铁匠");
       set("gender", "男性");
       set("long",
"老陈虽然是铁匠,还是顺带卖点药材。\n");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("chat_chance", 40);
       set("chat_msg", ({
"老铁匠哈哈大笑，不知想到了什么．\n",
"老铁匠似乎想到了些什么,脸上露出诡异的笑容．\n",

}) );

        set("vendor_goods", ([
                "yaochu": "/d/liandan/obj/yaochu",
                "gourou": "/d/ourhome/obj/gourou",
                "jitui": "/d/ourhome/obj/jitui",
                "taogan": "/d/obj/drug/fake-tao",
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
        ]) );
        setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
        say( name()+"笑咪咪地说道：这位" +RANK_D->query_respect(ob) + "，进来照顾点生意吧?\n");
                        break;
        }
}
