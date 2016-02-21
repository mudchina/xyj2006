inherit NPC;

void create()
{
        set_name("铁算盘", ({"tie suanpan", "tie", "zhanggui"}));
        set("title", "钱庄掌柜");
        set("gender", "男性");
        set("age", 54);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 10);
        set("chat_msg", ({
        "铁算盘嘿嘿嘿地笑了几声：我这把算盘几十年来可从来没错过。\n",

"铁算盘骄傲的说道：提起本钱庄相老板，可以说是无人不晓。连当今皇上都跟他很熟。\n"
        }));

        set_skill("unarmed", 60);
	set_skill("parry", 60);
        set_skill("dodge", 60);

        setup();
        carry_object(__DIR__"obj/choupao")->wear();
        add_money("gold", 1);
}

