inherit NPC;

void create()
{
       set_name("贝嫂", ({"beisao"}));

set("long","一位中年妇女，是龙女的贴身仆人．\n");
       set("gender", "女性");
       set("age", 36);
	set("per", 20);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set_skill("unarmed", 60);
	set_skill("dodge", 80);
	set_skill("parry", 60);
        set("combat_exp", 36000);
        setup();
        add_money("silver", 1);

}

