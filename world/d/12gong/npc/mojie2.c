// by happ@YSZZ
 
inherit NPC;
 
void create()
{
        set_name("可洛诺斯", ({"kelowooz two"}));
        set("long", "传说中的作物之神，守护着摩羯座.\n");
        set("gender","男性");
        set("title", "【作物之神】");
        set("age",37);
        set("con",45);
        set("per",30);
        set("str",63);
        set("int",64);
        set("combat_exp",5000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "可洛诺斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 330);
        set_skill("force", 330);
        set_skill("parry", 330);
        set_skill("unarmed", 330);
        set_skill("sword", 330);
        set_skill("westsword",330);
        set_skill("boxing",330);
        set_skill("balei",330);
        set_skill("spells",330);
        set_skill("renma", 330);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_force", 6500);
        set("force", 1300);
        set("max_mana",6000);
        set("mana",12000);
        set("mana_factor",230);
        set("force_factor", 220);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);

        setup();
        carry_object(__DIR__"obj/mj_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        remove_call_out("check_me");
        call_out("check_me",12);
}
void check_me()
{
        command_function("say 我先走一步了!\n");
        destruct(this_object());
}
