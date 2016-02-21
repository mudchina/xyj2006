inherit NPC;
void consider();

void create()
{
        set_name("林冠雨", ({"lin guanyu", "lin"}));
        set("age", 42);
        set("gender", "男性");
        set("long",
"古董店的老板，笑眯眯的看着你。\n但笑容的后面好象又有一丝．．．\n");
	set("title", "古董店老板");
        set("attitude", "friendly");

        set("combat_exp", 20000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("sen", 300);
	set("max_sen", 300);
	set("force_factor", 10);
        set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("sword", 50);
	set_skill("fonxansword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 40);
	map_skill("unarmed", "changquan");
        map_skill("sword", "fonxansword");
        map_skill("parry", "fonxansword");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	setup();
	carry_object("/d/obj/weapon/sword/changjian");
        carry_object("/d/obj/cloth/choupao")->wear();
}
int accept_fight(object me)
{
        command("say 别，别，我这里东西都是宝贝，碰坏了可不得了！\n");
        return 0;
}

void consider()
{
        int i, flag = 0;
        object *enemy;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                        flag++;
		if(     !query_temp("weapon") ) {
                command("say 既然阁下逼人太甚，我也不再手下留情了！\n");
                        command("wield sword");

                        break;
		}
        }
}
