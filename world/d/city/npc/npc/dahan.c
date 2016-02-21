inherit NPC;

void create()
{
        set_name("陕北大汉", ({"dahan"}));
        set("age", 25);
        set("gender", "男性");
        set("long",
"一个体型魁悟的大汉，正在吃包子。\n");
        set("attitude", "peaceful");
	set("str", 30);
        set("combat_exp", 12000+random(3000));
        set("shen_type", 1);
        set("force", 200);
        set("force_factor", 3);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
int accept_fight(object me)
{
        command("say 打架？那您小心点，莫把老板的桌椅砸了！");
        return 1;
}


