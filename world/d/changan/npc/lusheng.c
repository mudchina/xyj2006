inherit NPC;

void create() {
        set_name("卢生", ({"lu sheng","lu", "sheng"}));
   set("long","一个很会做梦的书生。\n");
        set("gender", "男性" );
        set("age", 25);
        set("combat_exp", 100);
        set("attitude", "peaceful");
        set_skill("unarmed", 5);
        set_skill("dodge", 5);
        set_skill("parry", 5);
        set_skill("literate", 5);
        set_skill("force", 5);   
        set_skill("sword", 3);
        set("per", 27);
        set("max_kee", 500);
        set("max_sen", 300);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/misc/pillow");
}
