//Cracked by Roath
inherit NPC;

string *first_name = ({ "降龙",
			"伏虎",
			"清静",
			"接引",
			"归真",
			"金刚",
			"精进",
			"功德",
			"旃檀",
			"光明",
			"贤善",
			"庄严",
			"智慧",
			"日月",
			"妙音",
			"须弥",
			"金身",
			"广力"
});

string *name_words = ({"罗汉"});

int create()
{
	string name;
	name = first_name[ID];
	name+= name_words[random(sizeof(name_words))];

	set_name(name, ({"luo han", "luohan"}));
  	set("long", "南海观音座下十八罗汉。\n");
	set("title", "十八罗汉");
        set("gender", "男性");
        set("age", 25);
        set("attitude", "peaceful");
        set("rank_info/self", "贫僧");
        set("class", "bonze");
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        set("force", 3600);
        set("max_force", 1800);
        set("force_factor", 50);
        set("max_mana", 2000);
        set("mana", 4000);
        set("mana_factor", 50);

	set("daoxing", 2000000);
	set("combat_exp", 2000000);

        set("eff_dx", 720000);
        set("nkgain", 500);

        set_skill("spells", 150);
        set_skill("buddhism", 150);
        set_skill("unarmed", 150);
        set_skill("jienan-zhi", 150);
        set_skill("dodge", 150);
        set_skill("lotusmove", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("lotusforce", 150);
        set_skill("staff", 150);
        set_skill("lunhui-zhang", 150);

        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("staff", "lunhui-zhang");
/*
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
                (: cast_spell, "jingang" :),
		(: perform_action, "staff", "diyu" :),
        }) );
*/
        create_family("南海普陀山", 2, "弟子");

        setup();
        carry_object("/d/nanhai/obj/sengpao")->wear();
        carry_object("/d/nanhai/obj/budd_staff")->wield();
        return 1;
}
