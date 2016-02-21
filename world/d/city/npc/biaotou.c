inherit NPC;

void create()
{
        set_name("镖头", ({ "biao tou", "biao", "tou" }));
        set("gender", "男性");
	set("long", "镖局中的镖头，长的膀大腰圆，看起来很有力气的样子。\n");
        set("age", 29);
	set("str", 30);
	set("con", 30);
        set("combat_exp", 35000);
	set("max_kee", 500);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 5);
        set("shen_type", 1);
	set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	set_skill("force", 50);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();

}

