inherit NPC;

void create()
{
        set_name("苦力", ({"kuli"}));
        set("age", 22);
        set("gender", "男性");
        set("long","一个衣衫破旧的苦力人。\n");
        set("attitude", "heroism");

        set("combat_exp", 5000+random(1000));
        set("shen_type", 1);

        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("blade", 10);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


