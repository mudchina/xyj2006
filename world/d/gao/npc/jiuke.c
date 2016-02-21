// jiading.c

inherit NPC;

void create()
{
       set_name("酒客", ({"jiuke"}));

set("long","喝的满面通红，酒糟鼻子象一个西红柿．\n大概是喝的太多了，眼睛四处瞟着，嘴里嘟嘟囔囔不知说些什么．\n");
	set("bellicosity", 500);
       set("gender", "男性");
       set("age", 36);
       set("attitude", "heroism");
       set("shen_type", 1);
	set("combat_exp", 10000);
	set("force", 200);
	set("max_force", 200);
	set_skill("parry", 25);
	set_skill("dodge", 35);
	set("force_factor", 3);
	setup();
        add_money("silver", 1);
        carry_object("/obj/example/dagger")->wield();
        carry_object("/obj/cloth")->wear();
}
int accept_fight(object me)
{
        command("say 打架？老子当年打遍长安无敌手！");
        return 1;
}

