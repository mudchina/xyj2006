//qiaofu.c

inherit NPC;

void create()
{
        set_name("李定", ({"qiaofu","liding","li"}));
        set("gender", "男性" );
        set("age", 35);
        set("title","樵夫");
        set("long", "他虽是个樵夫，却也知书达理，能吟诗作词。\n跟附近一个叫张梢的渔夫乃是知交好友。\n");
        set("combat_exp", 500);
        set("attitude", "peaceful");
        set_skill("dodge", 10);
        set_skill("axe", 20);
        set_skill("literate", 30);
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/ourhome/obj/lumber_axe")->wield();
}


