inherit NPC;

void create()
{
       set_name("祭赛国武士", ({"wu shi"}));
       set("gender", "男性");
       set("age", 30);
        set("long", "一个身高胸阔的武士，正走来走去巡视着。\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 18);
	set("str", 20);
       set("combat_exp", 60000);
        set_skill("unarmed", 55);
        set_skill("dodge", 55);
        set_skill("blade", 55);
        set_skill("parry", 55);
	set_skill("force", 55);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 10);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 30);
        set("mana", 30);
	setup();
	carry_object("/d/obj/armor/tongjia")->wear();
        carry_object("/d/qujing/baoxiang/obj/wandao")->wield();
}

