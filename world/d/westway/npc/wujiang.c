// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("边关守将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 35);
        set("str", 30);
        set("long", "他威风凛凛，杀气腾腾，虽然只是个守城门的小官，当年也是打过大仗的。\n");
        set("combat_exp", 200000+random(30000));
        set("attitude", "peaceful");
        set_skill("unarmed", 110);
        set_skill("force", 110);
        set_skill("spear", 110);
        set_skill("dodge", 110);
        set_skill("parry", 110);
	set("max_kee", 800);
	set("max_sen", 800);
        set("force", 600); 
        set("max_force", 600);
        set("force_factor", 30);

        setup();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
        message_vision("边关守将躬身道：末将公务在身，恕不奉陪！\n\n", me);
        return 0;
}
