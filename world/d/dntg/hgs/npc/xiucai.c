inherit NPC;

void create()
{
        set_name("蓝图郁", ({"lan tuyu","lan","xiansheng"}));
        set("gender", "男性");
        set("age", 55);
        set("title", "教书先生");
        set("str", 25);
        set("int", 30);
	set("long", "蓝图郁原是大唐一个秀才，因屡试不中，便漂流海外到傲来国。\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set_skill("literate", 40);
        set("force", 500); 
        set("max_force", 500);
        set("inquiry", ([
                "读书识字": "对了，你是来对地方了！\n",
        ]) );
        setup();
        carry_object("/d/obj/cloth/changpao")->wear();
}
int recognize_apprentice(object ob, object who)
{
        return 1;
}


