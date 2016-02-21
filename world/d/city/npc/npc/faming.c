inherit NPC;

void create()
{
        set_name("·¨Ã÷³¤ÀÏ", ({"faming zhanglao","monk", "faming","zhanglao"}));
        set("long",
                "·¨Ã÷³¤ÀÏÊÇ»¯ÉúËÂµÄÖ÷³Ö£¬ÉñÉ«×¯ÖØ£¬¾ÙÖ¹¼ä×ÔÓĞÒ»·¬ÍşÒÇ¡£
ÌıËµËûÓĞÒ»ÉíÎäÒÕ£¬Ò²ÄÜºô·ç»½Óê£¬È´²»´«ÊÚÓÚËÂÀïµÄºÍÉĞ¡£\n");
	set("title", "Ö÷³Ö");
        set("gender", "ÄĞĞÔ");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 55);
        set("per", 23);
        set("max_kee", 900);
        set("max_sen", 600);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
	set("max_mana", 500);
	set("mana", 900);
	set("mana_factor", 30);
        set("combat_exp", 200000);
  set("daoxing", 300000);

        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);


        set_skill("force", 90);
        set_skill("unarmed", 90);
        set_skill("dodge", 90);
	set_skill("jienan-zhi", 90);
        set_skill("parry", 90);
	set_skill("spells", 90);
	set_skill("buddhism", 90);
	map_skill("unarmed", "jienan-zhi");
	map_skill("spells", "buddhism");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );

        setup();
        carry_object("/d/obj/cloth/monkcloth")->wear();

        setup();
}

ÿ